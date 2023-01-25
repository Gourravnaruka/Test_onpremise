/*
 * Timer2.c
 *
 * Created: 19/07/2022 8:02:35 pm
 *  Author: Ahmed
 */ 


#include "Timer2.h"

u32 Timer2_u32_NumOfOverFlows = 0;
u8  Timer2_u8_RemTicks        = 0;
u32 Timer2_NumOfCompareMatch  = 0;

void (*CallBack_T2)(void);

void M_Timer2_Init(void)
{
	#if   TIMER2_MODE   ==   NORMAL_MODE
	ClrBit(TCCR2,3);
	ClrBit(TCCR2,6);
	SetBit(TIMSK,6);    // to enable timer0 overflow int
	#elif TIMER2_MODE   ==   CTC_MODE
	SetBit(TCCR2,3);
	ClrBit(TCCR2,6);
	SetBit(TIMSK,7);    // to enable timer0 compare match int
	#endif
	SetBit(SREG,7);     // to enable global int
	
	ClrBit(ASSR,3);
}

void M_Timer2_SetTime(u32 Local_u8_DesiredTime)
{
	#if   TIMER2_MODE   ==   NORMAL_MODE
	u32 Local_u32_TickTime        = TIMER2_PRESCALER / F_OSC;                            // result will be in micro second
	u32 Local_u32_Total_Ticks     = (Local_u8_DesiredTime * 1000) / Local_u32_TickTime;
	Timer2_u32_NumOfOverFlows = Local_u32_Total_Ticks / 256;
	Timer2_u8_RemTicks        = Local_u32_Total_Ticks % 256;
	if(Timer2_u8_RemTicks != 0)
	{
		TCNT2                     = 256 - Timer2_u8_RemTicks;
		Timer2_u32_NumOfOverFlows++;
	}
	#elif TIMER2_MODE   ==   CTC_MODE
	u32 Local_u32_TickTime        = TIMER2_PRESCALER / F_OSC;
	u32 Local_u32_Total_Ticks     = (Local_u8_DesiredTime * 1000) / Local_u32_TickTime;
	u8  Local_u8_DevisionFactor   = 255;
	while(Local_u32_Total_Ticks % Local_u8_DevisionFactor)
	{
		Local_u8_DevisionFactor--;
	}
	Timer2_NumOfCompareMatch  = Local_u32_Total_Ticks / Local_u8_DevisionFactor;
	OCR2                          = Local_u8_DevisionFactor - 1 ;
	#endif
}

void M_Timer2_Start(void)
{
	#if   TIMER2_PRESCALER   ==   1024
	SetBit(TCCR2,0);
	SetBit(TCCR2,1);
	SetBit(TCCR2,2);
	#elif TIMER2_PRESCALER   ==   256
	ClrBit(TCCR2,0);
	SetBit(TCCR2,1);
	SetBit(TCCR2,2);
	#elif  TIMER2_PRESCALER   ==  1
	SetBit(TCCR2,0);
	ClrBit(TCCR2,1);
	ClrBit(TCCR2,2);
	#endif
}

void M_Timer2_Stop(void)
{
	ClrBit(TCCR2,0);
	ClrBit(TCCR2,1);
	ClrBit(TCCR2,2);
}

void M_Timer2_Pwm2Init(void)
{
	SetBit(DDRD,7);              // to make PD7  -> output
	// to select fast PWM mode
	
	#if       PWM2_MODE   ==    FAST_PWM2
	 SetBit(TCCR2,3);
	 SetBit(TCCR2,6);
	   #if      FAST_PWM_MODE   ==  NON_INVERTED
	   ClrBit(TCCR2,4);
	   SetBit(TCCR2,5);
	   #elif    FAST_PWM_MODE    ==  INVERTED
	   SetBit(TCCR2,4);
	   SetBit(TCCR2,5);
	   #endif
	#elif     PWM2_MODE   ==    PHASE_CORRECT_PWM2
	 ClrBit(TCCR2,3);
	 SetBit(TCCR2,6); 
	   #if      PHASE_CORRECT_PWM2_MODE   ==  NON_INVERTED
	   ClrBit(TCCR2,4);
	   SetBit(TCCR2,5);
	   #elif    PHASE_CORRECT_PWM2_MODE    ==  INVERTED
	   SetBit(TCCR2,4);
	   SetBit(TCCR2,5);
	   #endif
	#endif
}


void M_Timer2_Pwm2SetDutyCycle(u8 Local_u8_DutyCycle)
{
	#if PWM2_MODE == FAST_PWM2
	   #if FAST_PWM_MODE  == NON_INVERTED
	   OCR2 = ((Local_u8_DutyCycle * 256 ) / 100) -1;
	   #elif  FAST_PWM_MODE ==  INVERTED
	   
	   
	   #endif
	#elif  PWM2_MODE  ==   PHASE_CORRECT_PWM2
	  #if PHASE_CORRECT_PWM2_MODE  ==  NON_INVERTED
	  OCR2 = ((Local_u8_DutyCycle * 255 ) / 100);
	  #elif PHASE_CORRECT_PWM2_MODE  ==  INVERTED
	  //OCR2 = 100;
	  #endif
	
	#endif
	
}


void M_Timer2_Pwm2Start(void)
{
	M_Timer2_Start();
}

void M_Timer2_Pwm2Stop(void)
{
	M_Timer2_Stop();
}


void M_Timer2_SetCallBack(void (*Ptr)(void))
{
	CallBack_T2 = Ptr;
}

#if   TIMER2_MODE   ==   NORMAL_MODE
ISR(TIMER2_OVF_vect)
{
	static u32 Local_u32_Counter = 0;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer2_u32_NumOfOverFlows)
	{
	CallBack_T2();
	Local_u32_Counter = 0;
	TCNT2             =   256 - Timer2_u8_RemTicks;
	}
}

#elif TIMER2_MODE   ==   CTC_MODE
ISR(TIMER2_COMP_vect)
{
	static u32 Local_u32_Counter = 0;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer2_NumOfCompareMatch)
	{
		CallBack_T2();
		Local_u32_Counter = 0;
	}
}
#endif