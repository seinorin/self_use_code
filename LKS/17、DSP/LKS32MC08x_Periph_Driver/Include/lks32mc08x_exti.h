/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_exti.h
 * �ļ���ʶ��
 * ����ժҪ�� EXTI�ⲿ�ж�����ͷ�ļ�
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
 
#ifndef __lks32mc08x_EXTI_H
#define __lks32mc08x_EXTI_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "basic.h"

typedef struct  
{
   __IO uint32_t CR0;
   __IO uint32_t CR1;
   __IO uint32_t IF;   
}EXTI_TypeDef;

/*typedef struct
{
   uint32_t Pad0Trig;
   uint32_t Pad1Trig;
   uint32_t Pad2Trig;
   uint32_t Pad3Trig;
   uint32_t Pad4Trig;
   uint32_t Pad5Trig;
   uint32_t Pad6Trig;
   uint32_t Pad7Trig;	
   uint32_t Pad8Trig;	
   uint32_t Pad9Trig;	
   uint32_t Pad10Trig;	
   uint32_t Pad11Trig;	
   uint32_t Pad12Trig;	
   uint32_t Pad13Trig;	
   uint32_t Pad14Trig;	
   uint32_t Pad15Trig;	
}EXTI_InitTypeDef;*/

/*EXTI_Pad define*/
#define EXTI_Pad_None     0
#define EXTI_Pad_0        BIT0
#define EXTI_Pad_1        BIT1
#define EXTI_Pad_2        BIT2
#define EXTI_Pad_3        BIT3
#define EXTI_Pad_4        BIT4
#define EXTI_Pad_5        BIT5
#define EXTI_Pad_6        BIT6
#define EXTI_Pad_7        BIT7
#define EXTI_Pad_8        BIT8
#define EXTI_Pad_9        BIT9
#define EXTI_Pad_10       BIT10
#define EXTI_Pad_11       BIT11
#define EXTI_Pad_12       BIT12
#define EXTI_Pad_13       BIT13
#define EXTI_Pad_14       BIT14
#define EXTI_Pad_15       BIT15
#define EXTI_Pad_All      (uint32_t)0xFFFF

typedef enum
{
   EXTI_TRG_None = 0x00,             /*������*/
   EXTI_TRG_Falling = 0x01,          /*�½��ش���*/
   EXTI_TRG_Rising = 0x02,           /*�����ش���*/
	 EXTI_TRG_Falling_Rising = 0x03,   /*˫�ش���*/
}EXTITrig_TypeDef;

typedef struct
{
   uint32_t EXTI_Pad;                /* �ⲿ�ж�IO*/
   EXTITrig_TypeDef EXTI_Trig;       /* ��������*/
}EXTI_InitTypeDef;

#define EXTI0 ((EXTI_TypeDef *) EXTI_BASE)

void EXTI_Init(EXTI_TypeDef* EXTIx, EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);

uint32_t EXTI_ReadIFFlag(EXTI_TypeDef* EXTIx);
void EXTI_ResetIF(EXTI_TypeDef* EXTIx, uint32_t temp);

#endif /*__lks32mc08x_EXTI_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
