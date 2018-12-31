#include<io.h>
#include<qjbldy.h>
#include<ds1302.h>
#include<spi.h>
#include<tf_sd.h>
#include<fat32.h>
#include<VS1003.h>
#include<KEY.h>
#include<CH375.h>

main()
{

char buf[512];
unsigned char bfkz = 0;
unsigned char i = 0;
unsigned int j;


    SPI_RST();    //��λSPI������

    TF_SD_CSH(0); //��ʼ���豸0�ڴ濨(��ʼ����"KC-LS1u_SPI_C"PCB�ϵ�"S_CS0"Ƭѡ�ߵ��豸),�����ʼ���ɹ�����ֵ��Ϊ0;
    FAT32_csh(0); //��ʼ���豸0�ļ�ϵͳ,�����ʼ���ɹ�����ֵ��Ϊ0
    VS1003_CSH(); //��ʼ��VS1003
    CH375_CSH(); //��ʼ��CH375

/*-----------------����MP3------------------*/

   SB_Z = 0x43;

   while(1)
   {



      if(bfkz)
      {

          if(FAT32_RDWJ_512B(0,0,buf) == 1) //�����ļ�512���ֽڷŵ�����������,����ֵΪ1��ʾ�����ɹ�,Ϊ2��ʾû���ļ�����
          {

              VS1003_WR512B(buf); //����������������д��VS1003������,��VS1003ι����

          }
          else //���ļ�512���ֽ�ʧ��(�������ļ�����)
          {

              if(FAT32_OPENWJ(0,2,0,"�����ļ�\����1.mp3") == 1); //�� "�����ļ�" �ļ����µ� "����1.mp3", ����ֵΪ1��ʾ�����ɹ�

              else while(1); //���������Ӳ������

          }

       }





       CH375_RUN(); //����CH375


       if(CH375_INTT) //CH375���жϵ�
       {

           if(KEY_Spacebar()) //�жϼ��̿ո������
           {
               if(i == 0)
               {
                  i = 1;
                  bfkz = ~bfkz; //��ͣ����/��������
               }
           }
           else i = 0;

           if(KEY_LEFT()) //�жϼ������������
           {
               FAT32_RWWJ_SETLBA(0,0,(FAT32_RETURN_WJDX_(0,0) - FAT32_RETURN__WJDX(0,0)) / 512 - 40); //����40������
           }

           if(KEY_RIGHT()) //�жϼ����ҷ��������
           {
               FAT32_RWWJ_SETLBA(0,0,(FAT32_RETURN_WJDX_(0,0) - FAT32_RETURN__WJDX(0,0)) / 512 + 40); //ǰ��40������
           }


           if(SB_KEY & 0x01) bfkz = 255; //����������,��������
           if(SB_KEY & 0x02) bfkz = 0; //����Ҽ�����,��ͣ����


           j = SB_Z;
           j = (j << 8) | SB_Z;
           VS1003_WR(0x0b,j);    //������ֵ���µ�VS1003�����Ĵ���

       }



   }


}