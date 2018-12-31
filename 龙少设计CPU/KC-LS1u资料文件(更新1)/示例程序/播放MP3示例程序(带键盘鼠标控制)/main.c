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


    SPI_RST();    //复位SPI控制器

    TF_SD_CSH(0); //初始化设备0内存卡(初始化接"KC-LS1u_SPI_C"PCB上的"S_CS0"片选线的设备),如果初始化成功返回值不为0;
    FAT32_csh(0); //初始化设备0文件系统,如果初始化成功返回值不为0
    VS1003_CSH(); //初始化VS1003
    CH375_CSH(); //初始化CH375

/*-----------------播放MP3------------------*/

   SB_Z = 0x43;

   while(1)
   {



      if(bfkz)
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





       CH375_RUN(); //运行CH375


       if(CH375_INTT) //CH375有中断到
       {

           if(KEY_Spacebar()) //判断键盘空格键按下
           {
               if(i == 0)
               {
                  i = 1;
                  bfkz = ~bfkz; //暂停播放/继续播放
               }
           }
           else i = 0;

           if(KEY_LEFT()) //判断键盘左方向键按下
           {
               FAT32_RWWJ_SETLBA(0,0,(FAT32_RETURN_WJDX_(0,0) - FAT32_RETURN__WJDX(0,0)) / 512 - 40); //后退40个扇区
           }

           if(KEY_RIGHT()) //判断键盘右方向键按下
           {
               FAT32_RWWJ_SETLBA(0,0,(FAT32_RETURN_WJDX_(0,0) - FAT32_RETURN__WJDX(0,0)) / 512 + 40); //前进40个扇区
           }


           if(SB_KEY & 0x01) bfkz = 255; //鼠标左键按下,继续播放
           if(SB_KEY & 0x02) bfkz = 0; //鼠标右键按下,暂停播放


           j = SB_Z;
           j = (j << 8) | SB_Z;
           VS1003_WR(0x0b,j);    //鼠标滚轮值更新到VS1003音量寄存器

       }



   }


}