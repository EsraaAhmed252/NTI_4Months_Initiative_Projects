/*
 * LCD.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Esraa Ahmed Taha
 */


#include "LCD_Interface.h"
#include "LCD_Private.h"
#define F_CPU 16000000
#include "util/delay.h"

void LCD_VInit (void){

	_delay_ms(35);
	Private_VWriteHalfPort(0b0010);
	Private_VEnable();
	/*LCD_VSendCmnd(0b0010000);*/
	LCD_VSendCmnd(LCD_Function_Set);
	_delay_us(45);
	LCD_VSendCmnd(LCD_Display_Control);
	_delay_us(45);
	LCD_VSendCmnd(LCD_Display_Clear);
	_delay_ms(2);
	LCD_VSendCmnd(LCD_Entry_Mode);

}

void LCD_VSendCmnd (UINT8 Cmnd){

	Dio_WriteChannel(LCD_Rs , LOW);
	Private_VWriteHalfPort(Cmnd>>4);
	Private_VEnable();
	Private_VWriteHalfPort(Cmnd);
	Private_VEnable();

}

void LCD_VSendChar (UINT8 Data){

	Dio_WriteChannel(LCD_Rs , HIGH);
	Private_VWriteHalfPort(Data>>4);
	Private_VEnable();
	Private_VWriteHalfPort(Data);
	Private_VEnable();

}

void LCD_VSendString (UINT8 *arr){
	UINT8 i = 0;
	while(arr[i] != '\0'){
		LCD_VSendChar (arr[i]);
		i++;
	}
}

void LCD_VGoToRowCol(UINT8 row, UINT8 col){

	UINT8 address;
		switch (row)
		{
			case 0:
				address = col;
				break;
			case 1:
				address = col + 0x40;
				break;
			case 2:
				address = col + 0x14;
				break;
			case 3:
				address = col + 0x54;
				break;

		}
		LCD_VSendCmnd(address | SET_CURSOR_LOCATION);
}

void LCD_VIntegerToString(UINT16 data){

	UINT8 BUFF[16];
	//itoa(data,BUFF,10);
	Private_VintToStr(data,BUFF);
	LCD_VSendString(BUFF);

}

void LCD_VClearScreen(){
	LCD_VSendCmnd(LCD_Display_Clear);
	_delay_ms(2);
}

static void Private_VWriteHalfPort(UINT8 value){

	Dio_WriteChannel(LCD_D4 , READBIT(value , 0));
	Dio_WriteChannel(LCD_D5 , READBIT(value , 1));
	Dio_WriteChannel(LCD_D6 , READBIT(value , 2));
	Dio_WriteChannel(LCD_D7 , READBIT(value , 3));

}

static void Private_VEnable(void){

	Dio_WriteChannel(LCD_En , HIGH);
	_delay_ms(1);
	Dio_WriteChannel(LCD_En , LOW);

}

static void Private_VintToStr(UINT16 num, UINT8 str[]) {
    int i = 0;

    do {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);

    str[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


