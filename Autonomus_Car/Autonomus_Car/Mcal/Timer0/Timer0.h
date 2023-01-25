/*
 * Timer0.h
 *
 * Created: 06/07/2022 11:14:11 pm
 *  Author: Ahmed
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/*************************************************_INCLUDES_********************************************/
#include "Timer0Cfg.h"
#include "Reg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include <avr/interrupt.h>
/**************************************************_MACROS_*********************************************/
#define NORMAL_MODE         1
#define CTC_MODE            2
#define FAST_PWM0           1
#define PHASE_CORRECT_PWM0  2
#define NON_INVERTED        1
#define INVERTED            2
/************************************************_PROTOTYPES_********************************************/
void M_Timer0_Init(void);
void M_Timer0_SetTime(u32);
void M_Timer0_Start(void);
void M_Timer0_Stop(void);
void M_Timer0_SetCallBack(void (*)(void));

void M_Timer0_Pwm0Init(void);
void M_Timer0_Pwm0SetDutyCycle(u8);
void M_Timer0_Pwm0Start(void);
void M_Timer0_Pwm0Stop(void);





#endif /* TIMER0_H_ */