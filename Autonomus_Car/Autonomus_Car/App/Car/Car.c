/*
 * Car.c
 *
 * Created: 18/07/2022 5:43:30 pm
 *  Author: Ahmed
 */ 

#include "Car.h"


void Car_StopSpeed()
{
  H_DcMotor_StopSpeed();
}

void Car_StartSpeed(void)
{
	H_DcMotor_StartSpeed(); 
}

void Car_Forward (u8 Local_u8_Speed)
{
	
	H_DcMotor_Setspeed(Local_u8_Speed);
	H_DcMotor_SetDirection(Right_M,CLK);
	H_DcMotor_SetDirection(Left_M,ACLK);
}

void Car_Reverse (u8 Local_u8_Speed)
{
	H_DcMotor_Setspeed(Local_u8_Speed);
	H_DcMotor_SetDirection(Right_M,ACLK);
	H_DcMotor_SetDirection(Left_M,CLK);
}

void Car_Round_Right_Turn (u8 Local_u8_Speed)
{
	H_DcMotor_Setspeed(Local_u8_Speed);
	H_DcMotor_SetDirection(Right_M,ACLK);
	H_DcMotor_SetDirection(Left_M,ACLK);
}

void Car_Round_Left_Turn (u8 Local_u8_Speed)
{
	H_DcMotor_Setspeed(Local_u8_Speed);
	H_DcMotor_SetDirection(Right_M,CLK);
	H_DcMotor_SetDirection(Left_M,CLK);
}

void Car_Turn_Right (u8 Local_u8_Speed)
{
	H_DcMotor_Setspeed(Local_u8_Speed);
	H_DcMotor_SetDirection(Left_M,ACLK);
	H_DcMotor_Stop(Right_M);
}

void Car_Turn_Left (u8 Local_u8_Speed)
{
	H_DcMotor_Setspeed(Local_u8_Speed);
	H_DcMotor_SetDirection(Right_M,CLK);
	H_DcMotor_Stop(Left_M);
}

void Car_Stop (void)
{
	
	H_DcMotor_Stop(Right_M);
	H_DcMotor_Stop(Left_M);
}


// Ultrasonic direction using servo motor
void USS_Right (void)
{
	H_Servo_SetAngel(0);
}

void USS_Forward (void)
{
	H_Servo_SetAngel(90);
}

void USS_Left (void)
{
	H_Servo_SetAngel(180);
}



// Ultrasonic sensor measuring distance
u16 Measure_Distance (void)
{
	u16 Local_u16_Distance;
	H_Lcd_GoTo(1,10);
	Local_u16_Distance = H_HC_SR04_Distacne()/928;
	H_Lcd_WriteNumber(Local_u16_Distance);
	H_Lcd_WriteString(" cm");
	return Local_u16_Distance;
}
