/*
 * Car.h
 *
 * Created: 18/07/2022 5:43:19 pm
 *  Author: Ahmed
 */ 


#ifndef CAR_H_
#define CAR_H_

/*************************************************_INCLUDES_********************************************/

#include "DcMotor.h"
#include "Servo.h"
#include "CarCfg.h"
#include "Lcd.h"
#include "HC_SR04.h"



/**************************************************_MACROS_*********************************************/

/************************************************_PROTOTYPES_********************************************/

void Car_StopSpeed(void);
void Car_StartSpeed(void);
void Car_Forward (u8);
void Car_Reverse (u8);
void Car_Round_Right_Turn (u8);
void Car_Round_Left_Turn (u8);
void Car_Turn_Right (u8);
void Car_Turn_Left (u8);
void Car_Stop (void);


void USS_Right (void);
void USS_Forward(void);
void USS_Left (void);

u16 Measure_Distance (void);

#endif /* CAR_H_ */