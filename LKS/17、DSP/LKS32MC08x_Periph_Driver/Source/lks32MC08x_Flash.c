/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc081_flash.c
 * �ļ���ʶ��
 * ����ժҪ�� Flash������������
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� Howlet
 * ������ڣ� 2019��3��5��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�2019��3��5��
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�Howlet
 * �޸����ݣ�����
 *
 * �޸ļ�¼2��
 * �޸����ڣ�
 * �� �� �ţ�
 * �� �� �ˣ�
 * �޸����ݣ�
 *
 *******************************************************************************/
#include "basic.h"
#include "lks32mc08x.h"
#include "lks32MC08x_Flash.h"
#include "lks32MC08x_nvr.h"
volatile u32 erase_flag = 0;
volatile u32 progm_flag = 0;



/*******************************************************************************
 �������ƣ�    void EraseSector(unsigned long adr, unsigned long nvr)
 ����������    Flash��������������
 �����ı�    ��
 ���������    adr��       ������ַ  (һ������512�ֽ�)
               nvr��       Ϊ0x800��ʱ�����NVR, Ϊ0ʱ������Flash 
               erase_flag�����ú���ǰ���븳ֵ0x9A0D361F������ִ�в����������������ܷ�
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/12/15      V1.2           DengT            ����
 *******************************************************************************/
void EraseSector(u32 adr, u16 nvr)
{
    u32 key1,key2,key3;

    key1 = 0x0;key2 = 0x0;key3 = 0x0;
    if(erase_flag == 0x9A0D361F)
    { //get flash_cfg addr
      key1   = 0xB00C060A;
      key2   = 0x6A013415;
      key3   = erase_flag ^ key1 ^ key2;
      REG32(key3) &=~0x80008000;
      FLASH_ADDR = adr;     
      REG32(key3) |=(0x80000000|nvr);
      key1 = 0x0;key2 = 0x0;key3 = 0x0;
    }

    if(erase_flag == 0x9A0D361F)
    { //get flash_erase addr
      key1   = 0xB001341A;
      key2   = 0x6A0C0615;
      key3   = erase_flag ^ key1 ^ key2;
      REG32(key3)= 0x7654DCBA;//trig sector erase, FLASH_ERASE
      FLASH_CFG &=~0x80000000;
      erase_flag = 0x00000000;
      key1 = 0x0;key2 = 0x0;key3 = 0x0;
    }
    FLASH_CFG &=~0x80000000;
    erase_flag = 0x00000000;
    key1 = 0x0;key2 = 0x0;key3 = 0x0;
}


/*******************************************************************************
 �������ƣ�    ProgramPage(unsigned long adr, unsigned long sz, unsigned char *buf)
 ����������    Flash��̲���
 �����ı�    ��
 ���������    adr��������ַ  
               sz : ����ֽ�����(0~512�ֽ�) 
               buf: Ҫ��̵���������ָ�룻
               nvr��       Ϊ0x800��ʱ����NVR, Ϊ0ʱ�����Flash 
               progm_flag�����ú���ǰ���븳ֵ0x9AFDA40C������ִ�б�̣������������ܷ�
 ���������    ��
 �� �� ֵ��    1����̳ɹ���  0: ���ʧ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/12/15      V1.2           DengT            ����
 *******************************************************************************/
int ProgramPage(u32 adr, u32 sz, u8 *buf, u16 nvr)
{

    /* Add your Code */
    volatile u32 Addr, size;
    volatile u8 *p;
    volatile u8 t_rlt = 1;

    u32 key1,key2,key3;
  
    key1 = 0x0;key2 = 0x0;key3 = 0x0;

    if(progm_flag == 0x9AFDA40C)
    {
      //get flash_cfg addr
      key1   = 0x6A5C040F;
      key2   = 0xB0A1A403;

      key3   = progm_flag ^ key1 ^ key2;
      REG32(key3) &=~0x80008000;
      FLASH_ADDR = adr;     
      REG32(key3) |=(0x08000000|nvr);
      progm_flag = 0;
      key1 = 0x0;key2 = 0x0;key3 = 0x0;

      p    = buf;
      size = (sz + 3) & ~3;                  // align the word
      Addr = adr;
      while(size)
      {
        FLASH_ADDR = (Addr & ~0x00000003);   // address alignment
        FLASH_WDATA= *p + (*(p+1)<<8) + (*(p+2)<<16) + (*(p+3)<<24);            // write data to flash

        p    += 4;
        size -= 4;                           // Go to next word
        Addr += 4;
      }

      p    = buf;
      size = (sz + 3) & ~3;                  // align the word
      Addr = adr;
      while(size)
      {
        u32 t_RData;
        FLASH_ADDR = (Addr & ~0x00000003);   // address alignment
        t_RData = *p + (*(p+1)<<8) + (*(p+2)<<16) + (*(p+3)<<24);
        if(t_RData != FLASH_RDATA)
        {
            t_rlt = 0;
        }

        p    += 4;
        size -= 4;
        Addr += 4;
      }

    }
    FLASH_CFG &= ~0x08000800;
    key1 = 0x0;key2 = 0x0;key3 = 0x0;
    progm_flag = 0;
    return (t_rlt);
}


/*******************************************************************************
 �������ƣ�    void MCPWM0_RegUpdate(void)
 ����������    ��ȡFLASH���ݺ���
 ���������    adr��Ҫ��ȡ���ݵĵ�ַ  
               nvr��Ϊ0����ȡMAIN���ݣ�Ϊ1����ȡNVR����
 ���������    ��ȡ������ֵ
 �� �� ֵ��    data
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2021/3/5      V1.0                                ����
 *******************************************************************************/
u32 Read_Flash(uint32_t adr , u16 nvr)
{
   uint32_t data;
	 if(nvr == Flash_MAIN) //��ȡMIAN����
	 {
	   FLASH_CFG &= ~BIT11;
	   FLASH_ADDR = adr;
	   data = FLASH_RDATA;	
	 }else{
	   data =  Read_NVR(adr);
	 }
	 
	 FLASH_CFG &= ~BIT11;  //�ָ�MIAN����
	 return data;
}

/*******************************************************************************
 �������ƣ�    void MCPWM0_RegUpdate(void)
 ����������    ��ȡFLASH���ַ���ݺ���
 ���������    adr��Ҫ��ȡ���ݵĵ�ַ
               nvr��Ϊ0����ȡMAIN���ݣ�Ϊ1����ȡNVR����
							 buf:��ȡ���ݴ洢�ĵ�ַ
               sz :��ȡsz����
 ���������    ��ȡ������ֵ
 �� �� ֵ��    data
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2021/3/5      V1.0                                ����
 *******************************************************************************/
void Read_More_Flash(u32 adr, u32 sz, u32 *buf, u16 nvr)
{
	 volatile u32 Addr = 0;
   volatile u32	size = 0;
   volatile u32 *p;
	 size = sz;
	 Addr = adr;
	 p  = buf;
	 printf("size= %d\r\n ", size);
	 while(size)
	 {	 
		 *p = Read_Flash(Addr , nvr);
		 while(!(FLASH_READY&BIT0));	
	   size -= 1;  
		 Addr += 4;
		 p += 1;		 
	 }
}




