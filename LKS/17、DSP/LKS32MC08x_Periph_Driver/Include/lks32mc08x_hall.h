/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_hall.h
 * �ļ���ʶ��
 * ����ժҪ�� HALL����ͷ�ļ�
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
 
#ifndef __lks32mc08x_HALL_H
#define __lks32mc08x_HALL_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "basic.h"


typedef struct
{
   __IO uint32_t CFG;
   __IO uint32_t INFO;
   __IO uint32_t WIDTH;
   __IO uint32_t TH;
	 __IO uint32_t CNT;
	
}HALL_TypeDef;

typedef struct
{
   uint16_t FilterLen;                /*�˲�����,0��Ӧ����1,1023��Ӧ����1024�˲�����*/
   uint8_t ClockDivision;            /*��Ƶ 0~3:/1 /2 /4 /8*/
   uint8_t Filter75_Ena;             /*ʹ�ܵ�һ��7/5�˲�,�ߵ�ƽ��Ч*/
   uint8_t HALL_Ena;                 /*ʹ��HALL,�ߵ�ƽ��Ч*/
   uint8_t Capture_IRQ_Ena;          /*HALL�źű仯�ж�ʹ��,�ߵ�ƽ��Ч*/
   uint8_t OverFlow_IRQ_Ena;         /*HALL����������ж�ʹ��,�ߵ�ƽ��Ч*/
   uint32_t CountTH;                  /*HALL����������ֵ*/
	 uint8_t softIE;                   /* ����ж�ʹ�� */
}HALL_InitTypeDef;

#define HALL_CLK_DIV1 ((uint32_t)0x00)
#define HALL_CLK_DIV2 ((uint32_t)0x01)
#define HALL_CLK_DIV4 ((uint32_t)0x02)
#define HALL_CLK_DIV8 ((uint32_t)0x03)

#define HALL_CAPTURE_EVENT  ((uint32_t)0x00010000)
#define HALL_OVERFLOW_EVENT ((uint32_t)0x00020000)

void HALL_Init(HALL_InitTypeDef* HALL_InitStruct);
void HALL_StructInit(HALL_InitTypeDef* HALL_InitStruct);

uint32_t HALL_GetFilterValue(void);
uint32_t HALL_GetCaptureValue(void);
uint32_t HALL_GetCount(void);

uint32_t HALL_IsCaptureEvent(void);
uint32_t HALL_IsOverFlowEvent(void);

void HALL_Clear_IRQ(void);

#endif /*__lks32mc08x_HALL_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
