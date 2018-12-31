/*  TF_SD_LBAX数组记录设备的LBA扇区数,使用此函数要把这个变量定义拷贝到"qjbldy.h"

  unsigned long int TF_SD_LBAX[8]; //记录设备的总扇区数

*/


/*
unsigned char TF_SD_RD_CID(unsigned char device,unsigned char *RAMaddr)  //读设备CSD,device选择设备
{

  unsigned char x,y;

  SPI_CS = device & 0x07 | 0x18; //设置速率并选中内存卡

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

  SPI_S = 0x02; //SPI输出1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //读到应答标志0x00跳出
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  while(x != 0 && SPI_D != 0xfe) //读到扇区数据起始标志0xfe跳出
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

  SPI_D = 0xff; //接收最后一个CRC

  SPI_S = 0x01; //SPI关闭输出1

  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;

  return x;

}
*/
unsigned char TF_SD_RD_CSD(unsigned char device,unsigned char *RAMaddr)  //读设备CSD,device选择设备
{

  unsigned char x,y;

  SPI_CS = device & 0x07 | 0x18; //设置速率并选中内存卡

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

  SPI_S = 0x02; //SPI输出1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //读到应答标志0x00跳出
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  while(x != 0 && SPI_D != 0xfe) //读到扇区数据起始标志0xfe跳出
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

  SPI_D = 0xff; //接收最后一个CRC

  SPI_S = 0x01; //SPI关闭输出1

  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;

  return x;

}



unsigned char TF_SD_CSH(unsigned char device) //TF/SD卡初始化, 如果初始化成功返回值不为0, device选择SPI设备
{

unsigned int x;
unsigned char buf[16];
unsigned long int LBAX;


//////////////////复位为SPI模式//////////////////     

  SPI_CS = 0x10;  //SPI速率设置为4分频 并选中空设备
  
  for(x = 0;x != 8;++x) SPI_D = 0xff; //发送80个时钟


  SPI_CS = device & 0x07 | 0x18; //设置速率并选中内存卡

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

  SPI_S = 0x02; //SPI输出1

  x = 16; //读16次不成功跳出
  while(SPI_D != 0x01 && x != 0) //读到0x01或超出限定读次数时跳出
  {
     SPI_WIDLE_IDLE();
     --x;
  }

  if(x != 0)
  {

///////////////////初始化/////////////////////////

     x = 65535; //初始化65535次不成功跳出

     while(SPI_D != 0x00 && x != 0)
     {

        SPI_S = 0x01; //SPI关闭输出1

        SPI_CS = 0x10; //选中空设备

        SPI_D = 0xff;   //填充8个时钟
        SPI_WIDLE_IDLE();

        SPI_CS = device & 0x07 | 0x18; //设置速率并选中内存卡

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

        SPI_S = 0x02; //SPI输出1

        SPI_D = 0xff;
        SPI_WIDLE_IDLE();
        SPI_D = 0xff;
        SPI_WIDLE_IDLE();

        --x;
     }

  }

  SPI_S = 0x01; //SPI关闭输出1

  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;



  if(TF_SD_RD_CSD(device,buf) == 0) x = 0; //读取CSD

  LBAX = buf[6] & 0x03; //设备容量,12位 +1再乘512的平方就是实际容量(单位字节)
  LBAX <<= 8;
  LBAX |= buf[7];
  LBAX <<= 2;
  LBAX |= buf[8] >> 6;

  TF_SD_LBAX[device] = (LBAX + 1) << 9; //+1乘512算出扇区数



  return x;

}




unsigned char TF_SD_RD_512B(unsigned char device,unsigned long int SQH,unsigned char *RAMaddr)  //SQDZ为扇区号, RAMaddr为读出数据写入内存的首地址, device选择设备
{

  unsigned char x,y;

  SQH <<= 1;

  SPI_CS = device & 0x07 | 0x18; //设置速率并选中内存卡

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

  SPI_S = 0x02; //SPI输出1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //读到应答标志0x00跳出
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  while(x != 0 && SPI_D != 0xfe) //读到扇区数据起始标志0xfe跳出
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

  SPI_D = 0xff; //接收最后一个CRC

  SPI_S = 0x01; //SPI关闭输出1

  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;

  return x;

}



unsigned char TF_SD_WR_512B(unsigned char device,unsigned long int SQH,unsigned char *RAMaddr)  //SQDZ为扇区号, RAMaddr为写入数据内存的首地址, device选择设备
{

  unsigned char x,y;
  unsigned int js1;

  SQH <<= 1;

  SPI_CS = device & 0x07 | 0x18; //设置速率并选中内存卡

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

  SPI_S = 0x02; //SPI输出1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //读到应答标志0x00跳出
  {
    SPI_WIDLE_IDLE();
    --x;
  }

  SPI_S = 0x01; //SPI关闭输出1

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

      //SPI_D = 0xff; //写两个CRC都为0xff
      //  SPI_WIDLE_IDLE();;
      //SPI_D = 0xff;
      //  SPI_WIDLE_IDLE();;

      SPI_S = 0x02; //SPI输出1

      while(x != 0 && (SPI_D & 0x1f) != 0x05); //收到XXX00101写入成功
      {
        SPI_WIDLE_IDLE();
        --x;
      }

      while(SPI_D != 0xff) //忙检测 完毕跳出
      {
        SPI_WIDLE_IDLE();
      }

      SPI_S = 0x01; //SPI关闭输出1

  }


  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;

  return x;

}





