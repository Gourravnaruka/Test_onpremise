/*
 * Timer2.h
 *
 * Created: 19/07/2022 8:02:14 pm
 *  Author: Ahmed
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

/*************************************************_INCLUDES_********************************************/
#include "Timer2Cfg.h"
#include "Reg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include <avr/interrupt.h>
/**************************************************_MACROS_*********************************************/
#define NORMAL_MODE         1
#define CTC_MODE            2
#define FAST_PWM2           1
#define PHASE_CORRECT_PWM2  2
#define NON_INVERTED        1
#define INVERTED            2
/************************************************_PROTOTYPES_********************************************/
void M_Timer2_Init(void);
void M_Timer2_SetTime(u32);
void M_Timer2_Start(void);
void M_Timer2_Stop(void);
void M_Timer2_SetCallBack(void (*)(void));

void M_Timer2_Pwm2Init(void);
void M_Timer2_Pwm2SetDutyCycle(u8);
void M_Timer2_Pwm2Start(void);
void M_Timer2_Pwm2Stop(void);




#endif /* TIMER2_H_ */