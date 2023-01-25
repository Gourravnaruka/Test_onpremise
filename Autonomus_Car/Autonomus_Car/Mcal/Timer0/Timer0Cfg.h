/*
 * Timer0Cfg.h
 *
 * Created: 06/07/2022 11:14:22 pm
 *  Author: Ahmed
 */ 


#ifndef TIMER0CFG_H_
#define TIMER0CFG_H_

/******************************************_SELECT_TIMER0_MODE_********************************************/
// option 1 -> [ NORMAL_MODE ]
// option 2 -> [ CTC_MODE    ]
#define TIMER0_MODE           NORMAL_MODE

/******************************************_SELECT_PWM_MODE_********************************************/
// option 1 -> [ FST_PWM0 ]
// option 2 -> [ PHASE_CORRECT_PWM0    ]
#define PWM0_MODE          PHASE_CORRECT_PWM0

/******************************************_SELECT_PHASE_CORRECT_PWM_MODE_********************************************/
// option 1 -> [ NON_INVERTED ]
// option 2 -> [ INVERSTED    ]
#define PHASE_CORRECT_PWM0_MODE         NON_INVERTED

/******************************************_SELECT_FAST_PWM_MODE_********************************************/
// option 1 -> [ NON_INVERTED ]
// option 2 -> [ INVERSTED    ]
#define FAST_PWM_MODE                  NON_INVERTED

/*********************************************_SELECT_F_OSC_********************************************/
#define F_OSC                   16
/***************************************_SELECT_TIMER0_PRESCALER_********************************************/
// option 1 -> [ 1024 ]
// option 2 -> [ 256  ]
// option 3 -> [ 1    ]   // no prescaler
#define TIMER0_PRESCALER     1



#endif /* TIMER0CFG_H_ */