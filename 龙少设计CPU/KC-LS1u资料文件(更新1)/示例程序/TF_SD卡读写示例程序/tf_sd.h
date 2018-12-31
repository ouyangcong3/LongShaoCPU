/*  TF_SD_LBAX�����¼�豸��LBA������,ʹ�ô˺���Ҫ������������忽����"qjbldy.h"

  unsigned long int TF_SD_LBAX[8]; //��¼�豸����������

*/


/*
unsigned char TF_SD_RD_CID(unsigned char device,unsigned char *RAMaddr)  //���豸CSD,deviceѡ���豸
{

  unsigned char x,y;

  SPI_CS = device & 0x07 | 0x18; //�������ʲ�ѡ���ڴ濨

  SPI_D = 0x4a;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0xff;
  SPI_WIDLE_IDLE();

  SPI_S = 0x02; //SPI���1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //����Ӧ���־0x00����
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  while(x != 0 && SPI_D != 0xfe) //��������������ʼ��־0xfe����
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  if(x != 0)
  {
      y = 2;
      while(y != 0)
      {
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        --y;
      }
  }

  SPI_D = 0xff; //�������һ��CRC

  SPI_S = 0x01; //SPI�ر����1

  SPI_CS = 0x00; //ѡ�п��豸
  SPI_D = 0xff;

  return x;

}
*/
unsigned char TF_SD_RD_CSD(unsigned char device,unsigned char *RAMaddr)  //���豸CSD,deviceѡ���豸
{

  unsigned char x,y;

  SPI_CS = device & 0x07 | 0x18; //�������ʲ�ѡ���ڴ濨

  SPI_D = 0x49;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0xff;
  SPI_WIDLE_IDLE();

  SPI_S = 0x02; //SPI���1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //����Ӧ���־0x00����
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  while(x != 0 && SPI_D != 0xfe) //��������������ʼ��־0xfe����
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  if(x != 0)
  {
      y = 2;
      while(y != 0)
      {
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        --y;
      }
  }

  SPI_D = 0xff; //�������һ��CRC

  SPI_S = 0x01; //SPI�ر����1

  SPI_CS = 0x00; //ѡ�п��豸
  SPI_D = 0xff;

  return x;

}



unsigned char TF_SD_CSH(unsigned char device) //TF/SD����ʼ��, �����ʼ���ɹ�����ֵ��Ϊ0, deviceѡ��SPI�豸
{

unsigned int x;
unsigned char buf[16];
unsigned long int LBAX;


//////////////////��λΪSPIģʽ//////////////////     

  SPI_CS = 0x10;  //SPI��������Ϊ4��Ƶ ��ѡ�п��豸
  
  for(x = 0;x != 8;++x) SPI_D = 0xff; //����80��ʱ��


  SPI_CS = device & 0x07 | 0x18; //�������ʲ�ѡ���ڴ濨

  SPI_D = 0x40;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0x95;
  SPI_WIDLE_IDLE();

  SPI_S = 0x02; //SPI���1

  x = 16; //��16�β��ɹ�����
  while(SPI_D != 0x01 && x != 0) //����0x01�򳬳��޶�������ʱ����
  {
     SPI_WIDLE_IDLE();
     --x;
  }

  if(x != 0)
  {

///////////////////��ʼ��/////////////////////////

     x = 65535; //��ʼ��65535�β��ɹ�����

     while(SPI_D != 0x00 && x != 0)
     {

        SPI_S = 0x01; //SPI�ر����1

        SPI_CS = 0x10; //ѡ�п��豸

        SPI_D = 0xff;   //���8��ʱ��
        SPI_WIDLE_IDLE();

        SPI_CS = device & 0x07 | 0x18; //�������ʲ�ѡ���ڴ濨

        SPI_D = 0x41;
        SPI_WIDLE_IDLE();
        SPI_D = 0x00;
        SPI_WIDLE_IDLE();
        SPI_D = 0x00;
        SPI_WIDLE_IDLE();
        SPI_D = 0x00;
        SPI_WIDLE_IDLE();
        SPI_D = 0x00;
        SPI_WIDLE_IDLE();
        SPI_D = 0xff;
        SPI_WIDLE_IDLE();

        SPI_S = 0x02; //SPI���1

        SPI_D = 0xff;
        SPI_WIDLE_IDLE();
        SPI_D = 0xff;
        SPI_WIDLE_IDLE();

        --x;
     }

  }

  SPI_S = 0x01; //SPI�ر����1

  SPI_CS = 0x00; //ѡ�п��豸
  SPI_D = 0xff;



  if(TF_SD_RD_CSD(device,buf) == 0) x = 0; //��ȡCSD

  LBAX = buf[6] & 0x03; //�豸����,12λ +1�ٳ�512��ƽ������ʵ������(��λ�ֽ�)
  LBAX <<= 8;
  LBAX |= buf[7];
  LBAX <<= 2;
  LBAX |= buf[8] >> 6;

  TF_SD_LBAX[device] = (LBAX + 1) << 9; //+1��512���������



  return x;

}




unsigned char TF_SD_RD_512B(unsigned char device,unsigned long int SQH,unsigned char *RAMaddr)  //SQDZΪ������, RAMaddrΪ��������д���ڴ���׵�ַ, deviceѡ���豸
{

  unsigned char x,y;

  SQH <<= 1;

  SPI_CS = device & 0x07 | 0x18; //�������ʲ�ѡ���ڴ濨

  SPI_D = 0x51;
  SPI_WIDLE_IDLE();
  SPI_D = SQH >> 16;
  SPI_WIDLE_IDLE();
  SPI_D = SQH >> 8;
  SPI_WIDLE_IDLE();
  SPI_D = SQH;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0xff;
  SPI_WIDLE_IDLE();

  SPI_S = 0x02; //SPI���1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //����Ӧ���־0x00����
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  while(x != 0 && SPI_D != 0xfe) //��������������ʼ��־0xfe����
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  if(x != 0)
  {
      y = 64;
      while(y != 0)
      {
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        --y;
      }
  }

  SPI_D = 0xff; //�������һ��CRC

  SPI_S = 0x01; //SPI�ر����1

  SPI_CS = 0x00; //ѡ�п��豸
  SPI_D = 0xff;

  return x;

}



unsigned char TF_SD_WR_512B(unsigned char device,unsigned long int SQH,unsigned char *RAMaddr)  //SQDZΪ������, RAMaddrΪд�������ڴ���׵�ַ, deviceѡ���豸
{

  unsigned char x,y;
  unsigned int js1;

  SQH <<= 1;

  SPI_CS = device & 0x07 | 0x18; //�������ʲ�ѡ���ڴ濨

  SPI_D = 0x58;
  SPI_WIDLE_IDLE();
  SPI_D = SQH >> 16;
  SPI_WIDLE_IDLE();
  SPI_D = SQH >> 8;
  SPI_WIDLE_IDLE();
  SPI_D = SQH;
  SPI_WIDLE_IDLE();
  SPI_D = 0x00;
  SPI_WIDLE_IDLE();
  SPI_D = 0xff;
  SPI_WIDLE_IDLE();

  SPI_S = 0x02; //SPI���1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //����Ӧ���־0x00����
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  SPI_S = 0x01; //SPI�ر����1

  if(x != 0)
  {

      SPI_D = 0xfe;
      SPI_WIDLE_IDLE();

      y = 64;
      while(y != 0)
      {
        SPI_D = *RAMaddr;
        ++RAMaddr;
        SPI_D = *RAMaddr;
        ++RAMaddr;
        SPI_D = *RAMaddr;
        ++RAMaddr;
        SPI_D = *RAMaddr;
        ++RAMaddr;
        SPI_D = *RAMaddr;
        ++RAMaddr;
        SPI_D = *RAMaddr;
        ++RAMaddr;
        SPI_D = *RAMaddr;
        ++RAMaddr;
        SPI_D = *RAMaddr;
        ++RAMaddr;
        --y;
      }

      //SPI_D = 0xff; //д����CRC��Ϊ0xff
      //  SPI_WIDLE_IDLE();;
      //SPI_D = 0xff;
      //  SPI_WIDLE_IDLE();;

      SPI_S = 0x02; //SPI���1

      while(x != 0 && (SPI_D & 0x1f) != 0x05); //�յ�XXX00101д��ɹ�
      {
        SPI_WIDLE_IDLE();
        --x;
      }

      while(SPI_D != 0xff) //æ��� �������
      {
        SPI_WIDLE_IDLE();
      }

      SPI_S = 0x01; //SPI�ر����1

  }


  SPI_CS = 0x00; //ѡ�п��豸
  SPI_D = 0xff;

  return x;

}





