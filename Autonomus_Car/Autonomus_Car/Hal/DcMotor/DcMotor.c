/*
 * DcMotor.c
 *
 * Created: 07/07/2022 10:30:59 am
 *  Author: Ahmed
 */ 

#include "DcMotor.h"

void H_DcMotor_Init(void)
{
	
	M_Dio_PinMode(R_DCMOTOR_PIN1,OUTPUT);
	M_Dio_PinMode(R_DCMOTOR_PIN2,OUTPUT);
	M_Dio_PinMode(L_DCMOTOR_PIN1,OUTPUT);
	M_Dio_PinMode(L_DCMOTOR_PIN2,OUTPUT);
	
	/*
	#if    Driver_Jumper   ==  Jumper_Enable
	M_Dio_PinMode(R_DCMOTORS_ENA,OUTPUT);
	M_Dio_PinMode(L_DCMOTORS_ENA,OUTPUT);
	#elif  Driver_Jumper   ==  Jumper_Disable
	
	#endif
	*/
	M_Timer2_Pwm2Init();
	 
	
}



void H_DcMotor_SetDirection(u8 Local_u8_Motor,u8 Local_u8_Direction)
{
	switch (Local_u8_Motor)
	{
		case Right_M:
		   switch (Local_u8_Direction)
		   {
			   case CLK:
			   M_Dio_PinWrite(R_DCMOTOR_PIN1,HIGH);
			   M_Dio_PinWrite(R_DCMOTOR_PIN2,LOW);
			   break;
			   
			   case ACLK:
			   M_Dio_PinWrite(R_DCMOTOR_PIN1,LOW);
			   M_Dio_PinWrite(R_DCMOTOR_PIN2,HIGH);
			   break;
			   default:  break;
		   }
		break;
		
		case Left_M:
		 switch (Local_u8_Direction)
		 {
			 case CLK:
			 M_Dio_PinWrite(L_DCMOTOR_PIN1,HIGH);
			 M_Dio_PinWrite(L_DCMOTOR_PIN2,LOW);
			 break;
			 
			 case ACLK:
			 M_Dio_PinWrite(L_DCMOTOR_PIN1,LOW);
			 M_Dio_PinWrite(L_DCMOTOR_PIN2,HIGH);
			 break;
			 
			 default:  break;
		 }
		
		break;
		
		default:   break;
	}
	
}


void H_DcMoror_On_Off(u8 Local_u8_Motor, u8 Local_u8_Mode)
{
	
	switch(Local_u8_Motor)
	{
		case Right_M:
		  switch(Local_u8_Mode)
		  {
			  case ON:
			  M_Dio_PinWrite(R_DCMOTORS_ENA,HIGH);
			  break;
			  
			  case OFF:
			  M_Dio_PinWrite(R_DCMOTORS_ENA,LOW);
			  break;
			  
			  default:  break;
		  }
		break;
	
		case Left_M:
		switch(Local_u8_Mode)
		{
			case ON:
			M_Dio_PinWrite(L_DCMOTORS_ENA,HIGH);;
			break;
			
			case OFF:
			M_Dio_PinWrite(L_DCMOTORS_ENA,LOW);
			break;
			default:  break;
		}
		
		break;
		
		default:  break;
	}
}


void H_DcMotor_Stop(u8 Local_u8_Motor)
{
	switch(Local_u8_Motor)
	{
		case Right_M:
		M_Dio_PinWrite(R_DCMOTOR_PIN1,LOW);
		M_Dio_PinWrite(R_DCMOTOR_PIN2,LOW);
		break;
		
		case Left_M:
		M_Dio_PinWrite(L_DCMOTOR_PIN1,LOW);
		M_Dio_PinWrite(L_DCMOTOR_PIN2,LOW);
		break;
		
		default:   break;
	}
	
}

void H_DcMotor_Setspeed(u8 Local_u8_Speed)
{
	M_Timer2_Pwm2SetDutyCycle(Local_u8_Speed);
}


void H_DcMotor_StartSpeed(void)
{
	M_Timer2_Pwm2Start();
}


void H_DcMoror_StopSpeed(void)
{
	M_Timer2_Pwm2Stop();
}
