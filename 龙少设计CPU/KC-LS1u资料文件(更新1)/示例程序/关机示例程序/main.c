#include<io.h>

void KC_LS1u_OFF()
{
  XT_C = 0x80;
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

   KC_LS1u_OFF(); //�ر�KC_LS1u��Դ

   while(1);
}