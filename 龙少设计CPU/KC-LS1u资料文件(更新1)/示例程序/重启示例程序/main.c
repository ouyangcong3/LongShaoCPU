#include<io.h>

void KC_LS1u_RST()
{
  XT_C |= 0x40;
}

main()
{

unsigned int i;

   for(i = 0;i != 65535;++i); //��ʱһ��ʱ��
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);
   for(i = 0;i != 65535;++i);

   KC_LS1u_RST(); //��λKC_LS1u

   while(1);
}