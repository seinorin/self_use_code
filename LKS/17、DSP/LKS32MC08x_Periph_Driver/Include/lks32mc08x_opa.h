/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_opa.h
 * �ļ���ʶ��
 * ����ժҪ�� OPA����ͷ�ļ�
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
 
#ifndef __lks32mc08x_OPA_H
#define __lks32mc08x_OPA_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc081.h"
#include "basic.h"

typedef enum
{
   OPA0 = 0,
   OPA1 = 1,
   OPA2 = 2,
   OPA3 = 3,
}enumOPA;

typedef struct
{
   uint32_t OPA_Gain;       /*�˷űջ�����*/
   uint32_t OPA_CLEna;      /*�˷űջ�ʹ��:Enable,Disable*/
}OPA_InitTypeDef;

/* ------------------------------PGA������ض��� ------------------------------ */
#define PGA_GAIN_20                    0x00                   /* ��������200:10 */
#define PGA_GAIN_9P5                   0x01                   /* ��������190:20 */
#define PGA_GAIN_6                     0x02                   /* ��������180:30 */
#define PGA_GAIN_4P25                  0x03                   /* ��������170:40 */                                                                                 

void OPA_Init(enumOPA opa, OPA_InitTypeDef* OPA_InitStruct);
void OPA_StructInit(OPA_InitTypeDef* OPA_InitStruct);
void OPA_OUT(enumOPA opa, FuncState state);

#endif /*__lks32mc08x_OPA_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
