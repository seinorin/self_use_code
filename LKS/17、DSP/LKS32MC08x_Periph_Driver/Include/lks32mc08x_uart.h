/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_uart.h
 * �ļ���ʶ��
 * ����ժҪ�� UART����ͷ�ļ�
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
 
#ifndef __lks32mc08x_UART_H
#define __lks32mc08x_UART_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "basic.h"

typedef enum
{
   UART_Parity_NO   = 0x00,
   UART_Parity_EVEN = 0x01,
   UART_Parity_ODD  = 0x02
}UART_ParityMode;

typedef struct
{
   __IO uint32_t CTRL;
   __IO uint32_t DIVH;
   __IO uint32_t DIVL;
   __IO uint32_t BUFF;
   __IO uint32_t ADR;
   __IO uint32_t STT;
   __IO uint32_t IE;
   __IO uint32_t IF;
	 __IO uint32_t INV;
}UART_TypeDef;

typedef struct
{
   uint32_t BaudRate;           /*������*/
   uint8_t WordLength;         /*���ݳ���*/
   uint8_t StopBits;           /*ֹͣλ����*/
   uint8_t FirstSend;          /*First bit to be sent,0:LSB 1:MSB*/
   UART_ParityMode ParityMode;  /*��żУ��,None,EVEN,ODD*/

   uint8_t MultiDropEna;       /*ʹ��Multi-drop,0:Disable 1:Enable*/
   uint8_t Bit9Value;          /*Multi-drop Masterģʽʱ,��9������λֵ*/
   uint8_t IOFlipEna;          /*ʹ��IO��ת,0:Disable 1:Enable*/

   uint16_t Match485Addr;       /*����485ͨ��ʱ��ƥ���ַ*/
   uint8_t IRQEna;             /*�ж�ʹ�ܼĴ��������庬��*/
	 uint8_t RXD_INV;            /* ���յ�ƽȡ�� */
	 uint8_t TXD_INV;            /* ���͵�ƽȡ�� */	
}UART_InitTypeDef;

#define UART_WORDLENGTH_8b                  0
#define UART_WORDLENGTH_7b                  1

#define UART_STOPBITS_1b                    0
#define UART_STOPBITS_2b                    1

#define UART_FIRSTSEND_LSB                  0
#define UART_FIRSTSEND_MSB                  1

/*�ж�ʹ�ܶ���*/
#define UART_IRQEna_SendOver                BIT0            /*ʹ�ܷ�������ж�*/
#define UART_IRQEna_RcvOver                 BIT1            /*ʹ�ܽ�������ж�*/
#define UART_IRQEna_SendBuffEmpty           BIT2            /*ʹ�ܷ��ͻ��������ж�*/
#define UART_IRQEna_StopError               BIT3            /*ʹ��ֹͣλ����*/
#define UART_IRQEna_CheckError              BIT4            /*ʹ��У�����*/
#define UART_IRQEna_TX_DMA_RE               BIT5            /*�������DMA����ʹ��*/
#define UART_IRQEna_RX_DMA_RE               BIT6            /*�������DMA����ʹ��*/
#define UART_IRQEna_TX_BUF_DMA_RE           BIT7            /*���ͻ�������DMA����ʹ��*/

/*�жϱ�־����*/
#define UART_IF_SendOver                    BIT0            /*��������ж�*/
#define UART_IF_RcvOver                     BIT1            /*��������ж�*/
#define UART_IF_SendBufEmpty                BIT2            /*���ͻ��������ж�*/
#define UART_IF_StopError                   BIT3            /*ֹͣλ����*/
#define UART_IF_CheckError                  BIT4            /*У����� */

void UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct);
void UART_StructInit(UART_InitTypeDef* UART_InitStruct);

void UART_SendData(UART_TypeDef *UARTx, uint32_t n);
uint32_t UART_ReadData(UART_TypeDef *UARTx);

void UART_SendnData(UART_TypeDef *UARTx, char *sendData, uint32_t len);
void UART_RecvnData(UART_TypeDef *UARTx, char *recvData, uint32_t maxlen);

uint32_t UART_GetIRQFlag(UART_TypeDef *UARTx);
void UART_ClearIRQFlag(UART_TypeDef *UARTx, uint32_t tempFlag);

#endif /*__lks32mc08x_UART_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
