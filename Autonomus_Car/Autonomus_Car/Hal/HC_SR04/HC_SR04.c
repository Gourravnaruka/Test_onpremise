/* * HC_SR04.c
 *
 * Created: 07/07/2022 10:39:59 am
 *  Author: Ahmed
 */ 

#include "HC_SR04.h"


u8  Sensor_Operation = 0;
u32 Timer_Counter = 0;
u32 Pulses;
u8  Rising_Edge = 0;  

void H_HC_SR04_Init(void)
{
	M_Dio_PinMode(Ultrasonic_Trig,OUTPUT);
	M_Dio_PinMode(Ultrasoinc_Echo,INPUT);
	M_Dio_PinPullUpRes(Ultrasoinc_Echo,DISABLE);
	
	M_ExtInt_Int0Init();
	M_Timer0_Init();
	M_ExtInt_SetCallBack(H_HC_SR04_Distance_Cal);
    M_Timer0_SetCallBack(H_HC_SR04_Time);
}

void H_HC_SR04_Trig(void)
{
	if (!Sensor_Operation)
	{
		M_Dio_PinWrite(Ultrasonic_Trig,LOW);
		_delay_us(5);
		M_Dio_PinWrite(Ultrasonic_Trig,HIGH);
		_delay_us(10);
		M_Dio_PinWrite(Ultrasonic_Trig,LOW);
		_delay_us(10);
		Sensor_Operation = 1;	
	}
} 

u32  H_HC_SR04_Distacne(void)
{
	H_HC_SR04_Trig();
	_delay_ms(5);
	return Pulses;
}


// This function executed at External Interrupt (ECHO)
void  H_HC_SR04_Distance_Cal(void)
{
  if (Sensor_Operation == 1)
	{
		if (Rising_Edge == 0)  // change from low to high 
		{
			M_Timer0_Start();
			Rising_Edge = 1;	
		}
		else
		//if (Rising_Edge == 1)  // change from high to low
		{
			Pulses = (Timer_Counter * 256) + TCNT0;
			M_Timer0_Stop();
			Timer_Counter = 0;
			Rising_Edge = 0;
			TCNT0 = 0;
			Sensor_Operation = 0;
		}
	}
}

// This function executed at Timer 0 overflow interrupt 
void H_HC_SR04_Time(void)
{
	Timer_Counter++;
	if (Timer_Counter > 1450)   // case MC 8MHz 730, case 16MHz 1450
	{
	  TCNT0 = 0x00;
	  Sensor_Operation = 0;
	  Rising_Edge = 0;
	  Timer_Counter = 0;
	}
}

