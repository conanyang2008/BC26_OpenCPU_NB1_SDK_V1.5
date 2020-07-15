/*
*********************************************************************************************************
*
*	ģ������ : ���������ģ��
*	�ļ����� : bsp_motor.h
*	˵    �� : ͷ�ļ�
*
*	Copyright (C), 2015-2020, �������
*
*********************************************************************************************************
*/

#ifndef __BSP_MOTOR_H
#define __BSP_MOTOR_H

typedef struct 
{
	u8  ucEnalbe;
	u8  ucState;
	u16 usRunTime;
	u16 usStopTime;
	u16 usCycle;
	u16 usCount;
	u16 usCycleCount;
}MOTOR_T;

/* ���ⲿ���õĺ������� */
void Motor_InitHard(void);
void Motor_Start(u16 _usRunTime, u16 _usStopTime, u16 _usCycle);
void Motor_Stop(void);
void Motor_Pro(void);

#endif
/*********************************** ������� (END OF FILE) ********************************************/

