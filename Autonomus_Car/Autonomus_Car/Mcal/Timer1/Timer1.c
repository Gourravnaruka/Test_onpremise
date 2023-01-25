/*
 * Timer1.c
 *
 * Created: 06/07/2022 11:45:27 pm
 *  Author: Ahmed
 */ 

#include "Timer1.h"

void M_Timer1_Pwm1Init(void)
{
	SetBit(DDRD,5);  // to make PD5 as output
	
	// to select mode no 14 in table 47. fast PWM , top ICR1
	ClrBit(TCCR1A,0);
	SetBit(TCCR1A,1);
	SetBit(TCCR1B,3);
	SetBit(TCCR1B,4);
	
	// to select non inverted mode and generate PWM at OC1A pin
	ClrBit(TCCR1A,6);
	SetBit(TCCR1A,7);
	
}

void M_Timer1_Pwm1SetFrequancy(u32 Local_u32_Frequancy)
{
	ICR1  = (((F_OSC * 1000000) / TIMER1_PRESCALER )  / Local_u32_Frequancy) - 1 ;
}

void M_Timer1_Pwm1SetDutyCycle(u8 Local_u8_DutyCycle)
{
	OCR1A = ((Local_u8_DutyCycle * ICR1 ) / 100) + 2 ;
}

void M_Timer1_Pwm1Start(void)
{
	#if     TIMER1_PRESCALER  == 1
	SetBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	ClrBit(TCCR1B,2);
	#elif   TIMER1_PRESCALER  == 8
	ClrBit(TCCR1B,0);
	SetBit(TCCR1B,1);
	ClrBit(TCCR1B,2);
	#elif   TIMER1_PRESCALER  == 64
	SetBit(TCCR1B,0);
	SetBit(TCCR1B,1);
	ClrBit(TCCR1B,2);
	#elif   TIMER1_PRESCALER  == 256
	ClrBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	SetBit(TCCR1B,2);
	#elif   TIMER1_PRESCALER  == 1024
	SetBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	SetBit(TCCR1B,2); 
	#endif
}

void M_Timer1_Pwm1Stop(void)
{
	ClrBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	ClrBit(TCCR1B,2);
}