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


    VGA_VRAM_LD(); //装载显存
    VGA_SK0(0,240,255); //VGA清屏
    VGA_ASCII(y,x,'|',0x11); //写光标
    VGA_VRAM_UP(); //更新显存


    CH375_CSH(); //初始化CH375

    while(1)
    {

        CH375_RUN(); //运行CH375


        /*----------------------下面为键盘按键判断处理---------------------*/


        if(KEY_ift() > 0x03 && KEY_ift() < 0x1e) //键盘A~Z键按下?
        {

            if(k2 == 0)
            {

                VGA_VRAM_LD(); //装载显存

                VGA_SK1(y,x,12,6,255); //擦除光标

                VGA_ASCII(y,x,KEY_ift()-4 + ((KEY_LED & 0x02) ? 'A' : 'a'),0x11); //三目运算符判断键盘LED值,Caps Lock为1时大写

                x+=6; //x坐标前进1个字符
                if(x > 250) x = 0, y += 12; //x坐标超出范围回归0,y坐标前进1行
                if(y > 228) //y坐标超出范围回归0,并清屏
                {
                    y = 0;
                    VGA_SK0(0,240,255); //VGA清屏
                }

                VGA_ASCII(y,x,'|',0x11); //写光标

                VGA_VRAM_UP(); //更新显存

                k2 = 1;

            }

        }
        else k2 = 0;




        if(KEY_Return()) //回车键按下换行
        {

            VGA_VRAM_LD(); //装载显存

            VGA_SK1(y,x,12,6,255); //擦除光标

            if(k0 == 0) //更新坐标
            {
               k0 = 1;
               y += 12;
               x = 0;

                if(y > 228) //y坐标超出范围回归0,并清屏
                {
                    y = 0;
                    VGA_SK0(0,240,255); //VGA清屏
                }
            }

            VGA_ASCII(y,x,'|',0x11); //写光标

            VGA_VRAM_UP(); //更新显存

        }
        else k0 = 0;




        if(KEY_Spacebar()) //空格键按下前进1个字符
        {

            VGA_VRAM_LD(); //装载显存

            VGA_SK1(y,x,12,6,255); //擦除光标

            if(k1 == 0) //更新坐标
            {

                k1 = 1;

                x+=6; //x坐标前进1个字符
                if(x > 250) x = 0, y += 12; //x坐标超出范围回归0,y坐标前进1行
                if(y > 228) //y坐标超出范围回归0,并清屏
                {
                    y = 0;
                    VGA_SK0(0,240,255); //VGA清屏
                }

            }

            VGA_ASCII(y,x,'|',0x11); //写光标

            VGA_VRAM_UP(); //更新显存

        }
        else k1 = 0;



       
    }


}