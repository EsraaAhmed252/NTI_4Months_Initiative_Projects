/*
 * EXI.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Esraa Ahmed Taha
 */


#include "EXTINT_Interface.h"

static void (*ptr1) (void) = NULL;
static void (*ptr2) (void) = NULL;
static void (*ptr3) (void) = NULL;

void EXTI_VEnable (EXTI_Source source, EXTI_Sence_Mode mode){
	switch(source){

		case EXTI0:
			switch (mode)
			{

				case Sence_LOW:
					CLRBIT(MCUCR , ISC00);
					CLRBIT(MCUCR , ISC01);
					break;
				case Sence_ANY:
					SETBIT(MCUCR , ISC00);
					CLRBIT(MCUCR , ISC01);
					break;
				case Sence_Falling:
					CLRBIT(MCUCR , ISC00);
					SETBIT(MCUCR , ISC01);
					break;
				case Sence_Rising:
					SETBIT(MCUCR , ISC00);
					SETBIT(MCUCR , ISC01);
					break;

			}
			SETBIT(GICR , INT0);
			break;

		case EXTI1:
			switch (mode)
			{

				case Sence_LOW:
					CLRBIT(MCUCR , ISC10);
					CLRBIT(MCUCR , ISC11);
					break;
				case Sence_ANY:
					SETBIT(MCUCR , ISC10);
					CLRBIT(MCUCR , ISC11);
					break;
				case Sence_Falling:
					CLRBIT(MCUCR , ISC10);
					SETBIT(MCUCR , ISC11);
					break;
				case Sence_Rising:
					SETBIT(MCUCR , ISC10);
					SETBIT(MCUCR , ISC11);
					break;

			}
			SETBIT(GICR , INT1);
			break;

		case EXTI2:
			switch (mode)
			{

				case Sence_Falling:
					CLRBIT(MCUCSR , ISC2);
					break;
				case Sence_Rising:
					SETBIT(MCUCSR , ISC2);
					break;
				default:
					break;

			}
			SETBIT(GICR , INT2);
			break;
	}

}
void EXTI_VDisable (EXTI_Source source){

	switch (source)
	{
		case EXTI0:
			CLRBIT(GICR , INT0);
			break;
		case EXTI1:
			CLRBIT(GICR , INT1);
			break;
		case EXTI2:
			CLRBIT(GICR , INT2);
			break;
	}

}

void EXTI0_SetCallBack (void (*p2f_var) (void)){

	ptr1 = p2f_var ;

}

void EXTI1_SetCallBack (void (*p2f_var) (void)){

	ptr2 = p2f_var ;

}

void EXTI2_SetCallBack (void (*p2f_var) (void)){

	ptr3 = p2f_var ;

}

void __vector_1(void) __attribute__ ((signal));
void __vector_1(void){
	if(ptr1 != NULL)
	ptr1();
}

void __vector_2(void) __attribute__ ((signal));
void __vector_2(void){
	if(ptr2 != NULL)
	ptr2();
}

void __vector_3(void) __attribute__ ((signal));
void __vector_3(void){
	if(ptr3 != NULL)
	ptr3();
}
