#include<io.h>
#include<qjbldy.h>
#include<KEY.h>
#include<CH375.h>

main()
{

char i = 0;
char buf[512];


    CH375_CSH(); //��ʼ��CH375

    while(1)
    {

        CH375_RUN(); //����CH375

        if(CH375_SBDM[0] == 1) //�ж��豸0����,Ϊ1ʱ(����USB�洢��)����
        {
            if(i == 0)
            {
               CH375_RD_LBA(0,0,1,buf); //���豸0��0��������������,��������ɹ�����ֵ��Ϊ0
               CH375_WR_LBA(0,1,1,buf); //������������д���豸0��1������,��������ɹ�����ֵ��Ϊ0

               i = 1;
            }
        }
        else i = 0;

    }

}