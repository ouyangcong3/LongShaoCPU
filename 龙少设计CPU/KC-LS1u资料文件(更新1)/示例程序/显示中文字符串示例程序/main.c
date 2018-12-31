#include<io.h>
#include<qjbldy.h>
#include<ds1302.h>
#include<spi.h>
#include<tf_sd.h>
#include<fat32.h>
#include<VGA.h>
//#include<string.h>
#include<printing.h>
#include<add_sys.h>


main()
{

    VGA_VRAM_LD(); //装载显存
    VGA_SK0(0,240,255); //清屏
    VGA_VRAM_UP(); //更新显存

    SPI_RST(); //复位SPI控制器


    TF_SD_CSH(0); //初始化设备0内存卡(初始化接"KC-LS1u_SPI_C"PCB上的"S_CS0"片选线的设备),如果初始化成功返回值不为0;
    FAT32_csh(0); //初始化设备0文件系统,如果初始化成功返回值不为0

    ADD_SYS(); //加载系统文件,返回值为1完成


/*-----------------显示字符串------------------*/

    VGA_VRAM_LD(); //装载显存

    printx(128,16,"我是神之觉醒(龙少)",69); //坐标YX为128和16,"我是神之觉醒(龙少)",像素值为69

    printx(115,16,"74门电路8位计算机KC-LS1u",0xe0); //坐标YX为115和16,"74门电路8位计算机KC-LS1u",像素值为0xe0

    VGA_VRAM_UP(); //更新显存


    while(1);

}