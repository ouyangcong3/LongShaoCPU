#include<io.h>
#include<ds1302.h>


main()
{

   char i;

   DS1302_WR(0,0x16); //0x16写入DS1302的0地址寄存器

   i = DS1302_RD(0);  //读出DS1302的0地址寄存器数据到i

   while(1);

}