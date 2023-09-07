/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� MC_type.c
 * �ļ���ʶ��
 * ����ժҪ�� ���������ؽṹ������
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� Howlet Li
 * ������ڣ� 2020��8��16��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�2020��8��16��
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�Howlet Li
 * �޸����ݣ�����
 *
 *******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MC_TYPE_H
#define __MC_TYPE_H

/* Includes ------------------------------------------------------------------*/
#include "basic.h"
#include "MC_type.h"

/* Exported types ------------------------------------------------------------*/
/*! Macro converting a signed fractional [-1,1) number into a fixed point 16-bit
 * number in the format Q1.15. */
 
#define S16FRACT_MAX                   (0.999969482421875)
#define S16FRACT_MIN                   (-1.0)

#define S32FRACT_MAX                   (0.9999999995343387126922607421875)
#define S32FRACT_MIN                   (-1.0)

#define FRAC16(x)                      ((s16) ((x) < (S16FRACT_MAX) ? ((x) >= S16FRACT_MIN ? (x)*0x8000 : 0x8000) : 0x7fff))

/*! Macro converting a signed fractional [-1,1) number into a fixed point 32-bit
 * number in the format Q1.31. */
#define FRAC32(x)                      ((s32) ((x) < (S32FRACT_MAX) ? ((x) >= S32FRACT_MIN ? (x)*0x80000000 : 0x80000000) : 0x7fffffff))

#define ABS(X)                         ( ( (X) >= 0 ) ? (X) : -(X) )

#define sat(x,ll,ul)                   ( (x) > (ul) ) ? (ul) : ( ( (x) < (ll) ) ? (ll) : (x) )


#define   _IQ15mpy(A,B)                (((s32)A*B)>>15)  /* ����Q15��ʽ��� */
#define   _IQ12mpy(A,B)                (((s32)A*B)>>12)  /* ����Q12��ʽ��� */

#define CURRENT_SAMPLE_1SHUNT          1                  /* ����������ʽΪ������������� */
#define CURRENT_SAMPLE_2SHUNT          2                  /* ����������ʽΪ˫����������� */
#define CURRENT_SAMPLE_3SHUNT          3                  /* ����������ʽΪ������������� */
#define CURRENT_SAMPLE_MOSFET          4                  /* ����������ʽΪ�������ű�MOS����������� */

#define ROTOR_HALL_SENSOR              1                  /* ���ת�Ӵ���������ΪHALL */
#define ROTOR_SENSORLESS               2                  /* ���ת�Ӵ���������ΪHALL */
#define ROTOR_HALL2SENSORLESS          3                  /* ���ת�Ӵ���������ΪHALL + �۲���Sensorless */

typedef struct
{
    s16 nAxisQ;
    s16 nAxisD;
} stru_CurrVoctorDQ;

typedef struct
{
    s16 nAlph;
    s16 nBeta;
} stru_CurrAlphBeta;

typedef struct
{
    s16 nPhaseU;
    s16 nPhaseV;
    s16 nPhaseW;
} stru_CurrPhaseUVW;


typedef struct
{
    s16 nAxisQ;
    s16 nAxisD;
} stru_VoltVoctorDQ;

typedef struct
{
    s16 nAlph;
    s16 nBeta;
} stru_VoltAlphBeta;

typedef struct
{
    s16 nPhaseU;
    s16 nPhaseV;
    s16 nPhaseW;
} stru_VoltPhaseUVW;

typedef struct
{
    s16 hCos;
    s16 hSin;
} stru_TrigComponents;


typedef struct
{
    s32 yk_1;
    u16 coef;
} stru_RC_Def;

typedef struct
{
    s16 nData0;
    u16 nData1;
} stru_Array_Def;


typedef enum
{
    IDLE       = 0,   /* ����״̬ */
    INIT       = 1,   /* ��ʼ��״̬ */
    CHARGE     = 2,   /* ���״̬ */
    ALIGN      = 3,   /* Ԥ��λ */
    OPEN_RUN   = 4,   /* ��������״̬ */
    DIR_CHECK  = 5,   /* ˳����� */
    POS_SEEK   = 6,   /* ��ʼλ�ü�� */
    RUN        = 7,   /* ��������״̬ */
    STOP       = 8,   /* ֹͣ״̬ */
    BRAKE      = 9,   /* ɲ��״̬ */
    WAIT       = 10,  /* �ȴ�״̬ */
    FAULT      = 11,  /* ����״̬ */
    SEEK_POS   = 12,  /* λ�ü��״̬ */
    HALL_RUN   = 13,  /* hall����״̬ */
    HALL_START = 15,  /* HALL��״̬ */
    HALL_LEARN = 16,  /* HALLѧϰ״̬ */  
} enum_SystStatus;

typedef enum
{
    NO_FAULT, OVER_VOLT, UNDER_VOLT
} BusV_t;



typedef struct
{
    u16 nTimeBaseFlg;        /* Timer �жϱ�ǣ�ȡֵ 0��1 */
    u8  bPWM_UpdateFlg;      /* PWM���ڸ��±�־��һ�μ��Ϊһ��PWM���� */
    u8  bTimeCnt1ms;         /* 1mS������ */
    u16 nTimeCnt10ms;        /* 10mS������ */
    u16 nTimeCnt500ms;       /* 500mS������ */
    const char* sVersion;    /* ����汾�� */
} stru_TaskSchedulerDef;


typedef struct {
    u16 cur;
    s16 curShftNum;
    u16 vol;
    s16 volShftNum;
    u16 freq;
    s16 freqShftNum;
    u16 speed;
    s16 speedShftNum;
    u16 power;
    s16 powerShftNum;
    u16 torque;
    s16 torqueShftNum;
    u16 angle;
    s16 angleShftNum;
    u16 vDc;
    s16 vDcShftNum;
} stru_TransCoef;

typedef struct
{
    s32 IPhAFilt;
    s32 IPhBFilt;
    s32 IPhCFilt;
    s32 IBusFilt;
    s32 UBusFilt;
} stru_OffsetDef; /* ƫ�ö�ȡ�ṹ�� */

typedef struct
{
    s16 nCurrentAccStep;   /* �������Ӳ��� */
    s16 nCurrentDecStep;   /* ������С���� */   
    s16 nStartCurSet;      /* ���������趨 */
    s16 nStartCurRef;      /* ���������ο� */   
    s32 wStartCurRamp;     /* ��������ֵ */
  
    s32 wOpen2CloseFreq;   /* �����бջ�Ƶ�� */
    s16 nFreqAccStep;      /* Ƶ�ʼ��ٲ��� */
    s16 nFreqDecStep;      /* Ƶ�ʼ��ٲ��� */
    s32 wRampFreqRef;      /* Ƶ������ֵ */
} stru_OpenForceRunDef; /* �Ƕȿ���ǿ�Ͻṹ�� */




/* Exported constants --------------------------------------------------------*/
#define U8_MAX     ((u8)255)
#define S8_MAX     ((s8)127)
#define S8_MIN     ((s8)-128)
#define U16_MAX    ((u16)65535u)
#define S16_MAX    ((s16)32767)
#define S16_MIN    ((s16)-32768)
#define U32_MAX    ((u32)4294967295uL)
#define S32_MAX    ((s32)2147483647)
#define S32_MIN    ((s32)-2147483648)


#define S16P80     ((s16)26213)
#define S16P65     ((s16)25000)
#define S16P50     ((s16)13000)
#define S16P95     ((s16)30000)





/**
* Not initialized pointer
*/
#define MC_NULL    (uint16_t)(0x0000u)

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MC_TYPE_H */
/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR **********************/
/* ------------------------------END OF FILE------------------------------------ */

