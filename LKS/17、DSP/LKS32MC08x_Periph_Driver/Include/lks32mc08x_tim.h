/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_tim.h
 * �ļ���ʶ��
 * ����ժҪ�� TIM����ͷ�ļ�
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

#ifndef __lks32mc08x_TIM_H
#define __lks32mc08x_TIM_H

/* Includes ------------------------------------------------------------------*/

#include "basic.h"


typedef struct
{
    __IO uint32_t CFG;
    __IO uint32_t TH;
    __IO uint32_t CNT;
    __IO uint32_t CMPT0;
    __IO uint32_t CMPT1;
    __IO uint32_t EVT;
} TIM_TimerTypeDef;

typedef struct
{
    __IO uint32_t CFG;
    __IO uint32_t TH;
    __IO uint32_t CNT;
} TIM_ECDTypeDef;



#define TIM_Clk_Div1          0x00         /*Timer����Ƶ��96M*/
#define TIM_Clk_Div2          0x01         /*Timer����Ƶ��48M*/
#define TIM_Clk_Div4          0x02         /*Timer����Ƶ��24M*/
#define TIM_Clk_Div8          0x03         /*Timer����Ƶ��12M*/

#define ECD_Clk_Div1          0x00         /*ECD����Ƶ��96M*/
#define ECD_Clk_Div2          0x01         /*ECD����Ƶ��48M*/
#define ECD_Clk_Div4          0x02         /*ECD����Ƶ��24M*/
#define ECD_Clk_Div8          0x03         /*ECD����Ƶ��12M*/

/*�ж�ʹ�����ö���*/
typedef enum
{
    Timer_IRQEna_None = 0,
    Timer_IRQEna_Zero = BIT0,     /*ʹ�ܹ����ж�*/
    Timer_IRQEna_CH0 = BIT1,      /*ʹ��CH0�жϣ����Ƚϡ������ж�*/
    Timer_IRQEna_CH1 = BIT2,      /*ʹ��CH1�жϣ����Ƚϡ������ж�*/
    Timer_IRQEna_All = 0x07       /*ʹ��Timerȫ���ж�*/
} Timer_IRQEnaDef;

/*�жϱ�־����*/
#define TIMER_IF_CH0               BIT0     /*Timer0 CH0�жϣ��Ƚϻ򲶻��ж�*/
#define TIMER_IF_CH1               BIT1     /*Timer0 CH1�жϣ��Ƚϻ򲶻��ж�*/
#define TIMER_IF_ZERO              BIT2     /*Timer0 �����ж�*/


/*�������ж�ʹ�����ö���*/
#define ECD_IRQEna_None      0     /*��ʹ��*/
#define ECD_IRQEna_UnderFlow BIT0  /*ʹ�������ж�*/
#define ECD_IRQEna_OverFlow  BIT1  /*ʹ�������ж�*/

/*�������жϱ�־����*/
#define ECD0_IF_UNDERFLOW  BIT12 /*Encoder0�����ж�*/
#define ECD0_IF_OVERFLOW   BIT13 /*Encoder0�����ж�*/
#define ECD1_IF_UNDERFLOW  BIT14 /*Encoder1�����ж�*/
#define ECD1_IF_OVERFLOW   BIT15 /*Encoder1�����ж�*/

/*����ģʽ����*/
#define TIMER_CapMode_None     ((uint32_t)0x00000000)   /*�޲���*/
#define TIMER_CapMode_Rise     ((uint32_t)0x00000001)   /*�����ز���*/
#define TIMER_CapMode_Fall     ((uint32_t)0x00000002)   /*�½��ز���*/
#define TIMER_CapMode_RiseFall ((uint32_t)0x00000003)   /*˫�ز���*/

#define TIMER_OPMode_CAP ((uint32_t)0x0000001)    /*����ģʽ*/
#define TIMER_OPMode_CMP ((uint32_t)0x0000000)    /*�Ƚ�ģʽ*/


#define ECD_Mode_T1              ((uint32_t)0x00) /*counting on T1*/
#define ECD_Mode_T1_T2           ((uint32_t)0x01) /*counting on T1&T2*/
#define ECD_Mode_CCWSIGN         ((uint32_t)0x02) /*CCW+SIGN, �������ź�������*/
#define ECD_Mode_CCWCW           ((uint32_t)0x03) /*CCW+CW, �������ź�������*/
#define ECD_Mode_CCWSIGN_UpDown  ((uint32_t)0x06) /*CCW+SIGN updown, �����źŵ�������*/
#define ECD_Mode_CCWCW_UpDown    ((uint32_t)0x07) /*CCW+CW updown, �����źŵ�������*/


typedef struct
{
    uint32_t Timer_CH0_WorkMode;  /*channel0����ģʽ:����ģʽ���Ƚ�ģʽ*/
    uint32_t Timer_CH0_CapMode;   /*channel0����ģʽ:�����ء��½��ء�˫��*/
    uint32_t Timer_CH0Output;     /*����������ʱ���Ƚ�ģʽIO���*/

    uint32_t Timer_CH1_WorkMode;  /*channel1����ģʽ:����ģʽ���Ƚ�ģʽ*/
    uint32_t Timer_CH1_CapMode;   /*channel1����ģʽ:�����ء��½��ء�˫��*/
    uint32_t Timer_CH1Output;     /*����������ʱ���Ƚ�ģʽIO���*/

    uint32_t Timer_TH;            /*��ʱ����������*/
    uint32_t Timer_CMP0;          /*CH0�Ƚϼ�����ֵ*/
    uint32_t Timer_CMP1;          /*CH1�Ƚϼ�����ֵ*/

    uint32_t Timer_Filter0;    /*CH0�˲���Ƶ, 0:���˲� N:�˲����õ�ʱ����ϵͳʱ��N��Ƶ*/
    uint32_t Timer_Filter1;    /*CH1�˲���Ƶ*/

    uint32_t Timer_ClockDiv;      /*��ʱ����Ƶ*/
    uint32_t Timer_IRQEna;
} TIM_TimerInitTypeDef;

typedef struct
{
    uint32_t ECD_Mode;
    uint32_t ECD_TH;
    uint32_t ECD_ClockDiv;
    uint32_t ECD_Filter0;
    uint32_t ECD_Filter1;
    uint32_t ECD_IRQEna;
} TIM_ECDInitTypeDef;


/*Timer��ʼ��*/
void TIM_TimerInit(TIM_TimerTypeDef *TIMERx, TIM_TimerInitTypeDef *TIM_TimerInitStruct);
void TIM_TimerStrutInit(TIM_TimerInitTypeDef *TIM_TimerInitStruct);
// void TIM_StartTimer(TIM_TimerTypeDef *TIMERx);
// void TIM_StopTimer(TIM_TimerTypeDef *TIMERx);
void TIM_TimerCmd(TIM_TimerTypeDef *TIMERx, FuncState state);

/*TIM�ж����*/
uint32_t TIM_GetIRQFlag(void);
/*TIM�ж����*/
void TIM_ClearIRQFlag(uint32_t tempFlag);

uint32_t TIM_Timer_GetCount(TIM_TimerTypeDef *TIM_TIMERx);
uint32_t TIM_Timer_GetCMPT0(TIM_TimerTypeDef *TIM_TIMERx);
uint32_t TIM_Timer_GetCMPT1(TIM_TimerTypeDef *TIM_TIMERx);

/*ECD��ʼ��*/
void TIM_ECDInit(TIM_ECDTypeDef *ECDx, TIM_ECDInitTypeDef *TIM_ECDInitStruct);
void TIM_ECDStructInit(TIM_ECDInitTypeDef *TIM_ECDInitStruct);
// void TIM_StartECD(TIM_ECDTypeDef *ECDx);
// void TIM_StopECD(TIM_ECDTypeDef *ECDx);
void TIM_ECDCmd(TIM_ECDTypeDef *ECDx, FuncState state);

uint32_t TIM_ECD_GetCount(TIM_ECDTypeDef *TIM_ECDx);

#endif /*__lks32mc08x_TIM_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
