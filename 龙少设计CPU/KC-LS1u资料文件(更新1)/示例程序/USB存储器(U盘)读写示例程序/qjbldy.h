
/*------------------------------------------------  CH375全局变量  ----------------------------------------------------*/

unsigned char CH375_DATAbuf[64]; //CH375本机缓冲区

unsigned char CH375_device_bz[4] = {0,0,0,0}; //设备存在标志,如果设备存在,标志为1,否则为0

unsigned char CH375_ICBBH[4]; //CH375芯片版本号

unsigned char CH375_BJ[4]; //设备初始化步骤记录 0为初始化完成

unsigned char CH375_ZXSD[4] = {0,0,0,0}; //USB总线速度

unsigned char CH375_INK[4] = {0,0,0,0}; //外设中断传输 IN查询开启关闭控制 1为开启 0 为关闭

unsigned char CH375_INDX[4]; //外设中断传输 DATA0和DATA1包控制

unsigned char CH375_SBDM[4] = {0,0,0,0}; //CH375设备代码 0:无设备 1:存储器 2:键盘 3:鼠标 255:未识别的设备

unsigned long int CH375_LBAX[4]; //USB存储器扇区数-1,+1再乘512就是实际容量(单位字节)

unsigned char CH375_QJ[4]; //CH375其他中断事件计数

unsigned char CH375_SBIOBZ = 0; //CH375设备拔插标志 1:设备插入 2:设备拔出 0:空状态

unsigned char CH375_CT2_; //记录硬件计数器高16位的低8位数据,用于和最新的计数器数据比较

unsigned char CH375_INTT = 0; //CH375有中断时置1

////////////////////键盘鼠标数据/////////////////////

unsigned char KEY_LED = 0x01; //键盘灯数据
unsigned char KEY_DATA[8] = {0,0,0,0,0,0,0,0}; //键盘键值

unsigned char SB_KEY; //鼠标按键数据
unsigned char SB_X = 127; //鼠标X坐标数据
unsigned char SB_Y = 119; //鼠标Y坐标数据
unsigned char SB_Z = 0; //鼠标滚轮数据