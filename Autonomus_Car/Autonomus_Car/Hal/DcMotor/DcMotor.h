/*
 * DcMotor.h
 *
 * Created: 07/07/2022 10:30:36 am
 *  Author: Ahmed
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_


/*************************************************_INCLUDES_********************************************/
#include "DcMotorCfg.h"
#include "Dio.h"
#include "Timer2.h"

/**************************************************_MACROS_*********************************************/

#define CLK      1
#define ACLK     2

#define Right_M  3
#define Left_M   4

#define ON   1
#define OFF  0

#define Jumper_Enable   1
#define Jumper_Disable  0  
/************************************************_PROTOTYPES_********************************************/

void H_DcMotor_Init(void);
void H_DcMotor_SetDirection(u8,u8);
void H_DcMotor_Setspeed(u8);
void H_DcMotor_StartSpeed(void);
void H_DcMotor_StopSpeed(void);

void H_DcMotor_Stop(u8);

void H_DcMoror_On_Off(u8,u8);




#endif /* DCMOTOR_H_ */