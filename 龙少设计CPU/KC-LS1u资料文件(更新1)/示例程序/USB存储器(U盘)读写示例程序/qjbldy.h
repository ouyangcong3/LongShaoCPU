
/*------------------------------------------------  CH375ȫ�ֱ���  ----------------------------------------------------*/

unsigned char CH375_DATAbuf[64]; //CH375����������

unsigned char CH375_device_bz[4] = {0,0,0,0}; //�豸���ڱ�־,����豸����,��־Ϊ1,����Ϊ0

unsigned char CH375_ICBBH[4]; //CH375оƬ�汾��

unsigned char CH375_BJ[4]; //�豸��ʼ�������¼ 0Ϊ��ʼ�����

unsigned char CH375_ZXSD[4] = {0,0,0,0}; //USB�����ٶ�

unsigned char CH375_INK[4] = {0,0,0,0}; //�����жϴ��� IN��ѯ�����رտ��� 1Ϊ���� 0 Ϊ�ر�

unsigned char CH375_INDX[4]; //�����жϴ��� DATA0��DATA1������

unsigned char CH375_SBDM[4] = {0,0,0,0}; //CH375�豸���� 0:���豸 1:�洢�� 2:���� 3:��� 255:δʶ����豸

unsigned long int CH375_LBAX[4]; //USB�洢��������-1,+1�ٳ�512����ʵ������(��λ�ֽ�)

unsigned char CH375_QJ[4]; //CH375�����ж��¼�����

unsigned char CH375_SBIOBZ = 0; //CH375�豸�β��־ 1:�豸���� 2:�豸�γ� 0:��״̬

unsigned char CH375_CT2_; //��¼Ӳ����������16λ�ĵ�8λ����,���ں����µļ��������ݱȽ�

unsigned char CH375_INTT = 0; //CH375���ж�ʱ��1

////////////////////�����������/////////////////////

unsigned char KEY_LED = 0x01; //���̵�����
unsigned char KEY_DATA[8] = {0,0,0,0,0,0,0,0}; //���̼�ֵ

unsigned char SB_KEY; //��갴������
unsigned char SB_X = 127; //���X��������
unsigned char SB_Y = 119; //���Y��������
unsigned char SB_Z = 0; //����������