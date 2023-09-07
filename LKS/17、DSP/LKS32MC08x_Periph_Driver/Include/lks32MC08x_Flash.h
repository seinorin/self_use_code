/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� LKS32MC_08x_flash.h
 * �ļ���ʶ��
 * ����ժҪ�� flash������������
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� Howlet
 * ������ڣ� 2016��3��25��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�2020��12��15��
 * �� �� �ţ�V 1.2
 * �� �� �ˣ�DengT
 * �޸����ݣ����ӳ����ܷ�ʱ����Flash�ı���
 *
 *******************************************************************************/
#ifndef __lks32mc08x_FLASH__
#define __lks32mc08x_FLASH__
#include "lks32mc08x.h"

#define Flash_MAIN 0x000
#define Flash_NVR  0x800

extern volatile u32 erase_flag;
extern volatile u32 progm_flag;
int ProgramPage(u32 adr, u32 sz, u8 *buf, u16 nvr);
extern void EraseSector(u32 adr, u16 nvr);
void Read_More_Flash(u32 adr, u32 sz, u32 *buf, u16 nvr);

#endif

