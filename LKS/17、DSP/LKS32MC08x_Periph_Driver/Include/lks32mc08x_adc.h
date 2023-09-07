/*******************************************************************************
 * ��Ȩ���� (C)2018, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_adc.h
 * �ļ���ʶ��
 * ����ժҪ�� ADC������������ͷ�ļ�
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� William Zhang
 * ������ڣ� 2018��25��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�2018��7��25��
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�William Zhang
 * �޸����ݣ�����
 *
 * �޸ļ�¼��
 * �޸����ڣ�
 * �� �� �ţ�
 * �� �� �ˣ�
 * �޸����ݣ�
 *
 *******************************************************************************/

#ifndef _CONNIE_ADC_H_
#define _CONNIE_ADC_H_


/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "basic.h"

typedef struct
{
    __IO uint32_t DAT0;
    __IO uint32_t DAT1;
    __IO uint32_t DAT2;
    __IO uint32_t DAT3;
    __IO uint32_t DAT4;
    __IO uint32_t DAT5;
    __IO uint32_t DAT6;
    __IO uint32_t DAT7;
    __IO uint32_t DAT8;
    __IO uint32_t DAT9;
    __IO uint32_t DAT10;
    __IO uint32_t DAT11;
    __IO uint32_t DAT12;
    __IO uint32_t DAT13;
    __IO uint32_t DAT14;
    __IO uint32_t DAT15;
    __IO uint32_t DAT16;
    __IO uint32_t DAT17;
    __IO uint32_t DAT18;
    __IO uint32_t DAT19;

    __IO uint32_t CHN0;
    __IO uint32_t CHN1;
    __IO uint32_t CHN2;
    __IO uint32_t CHN3;
    __IO uint32_t CHN4;
    __IO uint32_t CHN5;
    __IO uint32_t CHN6;
    __IO uint32_t CHN7;
    __IO uint32_t CHN8;
    __IO uint32_t CHN9;

    __IO uint32_t CHNT0;
    __IO uint32_t CHNT1;
    __IO uint32_t SD0;
    __IO uint32_t SD1;
    __IO uint32_t GAIN_0;
    __IO uint32_t GAIN_1;
    __IO uint32_t DC_A0;
    __IO uint32_t DC_A1;
    __IO uint32_t AMC_A0;
    __IO uint32_t AMC_A1;
    __IO uint32_t DC_B0;
    __IO uint32_t DC_B1;
    __IO uint32_t AMC_B0;
    __IO uint32_t AMC_B1;

    __IO uint32_t IE;
    __IO uint32_t IF;
    __IO uint32_t CFG;
    __IO uint32_t TRG;
    __IO uint32_t SWT;
    __IO uint32_t DAT0_TH;
} ADC_TypeDef;

typedef struct
{
    uint16_t IE;                           /* Configures ADC_IRQ */
    uint16_t Align;                        /* Configures ADC Result Align */
    uint16_t Con_Sample;                   /* ��������ģʽ */
    uint16_t Trigger_Cnt;                  /* ����ģʽ�´�����һ�β�������Ĵ����¼��� */
    uint16_t FirSeg_Ch;                    /* ��һ�β�������ͨ���� */
    uint16_t SecSeg_Ch;                    /* �ڶ��β�������ͨ���� */
    uint16_t ThrSeg_Ch;                    /* �����β�������ͨ���� */
    uint16_t FouSeg_Ch;                    /* ���Ķβ�������ͨ���� */
    uint16_t Trigger_Mode;                 /* ADC trigger mode */
    uint16_t MCPWM_Trigger_En;             /* mcpwm trigger enable */
    uint16_t UTIMER_Trigger_En;            /* utimer trigger enable */
    uint16_t DAT0_TH_Type;
    uint16_t AMC0;
    uint16_t AMC1;
    uint16_t SD0;
    uint16_t SD1;
} ADC_InitTypeDef;


#define ADC_1_TIMES_SAMPLE                ((u8)1) /* ADC����ͨ����1�β��� */
#define ADC_2_TIMES_SAMPLE                ((u8)2) /* ADC����ͨ����2�β��� */
#define ADC_3_TIMES_SAMPLE                ((u8)3) /* ADC����ͨ����3�β��� */
#define ADC_4_TIMES_SAMPLE                ((u8)4)
#define ADC_5_TIMES_SAMPLE                ((u8)5)
#define ADC_6_TIMES_SAMPLE                ((u8)6)
#define ADC_7_TIMES_SAMPLE                ((u8)7)
#define ADC_8_TIMES_SAMPLE                ((u8)8)
#define ADC_9_TIMES_SAMPLE                ((u8)9)
#define ADC_10_TIMES_SAMPLE               ((u8)10)
#define ADC_11_TIMES_SAMPLE               ((u8)11)
#define ADC_12_TIMES_SAMPLE               ((u8)12)
#define ADC_13_TIMES_SAMPLE               ((u8)13)
#define ADC_14_TIMES_SAMPLE               ((u8)14)
#define ADC_15_TIMES_SAMPLE               ((u8)15)
#define ADC_16_TIMES_SAMPLE               ((u8)16)
#define ADC_17_TIMES_SAMPLE               ((u8)17)
#define ADC_18_TIMES_SAMPLE               ((u8)18)
#define ADC_19_TIMES_SAMPLE               ((u8)19)
#define ADC_20_TIMES_SAMPLE               ((u8)20) /* ADC����ͨ����20�β��� */

#define ADC_EOS0_IRQ_EN                   ((uint16_t)0x01) /* ��һ��ɨ������ж� */
#define ADC_EOS1_IRQ_EN                   ((uint16_t)0x02) /* �ڶ���ɨ������ж� */
#define ADC_EOS2_IRQ_EN                   ((uint16_t)0x04) /* ������ɨ������ж� */
#define ADC_EOS3_IRQ_EN                   ((uint16_t)0x08) /* ���Ķ�ɨ������ж� */
#define ADC_CONFLICT_IRQ_EN               ((uint16_t)0x10) /* ���������ͻ */
#define ADC_DAT0_OV_IRQ_EN                ((uint16_t)0x40) /* ADC_DAT0����ֵ�ж� */

#define ADC_CONFLICT_IRQ_IF               ((uint16_t)0x10) /* ���������ͻ��־ */
#define ADC_EOS3_IRQ_IF                   ((uint16_t)0x08) /* ͨ��ȫ��ɨ�������־ */
#define ADC_EOS2_IRQ_IF                   ((uint16_t)0x04) /* ͨ��ȫ��ɨ�������־ */
#define ADC_EOS1_IRQ_IF                   ((uint16_t)0x02) /* ͨ��ȫ��ɨ�������־ */
#define ADC_EOS0_IRQ_IF                   ((uint16_t)0x01) /* ��һ��ɨ������жϱ�־ */
#define ADC_DAT0_OV_IRQ_IF                ((uint16_t)0x40) /* ADC_DAT0����ֵ�ж� */

#define ADC_LEFT_ALIGN                    ((uint16_t)0x0000) /* ADC������������ */
#define ADC_RIGHT_ALIGN                   ((uint16_t)0x0001) /* ADC��������Ҷ��� */

#define ADC_DAT0_HTH                      ((uint16_t)0x0001) /* ADC_DAT0_TH��Ϊ����ֵ */
#define ADC_DAT0_LTH                      ((uint16_t)0x0000) /* ADC_DAT0_TH��Ϊ����ֵ */

#define ADC_MCPWM_T0_TRG                  ((uint16_t)0x01)   /* ADC����MCPWM T0�¼����� */
#define ADC_MCPWM_T1_TRG                  ((uint16_t)0x02)   /* ADC����MCPWM T1�¼����� */
#define ADC_MCPWM_T2_TRG                  ((uint16_t)0x04)   /* ADC����MCPWM T2�¼����� */
#define ADC_MCPWM_T3_TRG                  ((uint16_t)0x08)   /* ADC����MCPWM T3�¼����� */
#define ADC_UTIMER_T0_TRG                 ((uint16_t)0x01)   /* ADC����UTIMER T0�¼����� */
#define ADC_UTIMER_T1_TRG                 ((uint16_t)0x02)   /* ADC����UTIMER T1�¼����� */
#define ADC_UTIMER_T2_TRG                 ((uint16_t)0x04)   /* ADC����UTIMER T2�¼����� */
#define ADC_UTIMER_T3_TRG                 ((uint16_t)0x08)   /* ADC����UTIMER T3�¼����� */


#define ADC_1SEG_TRG                      ((uint16_t)0x00)   /* ADC���õ���ģʽ */
#define ADC_2SEG_TRG                      ((uint16_t)0x01)   /* ADC����2��ģʽ */
#define ADC_4SEG_TRG                      ((uint16_t)0x03)   /* ADC����4��ģʽ */

#define ADC_CHANNEL_0                     ((uint16_t)0x00)   /* ADCͨ��0 */
#define ADC_CHANNEL_1                     ((uint16_t)0x01)   /* ADCͨ��1 */
#define ADC_CHANNEL_2                     ((uint16_t)0x02)   /* ADCͨ��2 */
#define ADC_CHANNEL_3                     ((uint16_t)0x03)   /* ADCͨ��3 */
#define ADC_CHANNEL_4                     ((uint16_t)0x04)   /* ADCͨ��4 */
#define ADC_CHANNEL_5                     ((uint16_t)0x05)   /* ADCͨ��5 */
#define ADC_CHANNEL_6                     ((uint16_t)0x06)   /* ADCͨ��6 */
#define ADC_CHANNEL_7                     ((uint16_t)0x07)   /* ADCͨ��7 */
#define ADC_CHANNEL_8                     ((uint16_t)0x08)   /* ADCͨ��8 */
#define ADC_CHANNEL_9                     ((uint16_t)0x09)   /* ADCͨ��9 */
#define ADC_CHANNEL_10                    ((uint16_t)0x0a)   /* ADCͨ��10 */
#define ADC_CHANNEL_11                    ((uint16_t)0x0b)   /* ADCͨ��11 */
#define ADC_CHANNEL_12                    ((uint16_t)0x0c)   /* ADCͨ��11 */
#define ADC_CHANNEL_13                    ((uint16_t)0x0d)   /* ADCͨ��11 */
#define ADC_CHANNEL_14                    ((uint16_t)0x0e)   /* ADCͨ��11 */
#define ADC_CHANNEL_15                    ((uint16_t)0x0f)   /* ADCͨ��11 */
#define ADC_CHANNEL_16                    ((uint16_t)0x10)   /* ADCͨ��11 */
#define ADC_CHANNEL_17                    ((uint16_t)0x11)   /* ADCͨ��11 */
#define ADC_CHANNEL_18                    ((uint16_t)0x12)   /* ADCͨ��11 */
#define ADC_CHANNEL_19                    ((uint16_t)0x13)   /* ADCͨ��11 */


#define ADC_HARDWARE_T0_TRG               ((uint16_t)0x01)   /* ADC����Ӳ��T0�¼����� */
#define ADC_HARDWARE_T1_TRG               ((uint16_t)0x02)   /* ADC����Ӳ��T1�¼����� */
#define ADC_HARDWARE_T2_TRG               ((uint16_t)0x04)   /* ADC����Ӳ��T2�¼����� */
#define ADC_HARDWARE_T3_TRG               ((uint16_t)0x08)   /* ADC����Ӳ��T3�¼����� */

void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);

#endif /*_CONNIE_ADC_H_ */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
