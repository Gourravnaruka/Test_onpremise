/*
 * HC_SR04.h
 *
 * Created: 07/07/2022 10:39:38 am
 *  Author: Ahmed
 */ 


#ifndef HC_SR04_H_
#define HC_SR04_H_


/*************************************************_INCLUDES_********************************************/
#include "Dio.h"
#include "HC_SR04Cfg.h"
#include "Timer0.h"
#include "ExtInt.h"
#include "Lcd.h"
#define F_CPU 16000000UL
#include <util/delay.h>

/**************************************************_MACROS_*********************************************/


/************************************************_PROTOTYPES_********************************************/

void H_HC_SR04_Init(void);
void H_HC_SR04_Trig(void);
void H_HC_SR04_Distance_Cal(void);
void H_HC_SR04_Time(void);
u32  H_HC_SR04_Distacne(void);



#endif /* HC_SR04_H_ */