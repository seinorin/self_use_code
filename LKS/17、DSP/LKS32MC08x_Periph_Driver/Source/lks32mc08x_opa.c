/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_opa.c
 * �ļ���ʶ��
 * ����ժҪ�� OPA�˷���������
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� 
 * ������ڣ� 
 *
 * �޸ļ�¼1��
 * �޸����ڣ�
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�
 * �޸����ݣ�����
 *
 * �޸ļ�¼2��
 * �޸����ڣ�
 * �� �� �ţ�
 * �� �� �ˣ�
 * �޸����ݣ�
 *
 *******************************************************************************/
#include "lks32mc08x_opa.h"

/*******************************************************************************
 �������ƣ�    void OPA_Init(OPA_InitTypeDef* OPA_InitStruct)
 ����������    OPA��ʼ��
 �����ı�    ��
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/06/02      V1.0           cfwu          ����
 *******************************************************************************/
void OPA_Init(enumOPA opa, OPA_InitTypeDef* OPA_InitStruct)
{
	uint32_t tmp1, tmp2;
	tmp1 = SYS_AFE_REG0;
	tmp2 = SYS_AFE_REG5;

	if (opa == OPA0)
	{
		tmp1 &= ~(BIT0 | BIT1);
		tmp1 |= OPA_InitStruct->OPA_Gain;

		tmp2 &= ~BIT2;
		tmp2 |= OPA_InitStruct->OPA_CLEna << 2;
	}
	else if (opa == OPA1)
	{
		tmp1 &= ~(BIT2 | BIT3);
		tmp1 |= (OPA_InitStruct->OPA_Gain << 2);

		tmp2 &= ~BIT3;
		tmp2 |= (OPA_InitStruct->OPA_CLEna << 3);
	}
	else if (opa == OPA2)
	{
		tmp1 &= ~(BIT4 | BIT5);
		tmp1 |= (OPA_InitStruct->OPA_Gain << 4);

		tmp2 &= ~BIT4;
		tmp2 |= (OPA_InitStruct->OPA_CLEna << 4);
	}
	else if (opa == OPA3)
	{
		tmp1 &= ~(BIT6 | BIT7);
		tmp1 |= (OPA_InitStruct->OPA_Gain << 6);

		tmp2 &= ~BIT5;
		tmp2 |= (OPA_InitStruct->OPA_CLEna << 5);
	}

	SYS_AFE_REG0 = tmp1;
	SYS_AFE_REG5 = tmp2;
}

/*******************************************************************************
 �������ƣ�    void OPA_StructInit(OPA_InitTypeDef* OPA_InitStruct)
 ����������    OPA�ṹ���ʼ��
 �����ı�    ��
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/06/02      V1.0           cfwu          ����
 *******************************************************************************/
void OPA_StructInit(OPA_InitTypeDef* OPA_InitStruct)
{
   OPA_InitStruct->OPA_Gain = PGA_GAIN_4P25;
   OPA_InitStruct->OPA_CLEna = DISABLE;
}

/*******************************************************************************
 �������ƣ�    void OPA_OUT(enumOPA opa, FuncState state)
 ����������    OPA�ⲿ�����������ⲿP2.7����
 �����ı�    ��
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/06/02      V1.0           cfwu          ����
 *******************************************************************************/
void OPA_OUT(enumOPA opa, FuncState state)
{
	
	if (opa == OPA0)
	{
		if (state != DISABLE)
		{
			SYS_AFE_REG2 = 0x01;
		}
		else
		{
			SYS_AFE_REG2 = 0x00;
		}
	}
	else if (opa == OPA1)
	{
		if (state != DISABLE)
		{
			SYS_AFE_REG2 = 0x02;
		}
		else
		{
			SYS_AFE_REG2 = 0x00;;
		}
	}
	else if (opa == OPA2)
	{
		if (state != DISABLE)
		{
			SYS_AFE_REG2 = 0x03;
		}
		else
		{
			SYS_AFE_REG2 = 0x00;
		}
	}
	else if (opa == OPA3)
	{
		if (state != DISABLE)
		{
			SYS_AFE_REG2 = 0x04;
		}
		else
		{
			SYS_AFE_REG2 = 0x00;
		}
	}

}

/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
