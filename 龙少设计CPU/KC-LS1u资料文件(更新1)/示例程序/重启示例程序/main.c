#include<io.h>

void KC_LS1u_RST()
{
  XT_C |= 0x40;
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

   KC_LS1u_RST(); //复位KC_LS1u

   while(1);
}