#include<io.h>
#include<qjbldy.h>
#include<ds1302.h>
#include<spi.h>
#include<tf_sd.h>
#include<fat32.h>
#include<VS1003.h>


main()
{

char buf[512];


    SPI_RST();    //复位SPI控制器

    TF_SD_CSH(0); //初始化设备0内存卡(初始化接"KC-LS1u_SPI_C"PCB上的"S_CS0"片选线的设备),如果初始化成功返回值不为0;
    FAT32_csh(0); //初始化设备0文件系统,如果初始化成功返回值不为0
    VS1003_CSH(); //初始化VS1003


/*-----------------播放MP3------------------*/


   while(1)
   {

       if(FAT32_RDWJ_512B(0,0,buf) == 1) //读出文件512个字节放到本机缓冲区,返回值为1表示操作成功,为2表示没有文件数据
       {

           VS1003_WR512B(buf); //本机缓冲区的数据写入VS1003缓冲区,给VS1003喂数据

       }
       else //读文件512个字节失败(可能是文件读完)
       {

           if(FAT32_OPENWJ(0,2,0,"音乐文件\音乐1.mp3") == 1); //打开 "音乐文件" 文件夹下的 "音乐1.mp3", 返回值为1表示操作成功

           else while(1); //否则可能是硬件错误

       }

   }


}