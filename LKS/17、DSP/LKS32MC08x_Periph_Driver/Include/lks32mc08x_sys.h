/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_sys.h
 * �ļ���ʶ��
 * ����ժҪ�� sys����ͷ�ļ�
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
 
#ifndef __lks32mc08x_SYS_H
#define __lks32mc08x_SYS_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "basic.h"
#include "lks32mc08x_gpio.h"

typedef struct
{
	uint32_t PLL_SrcSel;                      /*PLL�ź�����Դѡ��RCʱ�ӻ��ⲿ����*/
	uint32_t PLL_DivSel;                      /*ѡ��8��ʱ�������У��ĸ��������ʱ��*/
	uint32_t PLL_ReDiv;                       /*PLL�ٷ�Ƶ��1��Ƶ��4��Ƶ*/

	uint32_t Clk_DivSPI;                      /*SPI I2Cʱ�ӷ�Ƶ*/
	uint32_t Clk_DivUART;                     /*UARTʱ�ӷ�Ƶ*/
	uint32_t Clk_FEN;                         /*ģ��ʱ��ʹ��*/

	uint32_t WDT_Ena;                         /*ʹ�ܿ��Ź�*/
	uint32_t PORFilter_Ena;                   /*ʹ��POR�˲�*/
}SYS_InitTypeDef;

/*PLL�ź�����Դѡ��*/
#define SYS_PLLSRSEL_RCH        0x00          /*ʹ��4MHz RCʱ��*/
#define SYS_PLLSRSEL_CRYSTAL    0x01          /*ʹ�þ���ʱ��*/

/*PLL�ٷ�Ƶ����*/
#define SYS_PLLREDIV_4			0x00          /*��PLL��Ƶ��������/4*/
#define SYS_PLLREDIV_1			0x01          /*��PLL��Ƶ�����ϲ��ٷ�Ƶ*/

/*SPIʱ�ӷ�Ƶ*/
#define SYS_Clk_SPIDiv1          0
#define SYS_Clk_SPIDiv2          1
#define SYS_Clk_SPIDiv4          2
#define SYS_Clk_SPIDiv8          3

/*UARTʱ�ӷ�Ƶ*/
#define SYS_Clk_UARTDiv1         0
#define SYS_Clk_UARTDiv2         1
#define SYS_Clk_UARTDiv4         2
#define SYS_Clk_UARTDiv8         3

/*����ģ��λ����*/
#define SYS_Module_I2C           BIT0
#define SYS_Module_HALL          BIT1
#define SYS_Module_TIMER         BIT2
#define SYS_Module_MCPWM         BIT3
#define SYS_Module_UART0         BIT4
#define SYS_Module_UART1         BIT5
#define SYS_Module_DSP           BIT6
#define SYS_Module_CAN           BIT7
#define SYS_Module_SPI           BIT8

/*ģ��ģ�鶨��*/
#define SYS_AnalogModule_ADC     BIT0  //ADC
#define SYS_AnalogModule_OPA0    BIT2  //OPA0
#define SYS_AnalogModule_OPA1    BIT3  //OPA1
#define SYS_AnalogModule_OPA2    BIT4  //OPA2
#define SYS_AnalogModule_OPA3    BIT5  //OPA3
#define SYS_AnalogModule_CMP0    BIT6  //CMP0
#define SYS_AnalogModule_CMP1    BIT7  //CMP1
#define SYS_AnalogModule_BGP     BIT8  //BGP
#define SYS_AnalogModule_RCH     BIT10 //RCH
#define SYS_AnalogModule_DAC     BIT12 //DAC
#define SYS_AnalogModule_TMP     BIT13 //�¶ȴ�����
#define SYS_AnalogModule_XTAL    BIT14 //����
#define SYS_AnalogModule_PLL     BIT15  //PLL

/*���Ź���ʱʱ��*/
#define SYS_WD_TimeOut2s  0         /*2s��λ*/
#define SYS_WD_TimeOut4s  1         /*4s��λ*/
#define SYS_WD_TimeOut8s 2         /*8s��λ*/
#define SYS_WD_TimeOut64s 3         /*64s��λ*/

/*��λ�ź�Դ����*/
#define SYS_RstSrc_LPOR        0x01
#define SYS_RstSrc_HPOR        0x02
#define SYS_RstSrc_KEYBOARD    0x04     /*������λ*/
#define SYS_RstSrc_WDT         0x08     /*WDT��λ*/

/*���߻��Ѽ��ʱ��*/
#define SYS_WakeInterval_025s  0x00     /*0.25s*/    
#define SYS_WakeInterval_05s   0x01     /*0.5s*/
#define SYS_WakeInterval_1s    0x02     /*1s*/
#define SYS_WakeInterval_2s    0x03     /*2s*/
#define SYS_WakeInterval_4s    0x04     /*4s*/
#define SYS_WakeInterval_8s    0x05     /*8s*/
#define SYS_WakeInterval_16s   0x06     /*16s*/
#define SYS_WakeInterval_32s   0x07     /*32s*/

/*ϵͳ����*/
void SYS_Init(SYS_InitTypeDef* SYS_InitStruct);
void SYS_StructInit(SYS_InitTypeDef* SYS_InitStruct);

/*��λԴ*/
uint32_t SYS_GetRstSource(void);
void SYS_ClearRst(void);

/*���Ź�*/
void SYS_WatchDogCmd(FuncState state);
void SYS_FeedDog(uint32_t timeOut);

/*POR�˲�*/
//void SYS_PORFilterCmd(FuncState state);

/*���ߡ�����*/
void SYS_FallSleep(void);
void SYS_SetWakeInterval(uint32_t nInterval);

/*����8·ʱ��ʹ��*/
void SYS_ModuleClockCmd(uint32_t nModule, FuncState state);

/*����ģ��ģ��ʱ��ʹ��*/
void SYS_AnalogModuleClockCmd(uint32_t nModule, FuncState state);
    
/*��λ��ģ��*/
void SYS_SoftResetModule(uint32_t nModule);

/*IAP_MODE*/
//�������IAP_MODE������λ�Ժ�

/*DSPģ���ʼ��*/
void DSP_Init(void);

#endif /*__lks32mc08x_SYS_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
