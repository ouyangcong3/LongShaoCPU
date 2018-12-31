#include<io.h>
#include<qjbldy.h>
#include<spi.h>
#include<TF_SD.h>

main()
{

char buf[512];


    SPI_RST(); //复位SPI控制器

    TF_SD_CSH(0); //初始化设备0内存卡,如果初始化成功返回值不为0;



/*----------------读写内存卡扇区---------------*/


    TF_SD_RD_512B(0,0,buf); //读设备0内存卡的0号扇区到缓冲区,如果读取成功,返回值不为0

    TF_SD_WR_512B(0,1,buf); //缓冲区buf的数据写入设备0内存卡的1号扇区,如果写入成功,返回值不为0


    while(1);

}