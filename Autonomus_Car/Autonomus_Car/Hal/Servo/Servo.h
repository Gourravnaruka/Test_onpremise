/*
 * Servo.h
 *
 * Created: 14/07/2022 10:11:52 am
 *  Author: Ahmed
 */ 


#ifndef SERVO_H_
#define SERVO_H_


/*************************************************_INCLUDES_********************************************/
#include "DcMotorCfg.h"
#include "Timer1.h"
/**************************************************_MACROS_*********************************************/


/************************************************_PROTOTYPES_********************************************/

void H_Servo_Init(void);
void H_Servo_SetAngel(u8);
void H_Servo_Start(void);
void H_Servo_Stop(void);


#endif /* SERVO_H_ */