/*
 * DcMotorCfg.h
 *
 * Created: 07/07/2022 10:30:49 am
 *  Author: Ahmed
 */ 


#ifndef DCMOTORCFG_H_
#define DCMOTORCFG_H_

/*********************************************_SELECT_DCMOTOR_PIN_********************************************/

#define R_DCMOTOR_PIN1  P_C1
#define R_DCMOTOR_PIN2  P_C2
#define L_DCMOTOR_PIN1  P_C3
#define L_DCMOTOR_PIN2  P_C4
#define R_DCMOTORS_ENA  P_C5
#define L_DCMOTORS_ENA  P_C6   



/***********************************************_Driver_L298N_Mode********************************************/
//option1 ->  [ Jumper_Enable ]
//option2 ->  [ Jumper_Disable ]

#define Driver_Jumper   Jumper_Disable     


#endif /* DCMOTORCFG_H_ */