/*******************************************************************************
 * ��Ȩ���� (C)2018, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_cmp.h
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
#include "lks32mc08x.h"
#include "basic.h"

typedef struct
{

    uint8_t CMP0_SELN;                    /* �Ƚ���0�������ź�ѡ�� */
    uint8_t CMP1_SELN;                    /* �Ƚ���1�������ź�ѡ�� */
    uint8_t CMP_HYS;                      /* �Ƚ�����ͷѡ�� */
    uint8_t CMP0_SELP;                    /* �Ƚ���0�������ź�ѡ��  */
    uint8_t CMP1_SELP;                    /* �Ƚ���1�������ź�ѡ�� */
    uint8_t CMP_FT;                       /* �Ƚ������ٱȽ�ʹ�� */
    uint8_t CMP0_EN;                      /* �Ƚ���0ʹ�� */
    uint8_t CMP1_EN;                      /* �Ƚ���1ʹ�� */

    uint8_t CMP_FltCnt;                   /* �Ƚ����˲�ѡ�� */
    uint8_t CMP_CLK_EN;                   /* �Ƚ����ж�����ʱ�Ӵ� */
    uint8_t CMP_CNK_PRSC;                 /* �Ƚ����˲�ʱ�ӷ�Ƶ */

    uint8_t CMP0_Polarity;                /* �Ƚ���0����ѡ�� */
    uint8_t CMP1_Polarity;                /* �Ƚ���1����ѡ�� */
    uint8_t CMP0_IE;                      /* �Ƚ���0�ж�ʹ�� */
    uint8_t CMP1_IE;                      /* �Ƚ���1�ж�ʹ�� */
    uint8_t CMP0_InEnable;                /* �Ƚ���0����ѡ�� */
    uint8_t CMP1_InEnable;                /* �Ƚ���1����ѡ�� */

} CMP_InitTypeDef;

#define SELN_CMP_IN             0        /* N������ */
#define SELN_REF                1        /* N���ڲ��ο�REF���� */
#define SELN_DAC                2        /* N���ڲ�DAC���� */
#define SELN_HALL_MID           3        /* N�˷����ƹ����е����� */

#define SELP_CMP_OPA0IP         1        /* P��OPA0_IP���� */
#define SELP_CMP_OPA0OUT        2        /* P��OPA0_OUT���� */
#define SELP_CMP_OPA1OUT        3        /* P��OPA1_OUT���� */

#define SELP_CMP_OPA3IP         1        /* P��OPA3_IP���� */
#define SELP_CMP_OPA2OUT        2        /* P��OPA2_OUT���� */
#define SELP_CMP_OPA3OUT        3        /* P��OPA3_OUT���� */

#define SELP_CMP_IP0            0        /* P��IP0���� */
#define SELP_CMP_IP1            4        /* P��IP1���� */
#define SELP_CMP_IP2            5        /* P��IP2���� */
#define SELP_CMP_IP3            6        /* P��IP3���� */
#define SELP_CMP_IP4            7        /* P��IP4���� */

void Comparator_init(CMP_InitTypeDef* CMP_InitStruct);
void CMP_StructInit(CMP_InitTypeDef* CMP_InitStruct);


