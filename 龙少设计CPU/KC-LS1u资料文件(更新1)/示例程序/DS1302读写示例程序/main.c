#include<io.h>
#include<ds1302.h>


main()
{

   char i;

   DS1302_WR(0,0x16); //0x16д��DS1302��0��ַ�Ĵ���

   i = DS1302_RD(0);  //����DS1302��0��ַ�Ĵ������ݵ�i

   while(1);

}