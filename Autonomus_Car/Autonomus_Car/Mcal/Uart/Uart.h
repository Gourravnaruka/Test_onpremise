/*
 * Uart.h
 *
 * Created: 20/07/2022 10:57:34 pm
 *  Author: Ahmed
 */ 


#ifndef UART_H_
#define UART_H_


/*************************************************_INCLUDES_********************************************/

#include "UartCfg.h"
#include "StdTypes.h"
#include "Reg.h"
#include "BitMath.h"

/**************************************************_MACROS_*********************************************/

#define  PARITY_DISABLE  1
#define  PARITY_ODD      2
#define  PARITY_EVEN     3


/************************************************_PROTOTYPES_********************************************/

void M_Uart_Init(void);
void M_Uart_Transmit(u8);
u8   M_Uart_Rec(void);



#endif /* UART_H_ */