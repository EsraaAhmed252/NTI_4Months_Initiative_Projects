/*
 * Timer1_Program.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Esraa Ahmed Taha
 */
#include "Timer1_Interface.h"

static void (*p2f_1)(void) = NULL;
static void (*p2f_2)(void) = NULL;
static void (*p2f_3)(void) = NULL;

void Timer1_Init(void) {

	TCNT1 = Timer1_Init_Value;

#if Timer1_Mode == Timer1_Normal_Mode

	CLRBIT(TCCR1A,WGM10);
	CLRBIT(TCCR1A,WGM11);
	CLRBIT(TCCR1B,WGM12);
	CLRBIT(TCCR1B,WGM13);

#elif Timer1_Mode == Timer1_CTC_Mode

	CLRBIT(TCCR1A,WGM10);
	CLRBIT(TCCR1A,WGM11);
	SETBIT(TCCR1B,WGM12);
	CLRBIT(TCCR1B,WGM13);

#elif Timer1_Mode == Timer1_Mode_14

	CLRBIT(TCCR1A, WGM10);
	SETBIT(TCCR1A, WGM11);
	SETBIT(TCCR1B, WGM12);
	SETBIT(TCCR1B, WGM13);

#if Timer1_PWM_MODE == Timer1_PWM_NONINVERTING

	CLRBIT(TCCR1A, COM1A0);
	SETBIT(TCCR1A, COM1A1);

#elif Timer1_PWM_MODE == Timer1_PWM_INVERTING

	SETBIT(TCCR1A,COM1A0);
	SETBIT(TCCR1A,COM1A1);

#endif

#elif Timer1_Mode == Timer1_Mode_15

	SETBIT(TCCR1A,WGM10);
	SETBIT(TCCR1A,WGM11);
	SETBIT(TCCR1B,WGM12);
	SETBIT(TCCR1B,WGM13);

#if Timer1_PWM_MODE == Timer1_PWM_NONINVERTING

	CLRBIT(TCCR1A,COM1A0);
	SETBIT(TCCR1A,COM1A1);

#elif Timer1_PWM_MODE == Timer1_PWM_INVERTING

	SETBIT(TCCR1A,COM1A0);
	SETBIT(TCCR1A,COM1A1);

#endif

#endif

#if Timer1_Prescaler == Timer1_No_Prescalling

			//TCCR1B &= 0xF8
			//TCCR1B |= No_Prescalling
			SETBIT(TCCR1B,CS10);
			CLRBIT(TCCR1B,CS11);
			CLRBIT(TCCR1B,CS12);

#elif Timer1_Prescaler == Timer1_Prescalling_8

			CLRBIT(TCCR1B,CS10);
			SETBIT(TCCR1B,CS11);
			CLRBIT(TCCR1B,CS12);

#elif Timer1_Prescaler == Timer1_Prescalling_64

	SETBIT(TCCR1B, CS10);
	SETBIT(TCCR1B, CS11);
	CLRBIT(TCCR1B, CS12);

#elif Timer1_Prescaler == Timer1_Prescalling_265

			CLRBIT(TCCR1B,CS10);
			CLRBIT(TCCR1B,CS11);
			SETBIT(TCCR1B,CS12);

#elif Timer1_Prescaler == Timer1_Prescalling_1024

			SETBIT(TCCR1B,CS10);
			CLRBIT(TCCR1B,CS11);
			SETBIT(TCCR1B,CS12);

#elif Timer1_Prescaler == Timer1_External_Clk_Fallling

			CLRBIT(TCCR1B,CS10);
			SETBIT(TCCR1B,CS11);
			SETBIT(TCCR1B,CS12);

#elif Timer1_Prescaler == Timer1_External_Clk_Rising

			SETBIT(TCCR1B,CS10);
			SETBIT(TCCR1B,CS11);
			SETBIT(TCCR1B,CS12);
#endif

}

void Timer1_INTEnable(void) {

#if Timer0_Enable_INT == Timer1_OverFlow_Enable

	SETBIT(TIMSK, TOIE1);

#elif Timer0_Enable_INT == Timer1_ComperMatchA_Enable

	SETBIT(TIMSK,OCIE1A);

#elif Timer0_Enable_INT == Timer1_ComperMatchB_Enable

	SETBIT(TIMSK,OCIE1B);

#elif Timer0_Enable_INT == Timer1_No_INT

#endif

}

void Set_Init_Value_Timer1(UINT16 val) {

	TCNT1 = val;

}

void Set_OCR_Value_Timer1(UINT16 val) {

	OCR1A = val;

}

void Timer1_Stop(void) {

	CLRBIT(TCCR1B, CS10);
	CLRBIT(TCCR1B, CS11);
	CLRBIT(TCCR1B, CS12);

}

void Timer1_FastPWM_Mode14(float Duty, UINT16 freq) {

#if Timer1_Prescaler == Timer1_No_Prescalling

	UINT16 Per = ((1000000/freq))/0.0625;

#elif Timer1_Prescaler == Timer1_Prescalling_8

	UINT16 Per = ((1000000/freq))/0.5;

#elif Timer1_Prescaler == Timer1_Prescalling_64

	UINT16 Per = ((1000000 / freq)) / 4;

#elif Timer1_Prescaler == Timer1_Prescalling_265

	UINT16 Per = ((1000000/freq))/16;

#elif Timer1_Prescaler == Timer1_Prescalling_1024

	UINT16 Per = ((1000000/freq))/64;

#endif

	ICR1 = Per - 1;

#if Timer1_PWM_MODE == Timer1_PWM_NONINVERTING

	OCR1A = ((Duty * Per) / 100) - 1;

#elif Timer1_PWM_MODE == Timer1_PWM_INVERTING

	Duty = 100 - Duty;
	OCR1A = ((Duty * Per)/100) -1 ;

#endif

}

void Timer1_FastPWM_Mode15(float Duty, UINT16 freq) {

#if Timer1_Prescaler == Timer1_No_Prescalling

	UINT16 Per = ((1000000/freq))/0.0625;

#elif Timer1_Prescaler == Timer1_Prescalling_8

	UINT16 Per = ((1000000/freq))/0.5;

#elif Timer1_Prescaler == Timer1_Prescalling_64

	UINT16 Per = ((1000000 / freq)) / 4;

#elif Timer1_Prescaler == Timer1_Prescalling_265

	UINT16 Per = ((1000000/freq))/16;

#elif Timer1_Prescaler == Timer1_Prescalling_1024

	UINT16 Per = ((1000000/freq))/64;

#endif

	OCR1A = Per - 1;

#if Timer1_PWM_MODE == Timer1_PWM_NONINVERTING

	ICR1 = ((Duty * Per) / 100) - 1;

#elif Timer1_PWM_MODE == Timer1_PWM_INVERTING

	Duty = 100 - Duty;
	ICR1 = ((Duty * Per)/100) -1 ;

#endif

}

void Timer1_OVF_SetCallBack(void (*p2f_var)(void)) {
	p2f_1 = p2f_var;
}
void Timer1_COMA_SetCallBack(void (*p2f_var)(void)) {
	p2f_2 = p2f_var;
}
void Timer1_COMB_SetCallBack(void (*p2f_var)(void)) {
	p2f_3 = p2f_var;
}

void __vector_7(void) __attribute__ ((signal));
void __vector_7(void) {
	if (p2f_2 != NULL)
		p2f_2();
}

void __vector_8(void) __attribute__ ((signal));
void __vector_8(void) {
	if (p2f_3 != NULL)
		p2f_3();
}

void __vector_9(void) __attribute__ ((signal));
void __vector_9(void) {
	if (p2f_1 != NULL)
		p2f_1();
}

