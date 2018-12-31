#include<io.h>

void KC_LS1u_OFF()
{
  XT_C = 0x80;
}

main()
{

unsigned int i;

   for(i = 0;i != 65535;++i); //延时一段时间
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);

   KC_LS1u_OFF(); //关闭KC_LS1u电源

   while(1);
}