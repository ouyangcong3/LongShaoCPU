#include<io.h>
#include<qjbldy.h>
#include<VGA.h>
#include<string.h>
#include<printing.h>


main()
{

/*--------------填充屏幕像素0---------------*/

    VGA_VRAM_LD(); //装载显存
    VGA_SK0(0,240,255); //X坐标默认0~255,屏幕起始坐标Y为0,结束结束坐标为240,像素值为255(白色)
    VGA_VRAM_UP(); //更新显存


/*--------------填充屏幕像素1---------------*/

    VGA_VRAM_LD(); //装载显存
    VGA_SK1(128,0,2,8,0xe0); //Y起始坐标为128,X起始坐标为0,Y坐标点数为2,X坐标点数为8,像素值为0xe0(红色)
    VGA_VRAM_UP(); //更新显存

/*---------------写一个像素点---------------*/

    VGA_VRAM_LD(); //装载显存
    VRAM[0x80fc] = 0; //YX坐标分别为128和253,像素值为0(黑色)
    VGA_VRAM_UP(); //更新显存

/*----------用CPU指令写一个像素点-----------*/

    VGA_VRAM_LD(); //装载显存

    _A2 = 0x80; // RAM/IO地址高8位,写0x80(显存起始位置为0x800000)
    _A1 = 0x80; // RAM/IO地址中8位,写Y坐标128
    _A0 = 0xfb; // RAM/IO地址低8位,写X坐标252
    _NOP;       // 空操作
    _RAM = 0;   // RAM/IO写像素值0

    VGA_VRAM_UP(); //更新显存


/*-------------------画框-------------------*/

    VGA_VRAM_LD(); //装载显存
    VGA_kuang0(200,0,10,16,0x1c); //Y起始坐标为200,X起始坐标为0,Y边长为10+1像素,X边长为16+1像素,像素值为0x1c(绿色)
    VGA_VRAM_UP(); //更新显存


/*-------------------两点连线-------------------*/

    VGA_VRAM_LD(); //装载显存
    VGA_ZX(16,20,99,131,0x03); //点1坐标YX为16和20,点2坐标YX为99和131,像素值为0x03(蓝色)
    VGA_ZX(127,143,87,61,0x03); //点1坐标YX为127和143,点2坐标YX为87和61,像素值为0x03(蓝色)
    VGA_VRAM_UP(); //更新显存


/*-----------------显示ASCII码------------------*/

    VGA_VRAM_LD(); //装载显存
    print_ASCII(200,201,'X',69); //坐标YX为200和201,显示字符X,像素值为69
    VGA_VRAM_UP(); //更新显存

/*-----------------显示字符串------------------*/

    VGA_VRAM_LD(); //装载显存
    printx(180,201,"KC- LS1u",69); //坐标YX为180和201,显示字符串"KC- LS1u",像素值为69
    printx(160,201,U32_str(268435455),69); //坐标YX为1160和201,显示32位无符号数值268435455,像素值为69
    VGA_VRAM_UP(); //更新显存





    while(1);

}