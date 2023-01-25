/*
 * Dio.h
 *
 * Created: 06/07/2022 10:33:39 pm
 *  Author: Ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_

/**********Includes************/
#include "DioCfg.h"
#include "BitMath.h"
#include "Reg.h"
#include "StdTypes.h"

/**************MACROS*************/

#define OUTPUT 1
#define INPUT  2

#define HIGH 1
#define LOW 2

#define ENABLE 1
#define DISABLE 2

#define A 1
#define B 2
#define C 3
#define D 4

#define P_A0 10
#define P_A1 11
#define P_A2 12
#define P_A3 13
#define P_A4 14
#define P_A5 15
#define P_A6 16
#define P_A7 17

#define P_B0 20
#define P_B1 21
#define P_B2 22
#define P_B3 23
#define P_B4 24
#define P_B5 25
#define P_B6 26
#define P_B7 27

#define P_C0 30
#define P_C1 31
#define P_C2 32
#define P_C3 33
#define P_C4 34
#define P_C5 35
#define P_C6 36
#define P_C7 37

#define P_D0 40
#define P_D1 41
#define P_D2 42
#define P_D3 43
#define P_D4 44
#define P_D5 45
#define P_D6 46
#define P_D7 47

/***********prototypes************/
void M_Dio_PinMode (u8,u8);
void M_Dio_PinWrite (u8,u8);
void M_Dio_PinTog (u8);
u8   M_Dio_PinRead(u8);
void M_Dio_PinPullUpRes(u8,u8);

void M_Dio_PortMode(u8,u8);
void M_Dio_PortWrite(u8,u8);




#endif /* DIO_H_ */