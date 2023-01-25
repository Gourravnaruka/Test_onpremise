/*
 * Servo.c
 *
 * Created: 14/07/2022 10:12:10 am
 *  Author: Ahmed
 */ 


#include "Servo.h"

void H_Servo_Init(void)
{
	M_Timer1_Pwm1Init();
	M_Timer1_Pwm1SetFrequancy(50);
}

void H_Servo_SetAngel(u8 Local_u8_Angel)
{
	u8 Local_u8_ServoDutyCycle;
	
	Local_u8_ServoDutyCycle = ((Local_u8_Angel * 5 )/180) + 5;
	
	M_Timer1_Pwm1SetDutyCycle(Local_u8_ServoDutyCycle);
}

void H_Servo_Start(void)
{
	M_Timer1_Pwm1Start();
}

void H_Servo_Stop(void)
{
	M_Timer1_Pwm1Stop();
}