/*
*********************************************************************************************************
*
*	ģ������ : ��������ģ��
*	�ļ����� : bsp_key.h
*	˵    �� : ͷ�ļ�
*
*	Copyright (C), 2015-2020, ��������
*
*********************************************************************************************************
*/

#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#define KEY_COUNT    1	   		/* �������� */

/* ����Ӧ�ó���Ĺ��������������� */
#define KEY_DOWN_POWER		KEY_1_DOWN      /* ��Դ���� */
#define KEY_UP_POWER		KEY_1_UP
#define KEY_LONG_POWER		KEY_1_LONG


/* ����ID, ��Ҫ����bsp_KeyState()��������ڲ��� */
typedef enum
{
	KID_K1 = 0,	
}KEY_ID_E;

/*
	�����˲�ʱ��50ms, ��λ10ms��
	ֻ��������⵽50ms״̬�������Ϊ��Ч����������Ͱ��������¼�
	��ʹ������·����Ӳ���˲������˲�����Ҳ���Ա�֤�ɿ��ؼ�⵽�����¼�
*/
#define KEY_FILTER_TIME   5
#define KEY_LONG_TIME     100			/* ��λ10ms�� ����1�룬��Ϊ�����¼� */

/*
	ÿ��������Ӧ1��ȫ�ֵĽṹ�������
*/
typedef struct
{
	/* ������һ������ָ�룬ָ���жϰ����ַ��µĺ��� */
	u8 (*IsKeyDownFunc)(void); /* �������µ��жϺ���,1��ʾ���� */

	u8  Count;			/* �˲��������� */
	u16 LongCount;		/* ���������� */
	u16 LongTime;		/* �������³���ʱ��, 0��ʾ����ⳤ�� */
	u8  State;			/* ������ǰ״̬�����»��ǵ��� */
	u8  RepeatSpeed;	/* ������������ */
	u8  RepeatCount;	/* �������������� */
}KEY_T;

/*
	�����ֵ����, ���밴���´�����ÿ�����İ��¡�����ͳ����¼�

	�Ƽ�ʹ��enum, ����#define��ԭ��
	(1) ����������ֵ,�������˳��ʹ���뿴���������
	(2) �������ɰ����Ǳ����ֵ�ظ���
*/
typedef enum
{
	KEY_NONE = 0,			/* 0 ��ʾû�а����¼� */

	KEY_1_DOWN,				/* 1������ */
	KEY_1_UP,				/* 1������ */
	KEY_1_LONG,				/* 1������ */

}KEY_ENUM;

/* ����FIFO�õ����� */
#define KEY_FIFO_SIZE	10
typedef struct
{
	u8 Buf[KEY_FIFO_SIZE];		/* ��ֵ������ */
	u8 Read;					/* ��������ָ��1 */
	u8 Write;					/* ������дָ�� */
//	u8 Read2;					/* ��������ָ��2 */
}KEY_FIFO_T;

/* ���ⲿ���õĺ������� */
void bsp_InitKey(void);
void bsp_KeyScan(void);
u8 bsp_GetKey(void);
void bsp_ClearKey(void);

#endif

/***************************** �������� (END OF FILE) *********************************/
