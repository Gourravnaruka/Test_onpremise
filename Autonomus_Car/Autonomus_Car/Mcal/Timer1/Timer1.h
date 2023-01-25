/*
 * Timer1.h
 *
 * Created: 06/07/2022 11:45:05 pm
 *  Author: Ahmed
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "Timer1Cfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
/**************************************************_MACROS_*********************************************/
//#define NORMAL_MODE         1
//#define CTC_MODE            2
//#define FAST_PWM0           1
//#define PHASE_CORRECT_PWM0  2
//#define NON_INVERTED        1
//#define INVERTED            2
/************************************************_PROTOTYPES_********************************************/


void M_Timer1_Pwm1Init(void);
void M_Timer1_Pwm1SetFrequancy(u32);
void M_Timer1_Pwm1SetDutyCycle(u8);
void M_Timer1_Pwm1Start(void);
void M_Timer1_Pwm1Stop(void);






#endif /* TIMER1_H_ */