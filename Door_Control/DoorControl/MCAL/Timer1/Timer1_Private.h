/*
 * Timer1_Private.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_

#define Timer1_Normal_Mode		1
#define Timer1_CTC_Mode			2
#define Timer1_Mode_14			3
#define Timer1_Mode_15			4

#define Timer1_No_Prescalling			1
#define Timer1_Prescalling_8			2
#define Timer1_Prescalling_64			3
#define Timer1_Prescalling_265			4
#define Timer1_Prescalling_1024			5
#define Timer1_External_Clk_Fallling	6
#define Timer1_External_Clk_Rising		7

#define Timer1_OverFlow_Enable		0
#define Timer1_ComperMatchA_Enable	1
#define Timer1_ComperMatchB_Enable	2
#define Timer1_No_INT				3

#define Timer1_PWM_NONINVERTING		0
#define Timer1_PWM_INVERTING		1

#define TCCR1A *((volatile unsigned char * )(0x4F))
#define	WGM10	0
#define	WGM11	1
#define	FOC1B	2
#define	FOC1A	3
#define	COM1B0	4
#define	COM1B1	5
#define	COM1A0	6
#define	COM1A1	7

#define TCCR1B *((volatile unsigned char * )(0x4E))
#define	CS10	0
#define	CS11	1
#define	CS12	2
#define	WGM12	3
#define	WGM13	4
#define	ICES1	6
#define	ICNC1	7

#define TCNT1H *((volatile unsigned char * )(0x4D))
#define TCNT1L *((volatile unsigned char * )(0x4C))

#define TCNT1  *((volatile unsigned short * )(0x4C))

#define OCR1AH *((volatile unsigned char * )(0x4B))
#define OCR1AL *((volatile unsigned char * )(0x4A))

#define OCR1A *((volatile unsigned short * )(0x4A))

#define OCR1BH *((volatile unsigned char * )(0x49))
#define OCR1BL *((volatile unsigned char * )(0x48))

#define OCR1B *((volatile unsigned short * )(0x48))

#define ICR1H  *((volatile unsigned char * )(0x47))
#define ICR1L  *((volatile unsigned char * )(0x46))

#define ICR1  *((volatile unsigned short * )(0x46))

#define TIFR   *((volatile unsigned char * )(0x58))
#define TOV0 	0
#define OCF0	1

#define TOV1	2
#define OCF1B	3
#define OCF1A	4
#define ICF1	5

#define TOV2	6
#define OCF2	7

#define TIMSK  *((volatile unsigned char * )(0x59))
#define TOIE0	0
#define OCIE0	1

#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5

#define TOIE2	6
#define OCIE2	7


#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
