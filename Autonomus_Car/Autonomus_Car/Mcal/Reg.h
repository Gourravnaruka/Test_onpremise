/*
 * Reg.h
 *
 * Created: 06/07/2022 10:23:03 pm
 *  Author: Ahmed
 */ 


#ifndef REG_H_
#define REG_H_

/*********************************************************_DIO_REGISTERS_**********************************/
#define PINA          *(volatile u8*)0x39
#define DDRA          *(volatile u8*)0x3A
#define PORTA         *(volatile u8*)0x3B
#define PINB          *(volatile u8*)0x36
#define DDRB          *(volatile u8*)0x37
#define PORTB         *(volatile u8*)0x38
#define PINC          *(volatile u8*)0x33
#define DDRC          *(volatile u8*)0x34
#define PORTC         *(volatile u8*)0x35
#define PIND          *(volatile u8*)0x30
#define DDRD          *(volatile u8*)0x31
#define PORTD         *(volatile u8*)0x32
/*********************************************************_SREG_REGISTER_**********************************/
#define SREG          *(volatile u8*)0x5F
/*******************************************************_EXT_INT_REGISTERS_**********************************/
#define MCUCR         *(volatile u8*)0x55
#define GICR          *(volatile u8*)0x5B
/*********************************************************_ADC_REGISTERS_**********************************/
#define ADMUX         *(volatile u8*)0x27
#define ADCSRA        *(volatile u8*)0x26
#define ADCL          *(volatile u8*)0x24
#define ADCH          *(volatile u8*)0x25
#define ADC_VALUE     *(volatile u16*)0x24
/*******************************************************_TIMER0_REGISTERS_**********************************/
#define TCNT0         *(volatile u8*)0x52
#define TCCR0         *(volatile u8*)0x53
#define TIMSK         *(volatile u8*)0x59
#define OCR0          *(volatile u8*)0x5C

/*******************************************************_TIMER1_REGISTERS_**********************************/
#define TCNT1         *(volatile u16*)0x4C
#define TCCR1A        *(volatile u8*)0x4F
#define TCCR1B        *(volatile u8*)0x4E
#define OCR1A         *(volatile u16*)0x4A
#define OCR1B         *(volatile u16*)0x48
#define ICR1          *(volatile u16*)0x46

/*******************************************************_WDT_REGISTERS_**********************************/

#define WDTCR         *(volatile u8*)0x41

/*******************************************************_UART_REGISTERS_**********************************/

#define UDR           *(volatile u8*)0x2C
#define UCSRA         *(volatile u8*)0x2B
#define UCSRB         *(volatile u8*)0x2A
#define UCSRC         *(volatile u8*)0x40
#define UBRRL         *(volatile u8*)0x29
#define UBRRH         *(volatile u8*)0x40

/*******************************************************_SPI_REGISTERS_**********************************/
#define SPCR         *(volatile u8*)0x2D
#define SPDR         *(volatile u8*)0x2F
#define SPSR         *(volatile u8*)0x2E

/*******************************************************_TWI_REGISTERS_**********************************/
#define TWBR         *(volatile u8*)0x20
#define TWAR         *(volatile u8*)0x22
#define TWCR         *(volatile u8*)0x56
#define TWDR         *(volatile u8*)0x23
#define TWSR         *(volatile u8*)0x21



#endif /* REG_H_ */