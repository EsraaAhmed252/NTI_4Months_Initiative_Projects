/*
 * main.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Dio_Mod/Dio.h"
#include "MCAL/Global_INT/GI_Interface.h"
#include "MCAL/External Interrupt/EXTINT_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KeyPad/KeyPad.h"
#include <util/delay.h>

volatile UINT16 Val ;
volatile UINT16 num1;

void ADC_TEST (void){
	LCD_VClearScreen();
	Val = ADC_Read();
	if(Val<num1){
		Dio_WriteChannel(PINA_5,HIGH);
		Dio_WriteChannel(PINA_4,LOW);
	}
	else{
		Dio_WriteChannel(PINA_5,LOW);
		Dio_WriteChannel(PINA_4,HIGH);
	}
	LCD_VIntegerToString(Val);
}

int main (void){

	UINT16 key = 0;
	Dio_Init();
	ADC_Init();
	LCD_VInit();
	GI_VEnable();
	ADC_Select_Channel(0);
	ADC_SetCallBack(ADC_TEST);

	ADC_INTEnable();


	while (1) {
		KPD_VGetValue(&key);
		if (key >= 1 && key <= 10) {
			LCD_VClearScreen();
			num1 = num1 * 10 + (key - 1);
			LCD_VIntegerToString(num1);
		} else if (key == 16) {
			num1 = 0;
			LCD_VClearScreen();
		} else if (key == 15) {
			break;
		}
	}
	while (1){
		ADC_Start_Conversion();
		_delay_ms(100);
	}

}
