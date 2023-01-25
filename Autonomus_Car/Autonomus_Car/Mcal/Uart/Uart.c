/*
 * Uart.c
 *
 * Created: 20/07/2022 10:57:42 pm
 *  Author: Ahmed
 */ 


#include "Uart.h"

void M_Uart_Init(void)
{
	ClrBit(DDRD,0);    // to enable input circuit for Rx pin
	SetBit(DDRD,1);    // to enable output circuit for Tx pin
	
	u8  Local_u8_UCSRC  = 0b10000000;
	u16 Local_u16_UBRRH = 0b00000000;
	
	// to select character size  = 8b bits
	SetBit(Local_u8_UCSRC,1);
	SetBit(Local_u8_UCSRC,2);
	ClrBit(UCSRB,2);
	
	// to select asynch. mode
	ClrBit(Local_u8_UCSRC,6);
	
	#if         PARITY_MODE  == PARITY_DISABLE
	ClrBit(Local_u8_UCSRC,4);
	ClrBit(Local_u8_UCSRC,5);
	#elif       PARITY_MODE  == PARITY_ODD
	SetBit(Local_u8_UCSRC,4);
	SetBit(Local_u8_UCSRC,5);
	#elif       PARITY_MODE  == PARITY_EVEN
	ClrBit(Local_u8_UCSRC,4);
	SetBit(Local_u8_UCSRC,5);
	#endif
	
	ClrBit(Local_u8_UCSRC,3);  // to select stop bit  -> 1 bit
	UCSRC = Local_u8_UCSRC;
	// to select the baud rate
	UBRRL = ((u32)F_OSC * 1000000 / ((u32)16 * BAUD_RATE)) - 1;
	Local_u16_UBRRH = (((u32)F_OSC * 1000000 / ((u32)16 * BAUD_RATE)) - 1 )>>8;
	UBRRH = Local_u16_UBRRH;
	
	SetBit(UCSRB,4);  // to enable rx. circuit
	SetBit(UCSRB,3);  // to enable tx. circuit
}

void M_Uart_Transmit(u8 Local_u8_Data)
{
	UDR = Local_u8_Data;
	while (GetBit(UCSRA,6) == 0); // lock in this loop until transmit is finished
}

u8   M_Uart_Rec(void)
{
	while (GetBit(UCSRA,7) == 0);  // lock in this loop until receive is finished
	return UDR;
}