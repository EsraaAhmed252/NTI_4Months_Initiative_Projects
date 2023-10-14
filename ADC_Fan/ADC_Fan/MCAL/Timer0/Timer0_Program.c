/*
 * Timer_Program.c
 *
 *  Created on: Jul 28, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "../../Config/Timer0_Cfg.h"
#include "Timer0_Interface.h"

static void (*p2f_1) (void) = NULL;
static void (*p2f_2) (void) = NULL;

void Timer0_VInit(void){

	TCNT0 = Timer0_Init_Value ;

#if Timer0_Mode == Timer0_Normal_Mode

	CLRBIT(TCCR0,WGM00);
	CLRBIT(TCCR0,WGM01);

#elif Timer0_Mode == Timer0_PWM_Mode

	SETBIT(TCCR0,WGM00);
	CLRBIT(TCCR0,WGM01);

#if Timer0_Phase_Correct_PWM_MODE == Timer0_Phase_Correct_PWM_NONINVERTING

	CLRBIT(TCCR0,COM00);
	SETBIT(TCCR0,COM01);

#elif Timer0_Phase_Correct_PWM_MODE == Timer0_Phase_Correct_PWM_INVERTING

	SETBIT(TCCR0,COM00);
	SETBIT(TCCR0,COM01);

#endif

#elif Timer0_Mode == Timer0_CTC_Mode

//Set_OCR_Value(OCR_Value);
	OCR0 = Timer0_OCR_Value ;
	CLRBIT(TCCR0,WGM00);
	SETBIT(TCCR0,WGM01);

#elif Timer0_Mode == Timer0_Fast_PWM_Mode

	SETBIT(TCCR0,WGM00);
	SETBIT(TCCR0,WGM01);

#if Timer0_Fast_PWM_MODE == Timer0_Fast_PWM_NONINVERTING

	CLRBIT(TCCR0,COM00);
	SETBIT(TCCR0,COM01);

#elif Timer0_Fast_PWM_MODE == Timer0_Fast_PWM_INVERTING

	SETBIT(TCCR0,COM00);
	SETBIT(TCCR0,COM01);

#endif

#endif

#if Timer0_Prescaler == Timer0_No_Prescalling

			//TCCR0 &= 0xF8
			//TCCR0 |= No_Prescalling
			SETBIT(TCCR0,CS00);
			CLRBIT(TCCR0,CS01);
			CLRBIT(TCCR0,CS02);

#elif Timer0_Prescaler == Timer0_Prescalling_8

			CLRBIT(TCCR0,CS00);
			SETBIT(TCCR0,CS01);
			CLRBIT(TCCR0,CS02);

#elif Timer0_Prescaler == Timer0_Prescalling_64

			SETBIT(TCCR0,CS00);
			SETBIT(TCCR0,CS01);
			CLRBIT(TCCR0,CS02);

#elif Timer0_Prescaler == Timer0_Prescalling_265

			CLRBIT(TCCR0,CS00);
			CLRBIT(TCCR0,CS01);
			SETBIT(TCCR0,CS02);

#elif Timer0_Prescaler == Timer0_Prescalling_1024

			SETBIT(TCCR0,CS00);
			CLRBIT(TCCR0,CS01);
			SETBIT(TCCR0,CS02);

#elif Timer0_Prescaler == Timer0_External_Clk_Fallling

			CLRBIT(TCCR0,CS00);
			SETBIT(TCCR0,CS01);
			SETBIT(TCCR0,CS02);

#elif Timer0_Prescaler == Timer0_External_Clk_Rising

			SETBIT(TCCR0,CS00);
			SETBIT(TCCR0,CS01);
			SETBIT(TCCR0,CS02);
#endif

}

void Timer0_INTEnable(void){
#if Timer0_Enable_INT == Timer0_OverFlow_Enable

	SETBIT(TIMSK,TOIE0);

#elif Timer0_Enable_INT == Timer0_ComperMatch_Enable

	SETBIT(TIMSK,OCIE0);

#elif Timer0_Enable_INT == Timer0_No_INT

#endif
}

void Set_Init_Value (UINT8 val){
	TCNT0 = val ;
}

void Set_OCR_Value (UINT8 val){
	OCR0 = val ;
}

void Timer0_OVERFLOW_Check(void){

	while(READBIT(TIFR,TOV0) == 0);
	Set_Init_Value(Timer0_Init_Value);
	SETBIT(TIFR,TOV0);

}

void Timer0_Duty_FastPWM (UINT8 Duty){

	if(Duty<=100){
#if Timer0_Fast_PWM_MODE == Timer0_Fast_PWM_NONINVERTING

		OCR0 = (Duty * 256 /100) -1;

#elif Timer0_Fast_PWM_MODE == Timer0_Fast_PWM_INVERTING

		Duty = 100 - Duty;
		OCR0 = (Duty * 256 /100) -1;

#endif
	}

}

void Timer0_Stop (void){

	CLRBIT(TCCR0,CS00);
	CLRBIT(TCCR0,CS01);
	CLRBIT(TCCR0,CS02);

}

void Timer0_Duty_Phase_Correct_PWM (UINT8 Duty){

	if(Duty<=100){
#if Timer0_Phase_Correct_PWM_MODE == Timer0_Phase_Correct_PWM_NONINVERTING

		OCR0 = ((Duty * 510 /100)/2) -1;

#elif Timer0_Phase_Correct_PWM_MODE == Timer0_Phase_Correct_PWM_INVERTING

		Duty = 100 - Duty;
		OCR0 =  ((Duty * 510 /100)/2) -1;

#endif
	}

}

void Timer0_COM_SetCallBack (void (*p2f_var) (void)){
	p2f_2 = p2f_var ;

}

void Timer0_OVF_SetCallBack (void (*p2f_var) (void)){
	p2f_1 = p2f_var ;

}

void __vector_10(void) __attribute__ ((signal));
void __vector_10(void){
	if(p2f_2 != NULL)
		p2f_2();
}

void __vector_11(void) __attribute__ ((signal));
void __vector_11(void){
	if(p2f_1 != NULL)
		p2f_1();
}
