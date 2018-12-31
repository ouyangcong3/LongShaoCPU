


/*----------------------------------------------- TF_SD卡全局变量 ---------------------------------------------------*/

unsigned long int TF_SD_LBAX[2];


/*--------------------------------------------- FAT32文件系统全局变量 -----------------------------------------------*/

unsigned char FAT32_cudx[6];  //每簇扇区数               数组大小对应设备数量
unsigned long int FAT32_cudx_B[6];  //每簇字节数
unsigned char FAT32_FATsl[6]; //FAT表数量
unsigned int FAT32_FATDX[6]; //FAT表大小,单位扇区数
unsigned int FAT32_FAT1addr[6];  //FAT1表起始扇区号
unsigned long int FAT32_FAT2addr[6]; //FAT2表起始扇区号
unsigned long int FAT32_DATAaddr[6];  //数据区起始扇区号
unsigned long int FAT32__cuhao[6];  //存储器最后一个簇号
unsigned int FAT32__cuhao_LBAPY[6];  //存储器最后一个簇号在扇区内的偏移



#define FAT32_RWWJ_WJX 5  //可操作文件个数
#define FAT32_RWWJ_CLX 16  //簇链长度

unsigned char FAT32_RWWJ_bz[30];  //读写文件操作的时候,用来标志文件是否打开,为1打开,为0关闭, 6个设备就是6, 然后定义每个设备最多可以同时操作5个文件,6*5=30
unsigned long int FAT32_RWWJ_culian[480];  //读写文件操作的时候,用来保存簇链, 这里定义一个设备的簇链最多保存16个簇号, 6个设备就是96, 然后定义每个设备最多可以同时操作5个文件,96*5=480
unsigned char FAT32_RWWJ_culianX[30];  //读写文件操作的时候,用来保存簇链指针,指向下个簇号, 6个设备就是6, 然后定义每个设备最多可以同时操作5个文件,6*5=30
unsigned long int FAT32_RWWJ_sqh_[30];  //读写文件操作的时候,用来保存当前簇读取扇区的扇区号, 6个设备就是6, 然后定义每个设备最多可以同时操作5个文件,6*5=30
unsigned long int FAT32_RWWJ__sqh[30];  //读写文件操作的时候,用来保存当前簇最后一个扇区号+1, 6个设备就是6, 然后定义每个设备最多可以同时操作5个文件,6*5=30
unsigned long int FAT32_RWWJ_cuhao[30];  //读写文件操作的时候,用来保存文件首簇号, 6个设备就是6, 然后定义每个设备最多可以同时操作5个文件,6*5=30
unsigned long int FAT32_RWWJ__wjdx[30];  //读写文件操作的时候,用来保存文件剩余未读字节数, 6个设备就是6, 然后定义每个设备最多可以同时操作5个文件,6*5=30
unsigned long int FAT32_RWWJ_wjdx_[30];  //读写文件操作的时候,用来保存文件总字节数, 6个设备就是6, 然后定义每个设备最多可以同时操作5个文件,6*5=30



unsigned long int FAT32_SETUP_culian_sqh_[6]; //记录首簇号所在扇区号          数组大小对应设备数量
unsigned long int FAT32_SETUP_culian__sqh_[6]; //记录待指簇号所在扇区号
unsigned long int FAT32_SETUP_culian__sqh[6]; //记录扫描扇区号
unsigned long int FAT32_SETUP_culian_cuhao_js1[6]; //记录已创建簇号数量
unsigned int FAT32_SETUP_culian_py1[6]; //记录待指簇号在扇区内的偏移
unsigned long int FAT32_SETUP_culian_FAT_[6]; //记录FAT表首扇区号
unsigned long int FAT32_SETUP_culian__FAT[6]; //记录FAT表尾扇区号+1
unsigned long int FAT32_SETUP_culian_CLX[6]; //记录须创建簇数量
unsigned long int FAT32_DELETE_culian_FAT_[6]; //记录FAT表首扇区号
unsigned long int FAT32_DELETE_culian__cuhao[6]; //记录簇号指向的下个簇号
unsigned char FAT32_SETUP_DELETE_fatx; //记录fat表选择



#define FAT32_DELETE_E5_32B_CLX 8  //簇链长度
#define FAT32_DELETE_E5_CLX 8  //簇链长度

unsigned long int FAT32_DELETE_E5_32B_culian[8]; //记录处理32B空位的簇链
unsigned char FAT32_DELETE_E5_32B_culianX; //记录32B空位的簇链的指针
unsigned long int FAT32_DELETE_E5_32B_sqh_; //记录32B空位所在扇区号
unsigned long int FAT32_DELETE_E5_32B__sqh; //记录32B空位所在簇的尾扇区号+1
unsigned int FAT32_DELETE_E5_32B_smzz; //32B空位所在扇区内的偏移
unsigned long int FAT32_DELETE_E5_WJFDX; //记录目录里的文件符总大小,单位字节

unsigned char FAT32_DELETE_E5_qhc; //切换控制, =0扫首E5,=1正式处理

unsigned long int FAT32_DELETE_E5_culian[8]; //记录主扫描的簇链
unsigned char FAT32_DELETE_E5_culianX; //记录主扫描的簇链的指针
unsigned long int FAT32_DELETE_E5_sqh_; //记录主扫描所在扇区号
unsigned long int FAT32_DELETE_E5__sqh; //记录主扫描所在簇的尾扇区号+1
unsigned int FAT32_DELETE_E5_smzz; //主扫描所在扇区内的偏移


unsigned long int FAT32_VOID_cuhao_FAT_; //记录FAT表首扇区号
unsigned long int FAT32_VOID_cuhao__FAT; //记录FAT表尾扇区号+1
unsigned long int FAT32_VOID_cuhao_sqh; //记录当前扫描扇区(物理地址)
unsigned long int FAT32_VOID_cuhao_cuhao; //记录找到的空簇的簇号


unsigned long int FAT32_UP_culian_cuhao_; //记录当前扫描的首簇号
unsigned long int FAT32_UP_culian_DATADX; //记录目标数据大小,单位字节
unsigned char FAT32_UP_culian_LBA_VOID_K; //记录新扇区清空控制,为1清空新扇区,为0不清空新扇区
unsigned long int FAT32_UP_culian_DATADX_; //记录已扫数据大小,单位字节
unsigned char FAT32_UP_culian_XZ; //记录操作程序选择

#define FAT32_UP_culian_LBA_VOID_CLX 8  //创建簇链,如果要清空新扇区,这里定义每次读取的簇链长度

unsigned long int FAT32_UP_culian__cuhao; //创建簇链或删除簇链的首簇号
unsigned char FAT32_UP_culian_DELETE_culian_K; //删除簇链控制,为0正常删除簇链,为1标志为存储空间不够,删除簇链
//unsigned long int FAT32_UP_culian__CLX; //创建簇链,记录长度
unsigned char FAT32_UP_culian__cuhao_bz; //记录创建簇链的首簇号标志,为0x00表示簇号指向的是0x00000000,为0xff表示指向是0x0fffffff
unsigned long int FAT32_UP_culian_LBA_VOID_culian[8];  //创建簇链,如果要清空新扇区,这里记录每次读取的簇链
unsigned char FAT32_UP_culian_LBA_VOID_culiaX;  //创建簇链,如果要清空新扇区,这里记录簇链的指针
unsigned long int FAT32_UP_culian_LBA_VOID_sqh_; //创建簇链,如果要清空新扇区,记录簇的首扇区号
unsigned long int FAT32_UP_culian_LBA_VOID__sqh; //创建簇链,如果要清空新扇区,记录簇的尾扇区号+1


#define FAT32_ML_SETUP_WJF_CLX 8  //目录创建文件符,拷贝文件符,每次读取的簇链长度

unsigned long int FAT32_ML_SETUP_WJF_mulu_cuhao; //目录创建文件符,目录首簇号
unsigned char FAT32_ML_SETUP_WJF_WJF[1024]; //目录创建文件符,记录文件符
unsigned long int FAT32_ML_SETUP_WJF_WJFDX; //目录创建文件符,记录新文件符大小,单位字节
unsigned char FAT32_ML_SETUP_WJF_XZ; //目录创建文件符,记录操作程序选择
unsigned long int FAT32_ML_SETUP_WJF_culian[8];  //目录创建文件符,拷贝文件符,记录每次读取的簇链
unsigned char FAT32_ML_SETUP_WJF_culiaX;  //目录创建文件符,拷贝文件符,记录簇链的指针
unsigned long int FAT32_ML_SETUP_WJF_sqh_; //目录创建文件符,拷贝文件符,记录簇的首扇区号
unsigned long int FAT32_ML_SETUP_WJF__sqh; //目录创建文件符,拷贝文件符,记录簇的尾扇区号+1
unsigned int FAT32_ML_SETUP_WJF_WJFX; //目录创建文件符,拷贝文件符,文件符指针


unsigned long int FAT32_ML_SETUP_WJ_mulu_cuhao; //目录创建文件,记录目录的首簇号
unsigned long int FAT32_ML_SETUP_WJ_WJDX; //目录创建文件,记录创建文件的大小,单位字节
unsigned char FAT32_ML_SETUP_WJ_WJFDATA_32B[32]; //目录创建文件,记录32个字节的文件符数据
unsigned int FAT32_ML_SETUP_WJ_CWJM[404]; //目录创建文件,记录长文件名
unsigned char FAT32_ML_SETUP_WJ_LBA_VOID_K; //目录创建文件,选择是否清空新扇区,如果为1将清0新簇映射的扇区,为0不清0
unsigned char FAT32_ML_SETUP_WJ_XZ; //目录创建文件,记录操作程序选择


unsigned long int FAT32_ML_DELETE_WJ_cuhao; //目录删除文件,记录文件首簇号
unsigned char FAT32_ML_DELETE_WJ_XZ; //目录删除文件,记录操作程序选择


unsigned long int FAT32_ML_XGWJM_mulu_cuhao; //目录修改文件名,记录目录首簇号
unsigned char FAT32_ML_XGWJM_S_WJFDATA_32B[32]; //目录修改文件名,记录原文件符的32个字节的文件符数据
unsigned int FAT32_ML_XGWJM_S_CWJM[404]; //目录修改文件名,记录原文件符的长文件名
unsigned char FAT32_ML_XGWJM_D_WJFDATA_32B[32]; //目录修改文件名,记录新文件符的32个字节的文件符数据
unsigned int FAT32_ML_XGWJM_D_CWJM[404]; //目录修改文件名,记录新文件符的长文件名
unsigned char FAT32_ML_XGWJM_XZ; //目录修改文件名,记录操作程序选择




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


