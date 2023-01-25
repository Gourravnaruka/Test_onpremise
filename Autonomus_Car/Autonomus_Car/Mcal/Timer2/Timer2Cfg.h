/*
 * Timer2Cfg.h
 *
 * Created: 19/07/2022 8:02:25 pm
 *  Author: Ahmed
 */ 


#ifndef TIMER2CFG_H_
#define TIMER2CFG_H_


/******************************************_SELECT_TIMER0_MODE_********************************************/
// option 1 -> [ NORMAL_MODE ]
// option 2 -> [ CTC_MODE    ]
#define TIMER2_MODE           NORMAL_MODE

/******************************************_SELECT_PWM_MODE_********************************************/
// option 1 -> [ FAST_PWM2 ]
// option 2 -> [ PHASE_CORRECT_PWM2    ]
#define PWM2_MODE          FAST_PWM2

/******************************************_SELECT_PHASE_CORRECT_PWM_MODE_********************************************/
// option 1 -> [ NON_INVERTED ]
// option 2 -> [ INVERSTED    ]
#define PHASE_CORRECT_PWM2_MODE         NON_INVERTED

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
#define TIMER2_PRESCALER     1024


#endif /* TIMER2CFG_H_ */