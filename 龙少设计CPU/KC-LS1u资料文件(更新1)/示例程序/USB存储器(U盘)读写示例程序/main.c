#include<io.h>
#include<qjbldy.h>
#include<KEY.h>
#include<CH375.h>

main()
{

char i = 0;
char buf[512];


    CH375_CSH(); //初始化CH375

    while(1)
    {

        CH375_RUN(); //运行CH375

        if(CH375_SBDM[0] == 1) //判断设备0代码,为1时(挂有USB存储器)进入
        {
            if(i == 0)
            {
               CH375_RD_LBA(0,0,1,buf); //读设备0的0号扇区到缓冲区,如果操作成功返回值不为0
               CH375_WR_LBA(0,1,1,buf); //缓冲区的数据写入设备0的1号扇区,如果操作成功返回值不为0

               i = 1;
            }
        }
        else i = 0;

    }

}