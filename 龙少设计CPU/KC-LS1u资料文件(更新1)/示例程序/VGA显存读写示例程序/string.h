/*----使用此函数要把下面的变量定义拷贝到"qjbldy.h"-----
unsigned char U32_str_buf[11];
*/


char *strcat(char *target,char *source)
{
   char *original;

   original=target;
   while(*target) ++target; // Find the end of the string 
   while(*(target++)=*(source++));
   return(original);
}

int strlen(char *str)
{
   int i=0;
   while(*(str++)) ++i;
   return i;
}

/*
int strspn(char *s1 ,char *s2)
{
    char *s;
    char *p;
    s = s1;

    while (*s1)
    {
       for (p = s2; *p; ++p)
       {
         if (*s1 == *p)
            break;
       }
       if (*p == 0)
         break;
       s1++;
    }
    return s1 - s;
}
*/


unsigned char *U32_str(unsigned long int data) //无符号32位数转ASCII字符串
{

unsigned char *str;
unsigned char i;
unsigned char k = 0;
unsigned long int DIVZ = 1000000000;

 str = U32_str_buf;
 goto in;

  do
  {
     data %= DIVZ;
     DIVZ /= 10;
 in:
     i = data / DIVZ;
     if(k != 0 || i != 0 || DIVZ == 1) *str = '0'+i,++str,k = 1;

  }while(DIVZ != 1);

  *str = 0;
  return U32_str_buf;

}