/*
 * LcdCfg.h
 *
 * Created: 07/07/2022 10:27:44 am
 *  Author: Ahmed
 */ 


#ifndef LCDCFG_H_
#define LCDCFG_H_

/****************************_SELECT_LCD_MODE_*************************/
//option1 ->  [ _8_BIT_MODE ]
//option2 ->  [ _4_BIT_MODE ]

#define LCD_MODE   _4_BIT_MODE

/****************************_SELECT_LCD_PIN_*************************/
#define LCD_DATA_PORT PORTA

#define LCD_DATA0_PIN P_A0
#define LCD_DATA1_PIN P_A1
#define LCD_DATA2_PIN P_A2
#define LCD_DATA3_PIN P_A3
#define LCD_DATA4_PIN P_A4
#define LCD_DATA5_PIN P_A5
#define LCD_DATA6_PIN P_A6
#define LCD_DATA7_PIN P_A7
#define LCD_RS_PIN    P_B1
#define LCD_RW_PIN    P_B2
#define LCD_EN_PIN    P_B3



#endif /* LCDCFG_H_ */