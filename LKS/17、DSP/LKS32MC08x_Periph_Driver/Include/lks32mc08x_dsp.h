/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_dsp.h
 * �ļ���ʶ��
 * ����ժҪ�� DSP����ͷ�ļ�
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
 
#ifndef __lks32mc08x_DSP_H
#define __lks32mc08x_DSP_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc081.h"
#include "basic.h"

/*DSPʹ�ܺ͹ر�*/
void DSP_Cmd(FuncState state);

/*DSP��������*/
void DSP_CalcDivision(uint32_t nDID, uint32_t nDIS);
/*DSP��������*/
void DSP_CalcSquare(uint32_t nRAD);

/*DSPȡ����*/
uint32_t DSP_GetQuo(void);
/*DSPȡ������*/
uint32_t DSP_GetRem(void);
/*DSPȡ�ÿ�����*/
uint32_t DSP_GetSqrt(void);

/*��0�����־*/
uint32_t DSP_DIS0Error(void);

#endif /*__lks32mc08x_DSP_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
