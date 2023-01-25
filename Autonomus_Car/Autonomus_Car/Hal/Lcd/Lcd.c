/*
 * Lcd.c
 *
 * Created: 07/07/2022 10:27:53 am
 *  Author: Ahmed
 */ 


#include "Lcd.h"

// A function to initialize LCD pins
void H_Lcd_Init(void)
{
	#if  LCD_MODE  == _8_BIT_MODE
	
	M_Dio_PinMode(LCD_DATA0_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA1_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA2_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA3_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA4_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA5_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA6_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA7_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RW_PIN,OUTPUT);
	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);
	M_Dio_PinWrite(LCD_RW_PIN,LOW);	 // This statement is optional to write, by default RW it is low
	_delay_ms(1000);
	H_Lcd_WriteCommand(LCD_8_BIT_MODE);
	H_Lcd_WriteCommand(LCD_DISPLAY_ON_CURSUR_OFF);
	H_Lcd_WriteCommand(LCD_CLEAR);
	H_Lcd_WriteCommand(LCD_RETURN_HOME);
	
	#elif  LCD_MODE  == _4_BIT_MODE
	
	M_Dio_PinMode(LCD_DATA4_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA5_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA6_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA7_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RW_PIN,OUTPUT);
	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);
	M_Dio_PinWrite(LCD_RW_PIN,LOW);	 // This statement is optional to write, by default RW it is low
	_delay_ms(1000);
	H_Lcd_WriteCommand(LCD_4_BIT_MODE_1);
	H_Lcd_WriteCommand(LCD_4_BIT_MODE_2);
	H_Lcd_WriteCommand(LCD_4_BIT_MODE_3);
	H_Lcd_WriteCommand(LCD_DISPLAY_ON_CURSUR_OFF);
	H_Lcd_WriteCommand(LCD_CLEAR);
	H_Lcd_WriteCommand(LCD_RETURN_HOME);
	
	#endif
	
}

void H_Lcd_WriteCharacter(u8 Local_u8_Character)
{
	#if  LCD_MODE  == _8_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
	LCD_DATA_PORT = Local_u8_Character;
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);  // This delay for the lcd MC have time to respond to my MC
	
	#elif LCD_MODE  == _4_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
	LCD_DATA_PORT = (Local_u8_Character & 0xF0) | (LCD_DATA_PORT & 0X0F);  // send first 4 bit of data
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	LCD_DATA_PORT = (Local_u8_Character << 4) | (LCD_DATA_PORT & 0X0F);    // send the second 4 bit of data
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}

void H_Lcd_WriteCommand(u8 Local_u8_Command)
{
	#if  LCD_MODE  == _8_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,LOW);
	LCD_DATA_PORT = Local_u8_Command;
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(5);  // This delay for the lcd MC have time to respond to my MC
	
	#elif LCD_MODE  == _4_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,LOW);
	LCD_DATA_PORT = (Local_u8_Command & 0xF0) | (LCD_DATA_PORT & 0X0F);  // send first 4 bit of data
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(1);
	LCD_DATA_PORT = (Local_u8_Command << 4) | (LCD_DATA_PORT & 0X0F);    // send the second 4 bit of data
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}


void H_Lcd_WriteString(u8* Local_u8_Ptr)
{
	u8 Local_u8_Counter=0;
	while(Local_u8_Ptr[Local_u8_Counter] != NULL_)
	{
		H_Lcd_WriteCharacter(Local_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter++;
	}
	
}


void H_Lcd_WriteNumber(s32 Local_s32_Number)
{
	u8 Local_u8_Arr[10] = {0};
	s8 Local_s8_Counter = 0;
	u8 Local_u8_Digit   = 0;
	
	if(Local_s32_Number == 0)
	{
		H_Lcd_WriteCharacter('0');
	}
	else
	{
		if (Local_s32_Number < 0)
		{
			H_Lcd_WriteCharacter('-');
			Local_s32_Number = Local_s32_Number * -1;
		}
		
		while (Local_s32_Number != 0)
		{
			Local_u8_Digit = Local_s32_Number % 10;
			Local_u8_Arr[Local_s8_Counter] =  Local_u8_Digit;
			Local_s8_Counter++;
			Local_s32_Number = Local_s32_Number / 10;
		}
		Local_s8_Counter--;
		while (Local_s8_Counter >= 0)
		{
			H_Lcd_WriteCharacter(Local_u8_Arr[Local_s8_Counter] + 48);
			Local_s8_Counter--;
		}
		
	}
	
}


void H_Lcd_Clr(void)
{
	H_Lcd_WriteCommand(LCD_CLEAR);
}


void H_Lcd_GoTo(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 Local_u8_Arr[2] = {0x80, 0xC0};   // 0X80  &  0XC0 command from lcd datasheet
	H_Lcd_WriteCommand(Local_u8_Arr[Local_u8_Row] + Local_u8_Col);
}

void H_Lcd_ShiftRight(void)
{
	H_Lcd_WriteCommand(LCD_SHIFT_RIGHT );
}


void H_Lcd_ShiftLeft(void)
{
	H_Lcd_WriteCommand(LCD_SHIFT_LEFT );
}



void H_Lcd_decimal_WriteNumber(f32 Local_f32_Number)
{
	
	u32  Local_u32_intpart;
	f32  Local_f32_difference;
	u32  Local_u32_decpart;
	
	if(Local_f32_Number == 0)
	{
		H_Lcd_WriteCharacter('0');
	}
	else
	{
		if (Local_f32_Number < 0)
		{
			H_Lcd_WriteCharacter('-');
			Local_f32_Number = Local_f32_Number * -1;
		}
		
		Local_u32_intpart = (u32)Local_f32_Number;
		Local_f32_difference = Local_f32_Number - (f32)Local_u32_intpart;
		Local_u32_decpart = (u32)(Local_f32_difference * 1000.0) ;
		
		H_Lcd_WriteNumber(Local_u32_intpart);
		H_Lcd_WriteCharacter('.');
		H_Lcd_WriteNumber(Local_u32_decpart);
		
	}
	
}