/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� Chanhom_adc.h
 * �ļ���ʶ��
 * ����ժҪ�� ADC������������ͷ�ļ�
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� Howlet
 * ������ڣ� 2015��11��5��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�2015��11��5��
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
 
#ifndef __LKS08X_PWM_H
#define __LKS08X_PWM_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "basic.h"



typedef struct
{
    uint16_t MCPWM_PERIOD;           /* MCPWM�������*/
    uint8_t CLK_DIV;                 /* MCPWM ��Ƶϵ�� */
    uint8_t MCLK_EN;                 /* MCPWM ʱ��ʹ�ܿ��� */
    uint8_t MCPWM_Cnt_EN;            /* MCPWM ��������ʹ�ܿ��� */
    uint8_t GPIO_BKIN_Filter;        /* GPIO�����˲�ʱ������1-16 */
    uint8_t CMP_BKIN_Filter;         /* �Ƚ���CMP�����˲�ʱ������1-16 */ 
    uint16_t MCPWM_WorkModeCH0;      /* MCPWM CH0����ģʽ�����ض���/���Ķ��� */
    uint16_t MCPWM_WorkModeCH1;      /* MCPWM CH0����ģʽ�����ض���/���Ķ��� */
    uint16_t MCPWM_WorkModeCH2;      /* MCPWM CH0����ģʽ�����ض���/���Ķ��� */
    uint16_t MCPWM_WorkModeCH3;      /* MCPWM CH0����ģʽ�����ض���/���Ķ��� */	
 
    uint16_t TriggerPoint0;          /* PWM����ADC�¼�0��ʱ������� */
    uint16_t TriggerPoint1;          /* PWM����ADC�¼�1��ʱ������� */
    uint16_t TriggerPoint2;          /* PWM����ADC�¼�2��ʱ������� */
    uint16_t TriggerPoint3;          /* PWM����ADC�¼�3��ʱ������� */
 
    uint16_t DeadTimeCH0N;           /* CH0N����ʱ�����á�*/
    uint16_t DeadTimeCH0P;           /* CH0P����ʱ�����á�*/
    uint16_t DeadTimeCH1N;           /* CH1N����ʱ�����á�*/
    uint16_t DeadTimeCH1P;           /* CH1P����ʱ�����á�*/
    uint16_t DeadTimeCH2N;           /* CH2N����ʱ�����á�*/
    uint16_t DeadTimeCH2P;           /* CH2P����ʱ�����á�*/
    uint16_t DeadTimeCH3N;           /* CH3N����ʱ�����á�*/
    uint16_t DeadTimeCH3P;           /* CH3P����ʱ�����á�*/	
 
    uint8_t CH0N_Polarity_INV;       /* CH0N�������ȡ����0:���������1:ȡ����� */
    uint8_t CH0P_Polarity_INV;       /* CH0P�������ȡ����0:���������1:ȡ����� */
    uint8_t CH1N_Polarity_INV;       /* CH1N�������ȡ����0:���������1:ȡ����� */
    uint8_t CH1P_Polarity_INV;       /* CH1P�������ȡ����0:���������1:ȡ����� */
    uint8_t CH2N_Polarity_INV;       /* CH2N�������ȡ����0:���������1:ȡ����� */
    uint8_t CH2P_Polarity_INV;       /* CH2P�������ȡ����0:���������1:ȡ����� */
    uint8_t CH3N_Polarity_INV;       /* CH3N�������ȡ����0:���������1:ȡ����� */
    uint8_t CH3P_Polarity_INV;       /* CH3P�������ȡ����0:���������1:ȡ����� */	
   
    uint8_t CH0P_SCTRLP;             /* ��CH0_PS = 1ʱ�������CH0_Pͨ����ֵ*/
    uint8_t CH0N_SCTRLN;             /* ��CH0_NS = 1ʱ�������CH0_Nͨ����ֵ*/
    uint8_t CH1P_SCTRLP;             /* ��CH1_PS = 1ʱ�������CH1_Pͨ����ֵ*/
    uint8_t CH1N_SCTRLN;             /* ��CH1_NS = 1ʱ�������CH1_Nͨ����ֵ*/
    uint8_t CH2P_SCTRLP;             /* ��CH2_PS = 1ʱ�������CH2_Pͨ����ֵ*/
    uint8_t CH2N_SCTRLN;             /* ��CH2_NS = 1ʱ�������CH2_Nͨ����ֵ*/
    uint8_t CH3P_SCTRLP;             /* ��CH3_PS = 1ʱ�������CH3_Pͨ����ֵ*/
    uint8_t CH3N_SCTRLN;             /* ��CH3_NS = 1ʱ�������CH3_PNͨ����ֵ*/
   
    uint8_t Switch_CH0N_CH0P;        /* ����CH0N, CH0P�ź����ʹ�ܿ��� */
    uint8_t Switch_CH1N_CH1P;        /* ����CH1N, CH1P�ź����ʹ�ܿ��� */
    uint8_t Switch_CH2N_CH2P;        /* ����CH2N, CH2P�ź����ʹ�ܿ��� */
    uint8_t Switch_CH3N_CH3P;        /* ����CH3N, CH3P�ź����ʹ�ܿ��� */	

    uint8_t MCPWM_UpdateInterval;    /* MCPWM T0/T1�¼����¼�� */
    uint8_t MCPWM_T0_UpdateEN;       /* MCPWM T0�¼�����ʹ�� */
    uint8_t MCPWM_T1_UpdateEN;       /* MCPWM T1�¼�����ʹ�� */
    uint8_t MCPWM_Auto_ERR_EN;       /* MCPWM �����¼��Ƿ��Զ���MOE, ʹ�ܿ��� */
 
    uint8_t FAIL0_INPUT_EN;          /* FAIL0 ���빦��ʹ�� */
    uint8_t FAIL1_INPUT_EN;          /* FAIL1 ���빦��ʹ�� */	 
    uint8_t FAIL0_Signal_Sel;        /* FAIL0 �ź�ѡ�񣬱Ƚ���0��GPIO */
    uint8_t FAIL1_Signal_Sel;        /* FAIL1 �ź�ѡ�񣬱Ƚ���0��GPIO */	 
    uint8_t FAIL0_Polarity;          /* FAIL0 �źż������ã�����Ч�����Ч */	 
    uint8_t FAIL1_Polarity;          /* FAIL1 �źż������ã�����Ч�����Ч */
    uint8_t DebugMode_PWM_out;       /* Debugʱ��MCU����Halt, MCPWM�ź��Ƿ�������� */

    uint8_t CH0P_default_output;     /* CH0P MOEΪ0ʱ����FAIL�¼�ʱ��Ĭ�ϵ�ƽ��� */
    uint8_t CH0N_default_output;     /* CH0N MOEΪ0ʱ����FAIL�¼�ʱ��Ĭ�ϵ�ƽ��� */
    uint8_t CH1P_default_output;     /* CH1P MOEΪ0ʱ����FAIL�¼�ʱ��Ĭ�ϵ�ƽ��� */
    uint8_t CH1N_default_output;     /* CH1N MOEΪ0ʱ����FAIL�¼�ʱ��Ĭ�ϵ�ƽ��� */
    uint8_t CH2P_default_output;     /* CH2P MOEΪ0ʱ����FAIL�¼�ʱ��Ĭ�ϵ�ƽ��� */
    uint8_t CH2N_default_output;     /* CH2N MOEΪ0ʱ����FAIL�¼�ʱ��Ĭ�ϵ�ƽ��� */
    uint8_t CH3P_default_output;     /* CH3P MOEΪ0ʱ����FAIL�¼�ʱ��Ĭ�ϵ�ƽ��� */
    uint8_t CH3N_default_output;     /* CH3N MOEΪ0ʱ����FAIL�¼�ʱ��Ĭ�ϵ�ƽ��� */	

    uint8_t T0_Update_INT_EN;        /* T0�����¼��Д�ʹ�� */
    uint8_t T1_Update_INT_EN;        /* T1�����¼��Д�ʹ�� */  
    uint8_t TMR0_Match_INT_EN;       /* TMR0�����¼�ƥ���¼��ж�ʹ�� */    
    uint8_t TMR1_Match_INT_EN;       /* TMR1�����¼�ƥ���¼��ж�ʹ�� */    

    uint8_t FAIL0_INT_EN;            /* FAIL0�¼��ж�ʹ�� */
    uint8_t FAIL1_INT_EN;            /* FAIL1�¼��ж�ʹ�� */	 

}MCPWM_InitTypeDef;

#define MCPWM_MOE_ENABLE_MASK                     ((uint16_t)0x0040)   /* ��MOEλMASKλ */
#define MCPWM_MOE_DISABLE_MASK                    ((uint16_t)~0x0040)   /* ��MOEλMASKλ */

#define PWM_F_SELECT_CMP0    BIT0
#define PWM_F_SELECT_CMP1    BIT1
#define PWM_F_LFAIL_CH0      BIT2
#define PWM_F_LFAIL_CH1      BIT3
#define PWM_F_ENABLE_CH0     BIT4
#define PWM_F_ENABLE_CH1     BIT5

#define PWM_ENABLE_BK0IF     BIT4
#define PWM_ENABLE_BK1IF     BIT5
#define PWM_ENABLE_CMP0IF    BIT6
#define PWM_ENABLE_CMP1IF    BIT7

#define CENTRAL_PWM_MODE     0  /* ���Ķ���PWMģʽ */
#define EDGE_PWM_MODE        1  /* ���ض���PWMģʽ */

#define HIGH_LEVEL           1  /* �ߵ�ƽ */
#define LOW_LEVEL            0  /* �ߵ�ƽ */

#define HIGH_LEVEL_ACTIVE    0  /* �ߵ�ƽ��Ч */
#define LOW_LEVEL_ACTIVE     1  /* �͵�ƽ��Ч */

#define FAIL_SEL_CMP         1  /* Fail�¼���Դ�Ƚ��� */
#define FAIL_SEL_IO          0  /* Fail�¼���Դ�Ƚ��� */

#define MCPWM_UPDATE_REG()                        {MCPWM_PRT = 0x0000DEAD; MCPWM_UPDATE = 0x00ff; MCPWM_PRT = 0x0000CAFE;}

void PWMOutputs(FuncState t_state);
void MCPWM_Init(MCPWM_InitTypeDef* MCPWM_InitStruct);
void MCPWM_StructInit(MCPWM_InitTypeDef* MCPWM_InitStruct);

#endif /*__CHANHOM_PWM_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
