#include<io.h>
#include<qjbldy.h>
#include<KEY.h>
#include<CH375.h>
#include<SPI.h>
#include<VGA.h>


main()
{

unsigned char _y=119,_x=127;

    VGA_VRAM_LD(); //װ���Դ�
    VGA_SK0(0,240,255); //VGA����
    VGA_VRAM_UP(); //�����Դ�


    CH375_CSH(); //��ʼ��CH375

    while(1)
    {

        CH375_RUN(); //����CH375

        /*----------------------����Ϊ������괦��---------------------*/


        VGA_VRAM_LD(); //װ���Դ�

        VGA_SK0(0,240,255); //VGA����
        VGA_kuang0(SB_Y,SB_X,SB_Z+1,SB_Z+1,0xc9); //���ָ��λ�û���,���ֿ��ƿ��С

        if(SB_KEY) //����а�������,  SB_KEY��λ0Ϊ������,λ1����Ҽ�,λ2Ϊ����м�, λֵ����Ϊ1,�ɿ�Ϊ0
        {
            VGA_ZX(_y,_x,SB_Y,SB_X,0);
        }
        else
        {
            _y = SB_Y;  //�����SB_ZΪ������ֵ0~255,SB_YΪ������ĻY����0~239,SB_XΪ������ĻX����0~255
            _x = SB_X;
        }

        VGA_VRAM_UP(); //�����Դ�

    }

}