#include<io.h>
#include<qjbldy.h>
#include<KEY.h>
#include<CH375.h>
#include<SPI.h>
#include<VGA.h>


main()
{

unsigned char _y=119,_x=127;

    VGA_VRAM_LD(); //装载显存
    VGA_SK0(0,240,255); //VGA清屏
    VGA_VRAM_UP(); //更新显存


    CH375_CSH(); //初始化CH375

    while(1)
    {

        CH375_RUN(); //运行CH375

        /*----------------------下面为鼠标坐标处理---------------------*/


        VGA_VRAM_LD(); //装载显存

        VGA_SK0(0,240,255); //VGA清屏
        VGA_kuang0(SB_Y,SB_X,SB_Z+1,SB_Z+1,0xc9); //鼠标指针位置画框,滚轮控制框大小

        if(SB_KEY) //鼠标有按键按下,  SB_KEY的位0为鼠标左键,位1鼠标右键,位2为鼠标中键, 位值按下为1,松开为0
        {
            VGA_ZX(_y,_x,SB_Y,SB_X,0);
        }
        else
        {
            _y = SB_Y;  //这里的SB_Z为鼠标滚轮值0~255,SB_Y为鼠标的屏幕Y坐标0~239,SB_X为鼠标的屏幕X坐标0~255
            _x = SB_X;
        }

        VGA_VRAM_UP(); //更新显存

    }

}