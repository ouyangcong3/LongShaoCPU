


/*----------------------------------------------- TF_SD��ȫ�ֱ��� ---------------------------------------------------*/

unsigned long int TF_SD_LBAX[2];


/*--------------------------------------------- FAT32�ļ�ϵͳȫ�ֱ��� -----------------------------------------------*/

unsigned char FAT32_cudx[6];  //ÿ��������               �����С��Ӧ�豸����
unsigned long int FAT32_cudx_B[6];  //ÿ���ֽ���
unsigned char FAT32_FATsl[6]; //FAT������
unsigned int FAT32_FATDX[6]; //FAT���С,��λ������
unsigned int FAT32_FAT1addr[6];  //FAT1����ʼ������
unsigned long int FAT32_FAT2addr[6]; //FAT2����ʼ������
unsigned long int FAT32_DATAaddr[6];  //��������ʼ������
unsigned long int FAT32__cuhao[6];  //�洢�����һ���غ�
unsigned int FAT32__cuhao_LBAPY[6];  //�洢�����һ���غ��������ڵ�ƫ��



#define FAT32_RWWJ_WJX 5  //�ɲ����ļ�����
#define FAT32_RWWJ_CLX 16  //��������

unsigned char FAT32_RWWJ_bz[30];  //��д�ļ�������ʱ��,������־�ļ��Ƿ��,Ϊ1��,Ϊ0�ر�, 6���豸����6, Ȼ����ÿ���豸������ͬʱ����5���ļ�,6*5=30
unsigned long int FAT32_RWWJ_culian[480];  //��д�ļ�������ʱ��,�����������, ���ﶨ��һ���豸�Ĵ�����ౣ��16���غ�, 6���豸����96, Ȼ����ÿ���豸������ͬʱ����5���ļ�,96*5=480
unsigned char FAT32_RWWJ_culianX[30];  //��д�ļ�������ʱ��,�����������ָ��,ָ���¸��غ�, 6���豸����6, Ȼ����ÿ���豸������ͬʱ����5���ļ�,6*5=30
unsigned long int FAT32_RWWJ_sqh_[30];  //��д�ļ�������ʱ��,�������浱ǰ�ض�ȡ������������, 6���豸����6, Ȼ����ÿ���豸������ͬʱ����5���ļ�,6*5=30
unsigned long int FAT32_RWWJ__sqh[30];  //��д�ļ�������ʱ��,�������浱ǰ�����һ��������+1, 6���豸����6, Ȼ����ÿ���豸������ͬʱ����5���ļ�,6*5=30
unsigned long int FAT32_RWWJ_cuhao[30];  //��д�ļ�������ʱ��,���������ļ��״غ�, 6���豸����6, Ȼ����ÿ���豸������ͬʱ����5���ļ�,6*5=30
unsigned long int FAT32_RWWJ__wjdx[30];  //��д�ļ�������ʱ��,���������ļ�ʣ��δ���ֽ���, 6���豸����6, Ȼ����ÿ���豸������ͬʱ����5���ļ�,6*5=30
unsigned long int FAT32_RWWJ_wjdx_[30];  //��д�ļ�������ʱ��,���������ļ����ֽ���, 6���豸����6, Ȼ����ÿ���豸������ͬʱ����5���ļ�,6*5=30



unsigned long int FAT32_SETUP_culian_sqh_[6]; //��¼�״غ�����������          �����С��Ӧ�豸����
unsigned long int FAT32_SETUP_culian__sqh_[6]; //��¼��ָ�غ�����������
unsigned long int FAT32_SETUP_culian__sqh[6]; //��¼ɨ��������
unsigned long int FAT32_SETUP_culian_cuhao_js1[6]; //��¼�Ѵ����غ�����
unsigned int FAT32_SETUP_culian_py1[6]; //��¼��ָ�غ��������ڵ�ƫ��
unsigned long int FAT32_SETUP_culian_FAT_[6]; //��¼FAT����������
unsigned long int FAT32_SETUP_culian__FAT[6]; //��¼FAT��β������+1
unsigned long int FAT32_SETUP_culian_CLX[6]; //��¼�봴��������
unsigned long int FAT32_DELETE_culian_FAT_[6]; //��¼FAT����������
unsigned long int FAT32_DELETE_culian__cuhao[6]; //��¼�غ�ָ����¸��غ�
unsigned char FAT32_SETUP_DELETE_fatx; //��¼fat��ѡ��



#define FAT32_DELETE_E5_32B_CLX 8  //��������
#define FAT32_DELETE_E5_CLX 8  //��������

unsigned long int FAT32_DELETE_E5_32B_culian[8]; //��¼����32B��λ�Ĵ���
unsigned char FAT32_DELETE_E5_32B_culianX; //��¼32B��λ�Ĵ�����ָ��
unsigned long int FAT32_DELETE_E5_32B_sqh_; //��¼32B��λ����������
unsigned long int FAT32_DELETE_E5_32B__sqh; //��¼32B��λ���ڴص�β������+1
unsigned int FAT32_DELETE_E5_32B_smzz; //32B��λ���������ڵ�ƫ��
unsigned long int FAT32_DELETE_E5_WJFDX; //��¼Ŀ¼����ļ����ܴ�С,��λ�ֽ�

unsigned char FAT32_DELETE_E5_qhc; //�л�����, =0ɨ��E5,=1��ʽ����

unsigned long int FAT32_DELETE_E5_culian[8]; //��¼��ɨ��Ĵ���
unsigned char FAT32_DELETE_E5_culianX; //��¼��ɨ��Ĵ�����ָ��
unsigned long int FAT32_DELETE_E5_sqh_; //��¼��ɨ������������
unsigned long int FAT32_DELETE_E5__sqh; //��¼��ɨ�����ڴص�β������+1
unsigned int FAT32_DELETE_E5_smzz; //��ɨ�����������ڵ�ƫ��


unsigned long int FAT32_VOID_cuhao_FAT_; //��¼FAT����������
unsigned long int FAT32_VOID_cuhao__FAT; //��¼FAT��β������+1
unsigned long int FAT32_VOID_cuhao_sqh; //��¼��ǰɨ������(�����ַ)
unsigned long int FAT32_VOID_cuhao_cuhao; //��¼�ҵ��ĿմصĴغ�


unsigned long int FAT32_UP_culian_cuhao_; //��¼��ǰɨ����״غ�
unsigned long int FAT32_UP_culian_DATADX; //��¼Ŀ�����ݴ�С,��λ�ֽ�
unsigned char FAT32_UP_culian_LBA_VOID_K; //��¼��������տ���,Ϊ1���������,Ϊ0�����������
unsigned long int FAT32_UP_culian_DATADX_; //��¼��ɨ���ݴ�С,��λ�ֽ�
unsigned char FAT32_UP_culian_XZ; //��¼��������ѡ��

#define FAT32_UP_culian_LBA_VOID_CLX 8  //��������,���Ҫ���������,���ﶨ��ÿ�ζ�ȡ�Ĵ�������

unsigned long int FAT32_UP_culian__cuhao; //����������ɾ���������״غ�
unsigned char FAT32_UP_culian_DELETE_culian_K; //ɾ����������,Ϊ0����ɾ������,Ϊ1��־Ϊ�洢�ռ䲻��,ɾ������
//unsigned long int FAT32_UP_culian__CLX; //��������,��¼����
unsigned char FAT32_UP_culian__cuhao_bz; //��¼�����������״غű�־,Ϊ0x00��ʾ�غ�ָ�����0x00000000,Ϊ0xff��ʾָ����0x0fffffff
unsigned long int FAT32_UP_culian_LBA_VOID_culian[8];  //��������,���Ҫ���������,�����¼ÿ�ζ�ȡ�Ĵ���
unsigned char FAT32_UP_culian_LBA_VOID_culiaX;  //��������,���Ҫ���������,�����¼������ָ��
unsigned long int FAT32_UP_culian_LBA_VOID_sqh_; //��������,���Ҫ���������,��¼�ص���������
unsigned long int FAT32_UP_culian_LBA_VOID__sqh; //��������,���Ҫ���������,��¼�ص�β������+1


#define FAT32_ML_SETUP_WJF_CLX 8  //Ŀ¼�����ļ���,�����ļ���,ÿ�ζ�ȡ�Ĵ�������

unsigned long int FAT32_ML_SETUP_WJF_mulu_cuhao; //Ŀ¼�����ļ���,Ŀ¼�״غ�
unsigned char FAT32_ML_SETUP_WJF_WJF[1024]; //Ŀ¼�����ļ���,��¼�ļ���
unsigned long int FAT32_ML_SETUP_WJF_WJFDX; //Ŀ¼�����ļ���,��¼���ļ�����С,��λ�ֽ�
unsigned char FAT32_ML_SETUP_WJF_XZ; //Ŀ¼�����ļ���,��¼��������ѡ��
unsigned long int FAT32_ML_SETUP_WJF_culian[8];  //Ŀ¼�����ļ���,�����ļ���,��¼ÿ�ζ�ȡ�Ĵ���
unsigned char FAT32_ML_SETUP_WJF_culiaX;  //Ŀ¼�����ļ���,�����ļ���,��¼������ָ��
unsigned long int FAT32_ML_SETUP_WJF_sqh_; //Ŀ¼�����ļ���,�����ļ���,��¼�ص���������
unsigned long int FAT32_ML_SETUP_WJF__sqh; //Ŀ¼�����ļ���,�����ļ���,��¼�ص�β������+1
unsigned int FAT32_ML_SETUP_WJF_WJFX; //Ŀ¼�����ļ���,�����ļ���,�ļ���ָ��


unsigned long int FAT32_ML_SETUP_WJ_mulu_cuhao; //Ŀ¼�����ļ�,��¼Ŀ¼���״غ�
unsigned long int FAT32_ML_SETUP_WJ_WJDX; //Ŀ¼�����ļ�,��¼�����ļ��Ĵ�С,��λ�ֽ�
unsigned char FAT32_ML_SETUP_WJ_WJFDATA_32B[32]; //Ŀ¼�����ļ�,��¼32���ֽڵ��ļ�������
unsigned int FAT32_ML_SETUP_WJ_CWJM[404]; //Ŀ¼�����ļ�,��¼���ļ���
unsigned char FAT32_ML_SETUP_WJ_LBA_VOID_K; //Ŀ¼�����ļ�,ѡ���Ƿ����������,���Ϊ1����0�´�ӳ�������,Ϊ0����0
unsigned char FAT32_ML_SETUP_WJ_XZ; //Ŀ¼�����ļ�,��¼��������ѡ��


unsigned long int FAT32_ML_DELETE_WJ_cuhao; //Ŀ¼ɾ���ļ�,��¼�ļ��״غ�
unsigned char FAT32_ML_DELETE_WJ_XZ; //Ŀ¼ɾ���ļ�,��¼��������ѡ��


unsigned long int FAT32_ML_XGWJM_mulu_cuhao; //Ŀ¼�޸��ļ���,��¼Ŀ¼�״غ�
unsigned char FAT32_ML_XGWJM_S_WJFDATA_32B[32]; //Ŀ¼�޸��ļ���,��¼ԭ�ļ�����32���ֽڵ��ļ�������
unsigned int FAT32_ML_XGWJM_S_CWJM[404]; //Ŀ¼�޸��ļ���,��¼ԭ�ļ����ĳ��ļ���
unsigned char FAT32_ML_XGWJM_D_WJFDATA_32B[32]; //Ŀ¼�޸��ļ���,��¼���ļ�����32���ֽڵ��ļ�������
unsigned int FAT32_ML_XGWJM_D_CWJM[404]; //Ŀ¼�޸��ļ���,��¼���ļ����ĳ��ļ���
unsigned char FAT32_ML_XGWJM_XZ; //Ŀ¼�޸��ļ���,��¼��������ѡ��





