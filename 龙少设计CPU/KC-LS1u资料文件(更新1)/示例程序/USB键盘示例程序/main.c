#include<io.h>
#include<qjbldy.h>
#include<KEY.h>
#include<CH375.h>
#include<VGA.h>


main()
{

unsigned char y=0,x=0;
unsigned char k0 = 0;
unsigned char k1 = 0;
unsigned char k2 = 0;


    VGA_VRAM_LD(); //װ���Դ�
    VGA_SK0(0,240,255); //VGA����
    VGA_ASCII(y,x,'|',0x11); //д���
    VGA_VRAM_UP(); //�����Դ�


    CH375_CSH(); //��ʼ��CH375

    while(1)
    {

        CH375_RUN(); //����CH375


        /*----------------------����Ϊ���̰����жϴ���---------------------*/


        if(KEY_ift() > 0x03 && KEY_ift() < 0x1e) //����A~Z������?
        {

            if(k2 == 0)
            {

                VGA_VRAM_LD(); //װ���Դ�

                VGA_SK1(y,x,12,6,255); //�������

                VGA_ASCII(y,x,KEY_ift()-4 + ((KEY_LED & 0x02) ? 'A' : 'a'),0x11); //��Ŀ������жϼ���LEDֵ,Caps LockΪ1ʱ��д

                x+=6; //x����ǰ��1���ַ�
                if(x > 250) x = 0, y += 12; //x���곬����Χ�ع�0,y����ǰ��1��
                if(y > 228) //y���곬����Χ�ع�0,������
                {
                    y = 0;
                    VGA_SK0(0,240,255); //VGA����
                }

                VGA_ASCII(y,x,'|',0x11); //д���

                VGA_VRAM_UP(); //�����Դ�

                k2 = 1;

            }

        }
        else k2 = 0;




        if(KEY_Return()) //�س������»���
        {

            VGA_VRAM_LD(); //װ���Դ�

            VGA_SK1(y,x,12,6,255); //�������

            if(k0 == 0) //��������
            {
               k0 = 1;
               y += 12;
               x = 0;

                if(y > 228) //y���곬����Χ�ع�0,������
                {
                    y = 0;
                    VGA_SK0(0,240,255); //VGA����
                }
            }

            VGA_ASCII(y,x,'|',0x11); //д���

            VGA_VRAM_UP(); //�����Դ�

        }
        else k0 = 0;




        if(KEY_Spacebar()) //�ո������ǰ��1���ַ�
        {

            VGA_VRAM_LD(); //װ���Դ�

            VGA_SK1(y,x,12,6,255); //�������

            if(k1 == 0) //��������
            {

                k1 = 1;

                x+=6; //x����ǰ��1���ַ�
                if(x > 250) x = 0, y += 12; //x���곬����Χ�ع�0,y����ǰ��1��
                if(y > 228) //y���곬����Χ�ع�0,������
                {
                    y = 0;
                    VGA_SK0(0,240,255); //VGA����
                }

            }

            VGA_ASCII(y,x,'|',0x11); //д���

            VGA_VRAM_UP(); //�����Դ�

        }
        else k1 = 0;



       
    }


}