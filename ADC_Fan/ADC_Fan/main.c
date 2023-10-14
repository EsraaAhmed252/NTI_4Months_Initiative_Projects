/*
 * main.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Dio_Mod/Dio.h"
#include "MCAL/Timer0/Timer0_Interface.h"
#include "MCAL/Global_INT/GI_Interface.h"
#include "MCAL/External Interrupt/EXTINT_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "util/delay.h"

volatile UINT32 Val ;
volatile UINT16 Duty_Val ;

void ADC_TEST (void){
	LCD_VClearScreen();
	Val = ADC_Read();
	LCD_VSendString("ADC_Read:");
	LCD_VIntegerToString(Val);
	LCD_VSendString(" Duty:");
	Duty_Val = (UINT16)((Val * 100) /1023);
	LCD_VIntegerToString(Duty_Val);
	Timer0_Duty_FastPWM(Duty_Val);
}

void EXTINT_TEST (void){
	LCD_VClearScreen();
	ADC_Stop();
	Timer0_Stop();
}
int main (void){

	Dio_Init();
	ADC_Init();
	LCD_VInit();
	GI_VEnable();
	ADC_Select_Channel(0);
	ADC_SetCallBack(ADC_TEST);
	EXTI1_SetCallBack (EXTINT_TEST);
	EXTI_VEnable (EXTI1 , Sence_Rising);
	ADC_INTEnable();
	Timer0_VInit();

	while (1){
		ADC_Start_Conversion();
		_delay_ms(100);
	}

}
