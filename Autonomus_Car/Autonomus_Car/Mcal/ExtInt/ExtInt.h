/*
 * ExtInt.h
 *
 * Created: 06/07/2022 10:50:53 pm
 *  Author: Ahmed
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_

/*************************************************_INCLUDES_********************************************/
#include "ExtIntCfg.h"
#include "BitMath.h"
#include "Reg.h"
#include "StdTypes.h"
#include <avr/interrupt.h>
/**************************************************_MACROS_*********************************************/
#define RISING_EDGE           1
#define FAILLING_EDGE         2
#define LOGICAL_CHANGE        3
#define LOW_LEVEL             4
/************************************************_PROTOTYPES_********************************************/
void M_ExtInt_Int0Init(void);
void M_ExtInt_SetCallBack(void(*)(void));




#endif /* EXTINT_H_ */