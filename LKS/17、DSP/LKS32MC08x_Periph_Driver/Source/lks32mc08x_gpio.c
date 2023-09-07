/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc081_gpio.c
 * �ļ���ʶ��
 * ����ժҪ�� GPIO������������
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� cfwu
 * ������ڣ� 2016��4��18��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�
 * �޸����ݣ�����
 *
 * �޸ļ�¼2��
 * �޸����ڣ� 2016��6��19��
 * �� �� �ţ� v1.1
 * �� �� �ˣ� cfwu
 * �޸����ݣ� ����ChanHomB�����޸�
 *
 *******************************************************************************/
#include "lks32mc08x_gpio.h"
#include "lks32mc08x.h"

/*******************************************************************************
 �������ƣ�    void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
 ����������    GPIO��ʼ��
 �����ı�    ��
 ���������    GPIOx:GPIO����, GPIO_InitStruct:GPIO��ʼ���ṹ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/4/18      V1.0           cfwu              ����
 *******************************************************************************/
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
    uint32_t pinpos = 0x00, pos = 0x00, currentpin = 0x00, tempreg = 0x00;

    /*-------------------------- Configure the port pins -----------------------*/
    for (pinpos = 0x00; pinpos < 0x10; pinpos++)
    {
        pos = ((uint32_t)0x01) << pinpos;

        /* Get the port pins position */
        currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;
        if (currentpin == pos)
        {
            if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IN)
            {
                tempreg = GPIOx->PIE;    /*ʹ������*/
                tempreg |= (BIT0 << pinpos);
                GPIOx->PIE = tempreg;

                tempreg = GPIOx->POE;    /*��ֹ���*/
                tempreg &= ~(BIT0 << pinpos);
                GPIOx->POE = tempreg;
            }
            else if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT)
            {
                tempreg = GPIOx->PIE;    /*��ֹ����*/
                tempreg &= ~(BIT0 << pinpos);
                GPIOx->PIE = tempreg;

                tempreg = GPIOx->POE;    /*ʹ�����*/
                tempreg |= (BIT0 << pinpos);
                GPIOx->POE = tempreg;
            }
            else if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_ANA)
            {
                tempreg = GPIOx->POE;    /*��ֹ���*/
                tempreg &= ~(BIT0 << pinpos);
                GPIOx->POE = tempreg;
            }

            if (GPIO_InitStruct->GPIO_PuPd == GPIO_PuPd_UP)
            {
                tempreg = GPIOx->PUE;
                tempreg |= (BIT0 << pinpos);
                GPIOx->PUE = tempreg;
            }
            else if (GPIO_InitStruct->GPIO_PuPd == GPIO_PuPd_DOWN)
            {
                tempreg = GPIOx->PDE;
                tempreg |= (BIT0 << pinpos);
                GPIOx->PDE = tempreg;
            }
            else if (GPIO_InitStruct->GPIO_PuPd == GPIO_PuPd_NOPULL)
            {
                tempreg = GPIOx->PUE;
                tempreg &= ~(BIT0 << pinpos);
                GPIOx->PUE = tempreg;

                tempreg = GPIOx->PDE;
                tempreg &= ~(BIT0 << pinpos);
                GPIOx->PDE = tempreg;
            }

            tempreg = GPIOx->PODE;
            if(GPIO_InitStruct->GPIO_PODEna == (uint32_t)ENABLE)
            {
                tempreg |= (BIT0 << pinpos);
            }
            else
            {
                tempreg &= ~(BIT0 << pinpos);
            }
            GPIOx->PODE = tempreg;
        }
    }
}

/*******************************************************************************
 �������ƣ�    void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
 ����������    GPIO�ṹ���ʼ��
 �����ı�    ��
 ���������    GPIO_InitStruct:GPIO��ʼ���ṹ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/4/18      V1.0           cfwu              ����
 *******************************************************************************/
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
{
    GPIO_InitStruct->GPIO_Pin  = GPIO_Pin_NONE;
    GPIO_InitStruct->GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct->GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct->GPIO_PODEna = DISABLE;
}

/*******************************************************************************
 �������ƣ�    uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
 ����������    ��ȡGPIO��ָ��Pin������ֵ
 �����ı�    ��
 ���������    GPIOx:GPIO����, GPIO_Pin:ָ����Pin
 ���������    ��
 �� �� ֵ��    ָ��Pin������ֵ
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/7/1       V1.0           cfwu              ����
 *******************************************************************************/
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    uint8_t bitstatus = 0x00;
    if ((GPIOx->PDI & GPIO_Pin) != 0)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}

/*******************************************************************************
 �������ƣ�    uint32_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
 ����������    ��ȡGPIO����������
 �����ı�    ��
 ���������    GPIOx:GPIO����
 ���������    ��
 �� �� ֵ��    ��������
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/4/18      V1.0           cfwu              ����
 *******************************************************************************/
uint32_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
{
    return GPIOx->PDI;
}

/*******************************************************************************
 �������ƣ�    uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
 ����������    ��ȡGPIO��ָ��Pin�����ֵ
 �����ı�    ��
 ���������    GPIOx:GPIO����, GPIO_Pin:ָ����Pin
 ���������    ��
 �� �� ֵ��    ָ��Pin�����ֵ
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/4/18      V1.0           cfwu              ����
 *******************************************************************************/
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    uint8_t bitstatus = 0x00;
    if ((GPIOx->PDO & GPIO_Pin) != 0)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}

/*******************************************************************************
 �������ƣ�    uint32_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
 ����������    ��ȡGPIO�ĵ�ǰ�������
 �����ı�    ��
 ���������    GPIOx:GPIO����
 ���������    ��
 �� �� ֵ��    �������
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/4/18      V1.0           cfwu              ����
 *******************************************************************************/
uint32_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
{
    return GPIOx->PDO;
}

/*******************************************************************************
 �������ƣ�    void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
 ����������    GPIOָ��Pin��1
 �����ı�    ��
 ���������    GPIOx:GPIO����, GPIO_Pin:ָ����Pin
 ���������    ��
 �� �� ֵ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/7/2      V1.0           cfwu              ����
 *******************************************************************************/
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_SET);
}

/*******************************************************************************
 �������ƣ�    void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
 ����������    GPIOָ��Pin��0
 �����ı�    ��
 ���������    GPIOx:GPIO����, GPIO_Pin:ָ����Pin
 ���������    ��
 �� �� ֵ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/7/2      V1.0           cfwu              ����
 *******************************************************************************/
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_RESET);
}

/*******************************************************************************
 �������ƣ�    void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t BitVal)
 ����������    ��GPIOָ����Pinд������
 �����ı�    ��
 ���������    GPIOx:GPIO����, GPIO_Pin:ָ����Pin, BitVal:д���Bitֵ
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/4/18      V1.0           cfwu              ����
 *******************************************************************************/
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
{
    uint32_t tempVal;
    tempVal = GPIOx->PDO;
    if (BitVal != Bit_RESET)
    {
        tempVal |= GPIO_Pin;
    }
    else
    {
        tempVal &= ~GPIO_Pin;
    }
    GPIOx->PDO = tempVal;
}

/*******************************************************************************
 �������ƣ�    void GPIO_Write(GPIO_TypeDef* GPIOx, uint32_t Val)
 ����������    ��GPIOд������
 �����ı�    ��
 ���������    GPIOx:GPIO����, Val:д���ֵ
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/4/18      V1.0           cfwu              ����
 *******************************************************************************/
void GPIO_Write(GPIO_TypeDef* GPIOx, uint32_t Val)
{
    GPIOx->PDO = Val;
}

/*******************************************************************************
 �������ƣ�    void GPIO_LockRegister(GPIO_TypeDef* GPIOx)
 ����������    GPIO�Ĵ�����������
 �����ı�    ��
 ���������    GPIOx:GPIO����
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/6/19      V1.0          cfwu               ����
 *******************************************************************************/
void GPIO_LockRegister(GPIO_TypeDef* GPIOx)
{
    LCKR_PRT = ENABLE;
    GPIOx->LCKR = ENABLE;
}

/*******************************************************************************
 �������ƣ�    void GPIO_UnlockRegister(GPIO_TypeDef* GPIOx)
 ����������    GPIO�����Ĵ�������
 �����ı�    ��
 ���������    GPIOx:GPIO����
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/6/19      V1.0          cfwu               ����
 *******************************************************************************/
void GPIO_UnlockRegister(GPIO_TypeDef* GPIOx)
{
    GPIOx->LCKR = DISABLE;
}

/*******************************************************************************
 �������ƣ�    void GPIO_PadAFConfig(GPIO_TypeDef* GPIOx, uint32_t GPIO_PadSource, uint32_t GPIO_AF)
 ����������    GPIO����ѡ��
 �����ı�    ��
 ���������    GPIOx:GPIO����, GPIO_PadSource:ָ����PadSource, GPIO_AF:ָ���Ĺ���
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2016/6/19      V1.0          cfwu               ����
 *******************************************************************************/
void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint32_t GPIO_PinSource, uint32_t GPIO_AF)
{
    uint32_t temp;
    switch(GPIO_PinSource)
    {
    /*F3210*/
    case 0:
    {
        temp = GPIOx->F3210 & 0xFFF0;  /*get F321*/
        GPIOx->F3210 = temp + GPIO_AF; /*F321 + F0*/
        break;
    }
    case 1:
    {
        temp = GPIOx->F3210 & 0xFF0F;
        GPIOx->F3210 = temp + (GPIO_AF << 4);
        break;
    }
    case 2:
    {/* 2020.8.13 Repair bug HL */
        temp = GPIOx->F3210 & 0xF0FF;
        GPIOx->F3210 = temp + (GPIO_AF << 8);
        break;
    }
    case 3:
    {
        temp = GPIOx->F3210 & 0x0FFF;
        GPIOx->F3210 = temp + (GPIO_AF << 12);
        break;
    }
    /*F7654*/
    case 4:
    {
        temp = GPIOx->F7654 & 0xFFF0;
        GPIOx->F7654 = temp + GPIO_AF;
        break;
    }
    case 5:
    {
        temp = GPIOx->F7654 & 0xFF0F;
        GPIOx->F7654 = temp + (GPIO_AF << 4);
        break;
    }
    case 6:
    {
        temp = GPIOx->F7654 & 0xF0FF;
        GPIOx->F7654 = temp + (GPIO_AF << 8);
        break;
    }
    case 7:
    {
        temp = GPIOx->F7654 & 0x0FFF;
        GPIOx->F7654 = temp + (GPIO_AF << 12);
        break;
    }
    /*FBA98*/
    case 8:
    {
        temp = GPIOx->FBA98 & 0xFFF0;
        GPIOx->FBA98 = temp + GPIO_AF;
        break;
    }
    case 9:
    {
        temp = GPIOx->FBA98 & 0xFF0F;
        GPIOx->FBA98 = temp + (GPIO_AF << 4);
        break;
    }
    case 10:
    {
        temp = GPIOx->FBA98 & 0xF0FF;
        GPIOx->FBA98 = temp + (GPIO_AF << 8);
        break;
    }
    case 11:
    {
        temp = GPIOx->FBA98 & 0x0FFF;
        GPIOx->FBA98 = temp + (GPIO_AF << 12);
        break;
    }
    /*FFEDC*/
    case 12:
    {
        temp = GPIOx->FFEDC & 0xFFF0;
        GPIOx->FFEDC = temp + GPIO_AF;
        break;
    }
    case 13:
    {
        temp = GPIOx->FFEDC & 0xFF0F;
        GPIOx->FFEDC = temp + (GPIO_AF << 4);
        break;
    }
    case 14:
    {
        temp = GPIOx->FFEDC & 0xF0FF;
        GPIOx->FFEDC = temp + (GPIO_AF << 8);
        break;
    }
    case 15:
    {
        temp = GPIOx->FFEDC & 0x0FFF;
        GPIOx->FFEDC = temp + (GPIO_AF << 12);
        break;
    }
    default:
        break;
    }
}


/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
