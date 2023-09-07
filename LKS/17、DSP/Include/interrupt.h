/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� interrupt.c
 * �ļ���ʶ��
 * ����ժҪ�� �жϷ�������ļ�
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
 
#ifndef __INTERRUPT_H
#define __INTERRUPT_H

void SleepTimer_IRQHandler(void);
void GPIO_IRQHandler      (void);
void CSX_IRQHandler       (void);
void I2C0_IRQHandler      (void);

void SleepTimer_IRQHandler(void);
void GPIO_IRQHandler(void);
void VC3_IRQHandler(void);
void CSX_IRQHandler(void);
void NSX_IRQHandler(void);
void I2C0_IRQHandler(void);
void SPI0_IRQHandler(void);
void UART0_IRQHandler(void);
void UART1_IRQHandler(void);
void HALL_IRQHandler(void);
void UTIMER0_IRQHandler(void);
void UTIMER1_IRQHandler(void);
void UTIMER2_IRQHandler(void);
void UTIMER3_IRQHandler(void);
void ENCODER0_IRQHandler(void);
void ENCODER1_IRQHandler(void);
void ADC1_IRQHandler(void);
void ADC0_IRQHandler(void);
void MCPWM_IRQHandler(void);

#endif



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
