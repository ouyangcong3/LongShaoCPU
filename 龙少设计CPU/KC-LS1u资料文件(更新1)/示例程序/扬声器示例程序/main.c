#include<io.h>

void speaker(unsigned int sj,unsigned int pl) //������,sjΪ����ʱ��,plΪƵ��
{

unsigned int x;

   while(--sj != 0)
   {

      XT_C |= 0x20;
      for(x = 0;x != pl;++x);
      XT_C &= 0xdf;
      for(x = 0;x != pl;++x);

   }

}


main()
{

/* �������� "KC_LS1u_CLK_RST_IO_PS" PCB ��"Speaker"�ӿ�*/

     speaker(110,70);
     speaker(110,75);
     speaker(110,80);
     speaker(110,85);
     speaker(110,90);
     speaker(110,95);
     speaker(110,100);
     speaker(110,105);
     speaker(110,110);
     speaker(110,115);
     speaker(110,120);
     speaker(110,125);
     speaker(110,130);


   while(1);
}