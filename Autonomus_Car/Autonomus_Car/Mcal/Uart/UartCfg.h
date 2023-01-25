/*
 * UartCfg.h
 *
 * Created: 20/07/2022 10:57:24 pm
 *  Author: Ahmed
 */ 


#ifndef UARTCFG_H_
#define UARTCFG_H_


/*********************************_F_OSC_**********************************/

#define F_OSC                 16

/*********************************_SELECT_BAUD_RATE_**************************/
#define BAUD_RATE             9600

/*********************************_SELECT_PARITY_MODE**************************/
// option 1 -> [ PARITY_DISABLE ]
// option 2 -> [ PARITY_ODD     ]
// option 3 -> [ PARITY_EVEN ]

#define  PARITY_MODE        PARITY_DISABLE



#endif /* UARTCFG_H_ */