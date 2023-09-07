/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_DMA.h
 * �ļ���ʶ��
 * ����ժҪ�� DMA����ͷ�ļ�
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� 
 * ������ڣ� 2020��08��1��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�2020��08��1��
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
 
#ifndef __lks32mc08x_DMA_H
#define __lks32mc08x_DMA_H

#include "lks32mc08x.h"
#include "basic.h"


typedef struct
{
    uint8_t DMA_Channel_EN;           /* DMA ͨ��ʹ��*/
    uint8_t DMA_IRQ_EN;               /* DMA �ж�ʹ�� */
    uint8_t DMA_DIR;                  /* DMA���䷽�� 0:�������ڴ棬 1:�ڴ������� */
    uint8_t DMA_CIRC;                 /* DMA����ģʽ��ѭ��ģʽ������Ч */
    uint8_t DMA_PINC;                 /* �����ַÿ�����Ƿ����,����Ч */
    uint8_t DMA_MINC;                 /* �ڴ��ַ�ڶ����Ƿ��ڵ�һ�ֵ�ַ�Ļ����ϵ���,����Ч */
    uint8_t DMA_PBTW;                 /* �������λ�� 0:byte, 1:half-word, 2:word */
    uint8_t DMA_MBTW;                 /* �ڴ����λ�� 0:byte, 1:half-word, 2:word */
    uint8_t DMA_REQ_EN;               /* ͨ�� x ����Ӳ�� DMA ����ʹ�ܣ�����Ч */
    uint16_t DMA_TIMES;               /* DMA ͨ�� x ÿ�����ݰ��˴��� 1~511 */
    uint8_t DMA_ROUND;                /* DMA ͨ�� x �������� 1~255 */
    uint32_t DMA_CPAR;                /* DMA ͨ�� x �����ַ */
    uint32_t DMA_CMAR;                /* DMA ͨ�� x �ڴ��ַ */

} DMA_InitTypeDef;

typedef struct
{
    __IO uint32_t DMA_CCR;
    __IO uint32_t DMA_CTMS;
    __IO uint32_t DMA_CPAR;
    __IO uint32_t DMA_CMAR;
} DMA_RegTypeDef;


#define DMA_TCIE                 BIT0       /* ��������ж�ʹ�ܣ�����Ч */   
#define DMA_TEIE                 BIT1       /* �����ж�ʹ�ܣ�����Ч */

#define PERI2MEMORY              0          /* �������ڴ� */
#define MEMORY2PERI              1          /* �ڴ������� */

#define DMA_BYTE_TRANS           0          /* ����λ�� 0:byte */
#define DMA_HALFWORD_TRANS       1          /* ����λ�� 1:half-word */
#define DMA_WORD_TRANS           2          /* ����λ�� 2:word */ 


#define DMA_CH0_ADC0_REQ_EN      BIT0       /* Channel_0 ADC0 DMA����ʹ�� */
#define DMA_CH0_TIMER0_REQ_EN    BIT1       /* Channel_0 TIMER0 DMA����ʹ�� */
#define DMA_CH0_TIMER1_REQ_EN    BIT2       /* Channel_0 TIMER1 DMA����ʹ�� */ 
#define DMA_CH1_SPI_RX_REQ_EN    BIT0       /* Channel_1 SPI_RX DMA����ʹ�� */
#define DMA_CH1_MCPWM_REQ_EN     BIT1       /* Channel_1 MCPWM DMA����ʹ�� */
#define DMA_CH1_TIMER2_REQ_EN    BIT2       /* Channel_1 TIMER2 DMA����ʹ�� */
#define DMA_CH2_UART0_REQ_EN     BIT0       /* Channel_2 UART0 DMA����ʹ�� */
#define DMA_CH2_SPI_TX_REQ_EN    BIT1       /* Channel_2 SPI_TX DMA����ʹ�� */
#define DMA_CH2_TIMER3_REQ_EN    BIT2       /* Channel_2 TIMER3 DMA����ʹ�� */ 
#define DMA_CH3_UART1_REQ_EN     BIT0       /* Channel_3 UART1 DMA����ʹ�� */
#define DMA_CH3_CAN_REQ_EN       BIT1       /* Channel_3 SPI_CAN DMA����ʹ�� */
#define DMA_CH3_I2C_REQ_EN       BIT2       /* Channel_3 I2X DMA����ʹ�� */


void DMA_Init(DMA_RegTypeDef *DMAx, DMA_InitTypeDef *DMAInitStruct);
void DMA_StructInit(DMA_InitTypeDef *DMAInitStruct);

#endif
