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

#include "lks32mc08x_cmp.h"
#include "lks32mc08x.h"
#include "string.h"
#include "lks32mc08x_sys.h"

/*******************************************************************************
 �������ƣ�    void Comparator_init(CMP_InitTypeDef* CMP_InitStruct)
 ����������    CMP��ʼ��
 �����ı�    ��
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2018/11/26      V1.0           Howlet Li          ����
 *******************************************************************************/
void Comparator_init(CMP_InitTypeDef* CMP_InitStruct)
{
    if(CMP_InitStruct->CMP0_EN)
    {
        SYS_AnalogModuleClockCmd( SYS_AnalogModule_CMP0,ENABLE);    //CMP0ʹ��
    }
    else
    {
        SYS_AnalogModuleClockCmd( SYS_AnalogModule_CMP0,DISABLE);
    }
    
    if(CMP_InitStruct->CMP1_EN)
    {
        SYS_AnalogModuleClockCmd( SYS_AnalogModule_CMP1,ENABLE);     //CMP1ʹ��
    }
    else
    {
        SYS_AnalogModuleClockCmd( SYS_AnalogModule_CMP1,DISABLE);
    }
    
    SYS_AFE_REG3 |= (CMP_InitStruct->CMP0_SELN << 2) | (CMP_InitStruct->CMP1_SELN << 4) | (CMP_InitStruct->CMP0_SELP << 8) |
                    (CMP_InitStruct->CMP1_SELP << 12) | (CMP_InitStruct->CMP_HYS << 7);

    /* CMP_HYS �Ƚ����ͻع��ܣ�Ĭ��20mV, д0�ر� */

    SYS_AFE_REG1 |= CMP_InitStruct->CMP_FT; /* ���ٱȽϣ�Enable�� 30nS */

    SYS_AFE_REG5 |= (CMP_InitStruct->CMP0_EN << 6) | (CMP_InitStruct->CMP1_EN << 7);


    CMP_TCLK = (CMP_InitStruct->CMP_CLK_EN << 3) | (CMP_InitStruct->CMP_CNK_PRSC) | (CMP_InitStruct->CMP_FltCnt << 4);
    CMP_IE = CMP_InitStruct->CMP0_IE | (CMP_InitStruct->CMP1_IE << 1);
    CMP_CFG = CMP_InitStruct->CMP0_Polarity | (CMP_InitStruct->CMP0_InEnable << 1) |
              (CMP_InitStruct->CMP1_Polarity << 4) | (CMP_InitStruct->CMP1_InEnable << 5);
}

/*******************************************************************************
 �������ƣ�    void CMP_StructInit(CMP_InitTypeDef* CMP_InitStruct)
 ����������    CMP��ʼ��
 �����ı�    ��
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2018/11/26      V1.0           Howlet Li          ����
 *******************************************************************************/
void CMP_StructInit(CMP_InitTypeDef* CMP_InitStruct)
{

    memset(CMP_InitStruct, 0, sizeof(CMP_InitTypeDef));
}

