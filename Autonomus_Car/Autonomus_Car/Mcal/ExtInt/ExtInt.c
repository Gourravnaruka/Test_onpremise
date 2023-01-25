/*
 * ExtInt.c
 *
 * Created: 06/07/2022 10:51:19 pm
 *  Author: Ahmed
 */ 

#include "ExtInt.h"

void (*CallBack_INT)(void);

void M_ExtInt_Int0Init(void)
{
	#if    SENSE_CONTROL    ==    RISING_EDGE
	SetBit(MCUCR,0);
	SetBit(MCUCR,1);
	#elif  SENSE_CONTROL    ==    FAILLING_EDGE
	ClrBit(MCUCR,0);
	SetBit(MCUCR,1);
	#elif  SENSE_CONTROL    ==    LOGICAL_CHANGE
	SetBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#elif  SENSE_CONTROL    ==    LOW_LEVEL
	ClrBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#endif
	SetBit(GICR,6);     // to enable local  interrupt
	SetBit(SREG,7);     // to enable global interrupt
}

void M_ExtInt_SetCallBack(void (*Ptr)(void))
{
	CallBack_INT = Ptr;
}

ISR(INT0_vect)
{
	CallBack_INT();
}