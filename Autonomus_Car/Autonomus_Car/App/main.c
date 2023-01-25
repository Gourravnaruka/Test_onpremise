/*
 * Autonomus_Car.c
 *
 * Created: 06/07/2022 10:20:43 pm
 * Author : Ahmed
 */ 

//#include <avr/io.h>

/*************************************************_INCLUDES_********************************************/

#include "Dio.h"
#include "Reg.h"
#include "ExtInt.h"
#include "Timer0.h"
#include "Timer1.h"
#include "Lcd.h"
#include "HC_SR04.h"
#include "Car.h"
#include "Uart.h"

#define F_CPU 16000000UL
#include <util/delay.h>

/**************************************************_MACROS_*********************************************/

#define  Left      0
#define  Right     1
#define  TurnRound 2 
#define  RC        1
#define  AUTO      0
/************************************************_PROTOTYPES_********************************************/
void Autonomus (void);
u8 Check_Direction(void);
void Remote_Control(u8, u8);

u8  Bluetooth;
u8  Car_Mode;
u8  Stop_Distance = 50;
u16 Distance;
u8  Turn_Direction;
u8  Speed = 40;
u8  Turn_Speed = 50;
u8  Manual_Speed;

int main(void)
{
    H_DcMotor_Init();
	H_Lcd_Init();
    H_HC_SR04_Init();
	H_Servo_Init();
	H_Servo_Start();
	H_Lcd_Clr();
	Car_StartSpeed();
	M_Uart_Init();
	M_Dio_PinMode(P_B0,INPUT);
    while (1) 
    {
		Car_Mode = M_Dio_PinRead(P_B0);
		//Bluetooth = M_Uart_Rec();
		//H_Lcd_GoTo(0,0);
		//H_Lcd_WriteCharacter(Bluetooth);
		//H_Lcd_Clr();
		H_Lcd_GoTo(1,0);
		H_Lcd_WriteNumber(Car_Mode);
		
		// Manual Mode
	     while (1 )  //Car_Mode == RC
		{
			H_Lcd_GoTo(0,0);
			H_Lcd_WriteString("     Manual     ");
			Bluetooth = M_Uart_Rec();
			//H_Lcd_GoTo(1,0);
			//H_Lcd_WriteString("            ");
			
			if (Bluetooth >= 48 && Bluetooth <= 57)
			{
				Manual_Speed = (Bluetooth - 48)*10;
			    H_Lcd_GoTo(1,8);
				H_Lcd_WriteString("speed:");
				H_Lcd_WriteNumber(Manual_Speed);	
			}
			Remote_Control(Manual_Speed,Bluetooth);
			Car_Mode = M_Dio_PinRead(P_B0);
			if (Car_Mode == AUTO)break;
		}
		
		H_Lcd_Clr();
		
		//  Autonomous Mode
		while (1)  //Car_Mode == AUTO
		{
			//H_Lcd_Clr();
			H_Lcd_GoTo(0,0);
			H_Lcd_WriteString("   Autonomous   ");
			H_Lcd_GoTo(1,0);
			H_Lcd_WriteString("Distance= ");
			H_Lcd_GoTo(1,11);
			H_Lcd_WriteCharacter(Bluetooth);
			Autonomus();
			Car_Mode = M_Dio_PinRead(P_B0);
			if (Car_Mode == RC)break;
		}	   		
    }	
}



u8 Check_Direction(void)
{
  u8 Distances [2] = {0,0};
  u8 Local_u8_TurnDirection;	
  
  // measure the distance from obstacle in left direction
  USS_Left();     
  _delay_ms(500);
  Distances[0] = Measure_Distance();
  _delay_ms(200);
  
  // measure the distance form obstacle in right direction 
  USS_Right(); 
  _delay_ms(500); 
  Distances[1] = Measure_Distance();
  _delay_ms(200);
  
  //
  if (Distances[0] >= 200 && Distances[1]>=200)    // if both direction are clear turn right
    Local_u8_TurnDirection = Right;
  else if (Distances[0] <= Stop_Distance && Distances[1]<= Stop_Distance)   // if both direction are blocked turn around
    Local_u8_TurnDirection = TurnRound;
  else if (Distances[0] >= Distances[1])  // if left direction is clear turn left
	Local_u8_TurnDirection = Left;
  else if (Distances[0]< Distances[1] )   // if right direction is clear turn right
	Local_u8_TurnDirection = Right;
	
	return Local_u8_TurnDirection;
}



void Remote_Control (u8 Local_u8_speed, u8 control)
{
	switch (control)
	{
	  case 'F':
	  Car_Forward(Local_u8_speed);
	  H_Lcd_GoTo(1,0);
	  H_Lcd_WriteString("Forward         ");
	  break;
	  
	  case 'B':
	  Car_Reverse(Local_u8_speed);
	  H_Lcd_GoTo(1,0);
	  H_Lcd_WriteString("Backward        ");
	  break;
	  
	  case 'L':
	  Car_Round_Left_Turn(Local_u8_speed);
	  H_Lcd_GoTo(1,0);
	  H_Lcd_WriteString("Round Left      ");
	  break;
	  
	  case 'R':
	  Car_Round_Right_Turn(Local_u8_speed);
	  H_Lcd_GoTo(1,0);
	  H_Lcd_WriteString("Round Right     ");
	  break;
	  
	  case 'I':
	  Car_Turn_Right(Local_u8_speed);
	  H_Lcd_GoTo(1,0); 
	  H_Lcd_WriteString("Turning Right   ");
	  break;	
	  
	  case 'G':
	  Car_Turn_Left(Local_u8_speed);
	  H_Lcd_GoTo(1,0);
	  H_Lcd_WriteString("Turning Left    ");
	  break;
	  
	  default:
	  Car_Stop();
	  H_Lcd_GoTo(1,0);
	  H_Lcd_WriteString("      Stop       ");
	  break;
	}
}


void Autonomus (void)
{
	USS_Forward();
	_delay_ms(700);
	Distance = Measure_Distance();
	if (Distance >= Stop_Distance)
	{
		Car_Forward(Speed);
	}
	
	while (Distance >= Stop_Distance)
	{
		Distance = Measure_Distance();
		Car_Mode = M_Dio_PinRead(P_B0);
		if(Car_Mode == RC)break;	
	}
	

	Car_Stop();
	Turn_Direction = Check_Direction();
	
	switch(Turn_Direction)
	{
		case Left:
		Car_Round_Left_Turn(Turn_Speed);
		_delay_ms(430);
		Car_Stop();
		USS_Forward();
		break;
		
		case Right:
		Car_Round_Right_Turn(Turn_Speed);
		_delay_ms(430);
		Car_Stop();
		USS_Forward();
		break;
		
		case TurnRound:
		Car_Round_Right_Turn(Turn_Speed);
		_delay_ms(580);
		Car_Stop();
		USS_Forward();
		break;
		
		default:  break;
	}
_delay_ms(50);	
	
}
