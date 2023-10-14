/*
 * ADC_Progarm.c
 *
 *  Created on: Aug 4, 2023
 *      Author: Esraa Ahmed Taha
 */
#include "ADC_Interface.h"

static void (*ptr1) (void) = NULL;

void ADC_Init (void){

#if ADC_Prescaler == ADC_Prescalling_2
	CLRBIT(ADCSRA,ADPS0);
	CLRBIT(ADCSRA,ADPS1);
	CLRBIT(ADCSRA,ADPS2);

#elif ADC_Prescaler == ADC_Prescalling_4
	CLRBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	CLRBIT(ADCSRA,ADPS2);

#elif ADC_Prescaler == ADC_Prescalling_8
	SETBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	CLRBIT(ADCSRA,ADPS2);

#elif ADC_Prescaler == ADC_Prescalling_16
	CLRBIT(ADCSRA,ADPS0);
	CLRBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);

#elif ADC_Prescaler == ADC_Prescalling_32
	SETBIT(ADCSRA,ADPS0);
	CLRBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);

#elif ADC_Prescaler == ADC_Prescalling_64
	CLRBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);

#elif ADC_Prescaler == ADC_Prescalling_128
	SETBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);

#endif

#if Voltage_Ref == External_AREF
	CLRBIT(ADMUX,REFS0);
	CLRBIT(ADMUX,REFS1);

#elif Voltage_Ref == Internal_AVCC
	SETBIT(ADMUX,REFS0);
	CLRBIT(ADMUX,REFS1);

#elif Voltage_Ref == Internal_Voltage
	SETBIT(ADMUX,REFS0);
	SETBIT(ADMUX,REFS1);

#endif

	SETBIT(ADCSRA,ADEN);

}

void ADC_Select_Channel(UINT8 Channel){
	switch(Channel){
	case 0:
		CLRBIT(ADMUX,MUX0);
		CLRBIT(ADMUX,MUX1);
		CLRBIT(ADMUX,MUX2);
		break;

	case 1:
		SETBIT(ADMUX,MUX0);
		CLRBIT(ADMUX,MUX1);
		CLRBIT(ADMUX,MUX2);
		break;

	case 2:
		CLRBIT(ADMUX,MUX0);
		SETBIT(ADMUX,MUX1);
		CLRBIT(ADMUX,MUX2);
		break;

	case 3:
		SETBIT(ADMUX,MUX0);
		SETBIT(ADMUX,MUX1);
		CLRBIT(ADMUX,MUX2);
		break;

	case 4:
		CLRBIT(ADMUX,MUX0);
		CLRBIT(ADMUX,MUX1);
		SETBIT(ADMUX,MUX2);
		break;

	case 5:
		SETBIT(ADMUX,MUX0);
		CLRBIT(ADMUX,MUX1);
		SETBIT(ADMUX,MUX2);
		break;

	case 6:
		CLRBIT(ADMUX,MUX0);
		SETBIT(ADMUX,MUX1);
		SETBIT(ADMUX,MUX2);
		break;

	case 7:
		SETBIT(ADMUX,MUX0);
		SETBIT(ADMUX,MUX1);
		SETBIT(ADMUX,MUX2);
		break;
	}
}

UINT16 ADC_Read (void){
	return (UINT16) ADC ;
}

void ADC_Start_Conversion(void){
	SETBIT(ADCSRA,ADSC);
}

void ADC_Stop(void){
	CLRBIT(ADCSRA,ADEN);
}

void ADC_INTEnable(void){
	SETBIT(ADCSRA,ADIE);
}

void ADC_Complete_Check(void){
	while (READBIT(ADCSRA,ADIF)==0);
	SETBIT(ADCSRA,ADIF);
}

void ADC_SetCallBack (void (*p2f) (void)){
	ptr1 = p2f ;
}

void __vector_16(void) __attribute__ ((signal));
void __vector_16(void){
	if(ptr1 != NULL)
	ptr1();
}
