/*
 * Timer_Private.h
 *
 *  Created on: Jul 28, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

#define Timer0_Normal_Mode		0
#define Timer0_PWM_Mode			1
#define Timer0_CTC_Mode			2
#define Timer0_Fast_PWM_Mode	3

#define Timer0_No_Prescalling			1
#define Timer0_Prescalling_8			2
#define Timer0_Prescalling_64			3
#define Timer0_Prescalling_265			4
#define Timer0_Prescalling_1024			5
#define Timer0_External_Clk_Fallling	6
#define Timer0_External_Clk_Rising		7


#define Timer0_OverFlow_Enable		2
#define Timer0_ComperMatch_Enable	1
#define Timer0_No_INT				0


#define Timer0_Fast_PWM_NONINVERTING		0
#define Timer0_Fast_PWM_INVERTING			1


#define Timer0_Phase_Correct_PWM_NONINVERTING		0
#define Timer0_Phase_Correct_PWM_INVERTING			1

#define TCNT0 *((volatile unsigned char * )(0x52))

#define TCCR0 *((volatile unsigned char * )(0x53))
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

#define OCR0 *((volatile unsigned char * )(0x5C))

#define TIMSK *((volatile unsigned char * )(0x59))
#define TOIE0	0
#define OCIE0	1

#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5

#define TOIE2	6
#define OCIE2	7

#define TIFR *((volatile unsigned char * )(0x58))
#define TOV0 	0
#define OCF0	1

#define TOV1	2
#define OCF1B	3
#define OCF1A	4
#define ICF1	5

#define TOV2	6
#define OCF2	7

#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
