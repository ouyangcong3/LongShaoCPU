#include<io.h>
#include<qjbldy.h>
#include<ds1302.h>
#include<spi.h>
#include<tf_sd.h>
#include<fat32.h>
#include<VGA.h>
//#include<string.h>
#include<printing.h>
#include<add_sys.h>


main()
{

    VGA_VRAM_LD(); //װ���Դ�
    VGA_SK0(0,240,255); //����
    VGA_VRAM_UP(); //�����Դ�

    SPI_RST(); //��λSPI������


    TF_SD_CSH(0); //��ʼ���豸0�ڴ濨(��ʼ����"KC-LS1u_SPI_C"PCB�ϵ�"S_CS0"Ƭѡ�ߵ��豸),�����ʼ���ɹ�����ֵ��Ϊ0;
    FAT32_csh(0); //��ʼ���豸0�ļ�ϵͳ,�����ʼ���ɹ�����ֵ��Ϊ0

    ADD_SYS(); //����ϵͳ�ļ�,����ֵΪ1���


/*-----------------��ʾ�ַ���------------------*/

    VGA_VRAM_LD(); //װ���Դ�

    printx(128,16,"������֮����(����)",69); //����YXΪ128��16,"������֮����(����)",����ֵΪ69

    printx(115,16,"74�ŵ�·8λ�����KC-LS1u",0xe0); //����YXΪ115��16,"74�ŵ�·8λ�����KC-LS1u",����ֵΪ0xe0

    VGA_VRAM_UP(); //�����Դ�


    while(1);

}