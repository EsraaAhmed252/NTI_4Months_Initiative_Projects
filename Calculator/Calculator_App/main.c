/*
 * 		CalcApp.c
 *
 *  	Created on: Jul 30, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KeyPad/KeyPad.h"
#include "MCAL/Dio_Mod/Dio.h"

UINT16 calculate(UINT16 num1, UINT16 num2, UINT8 operator);

int main() {

    UINT16 num1, num2;
    UINT8 operator;
	UINT16 key = 0;

    Dio_Init();
    LCD_VInit();
    while(1){
    	num1 =0;
    	num2 =0;
		while (1) {
			KPD_VGetValue(&key);
			if (key >= 1 && key <= 10) {
				LCD_VClearScreen();
				num1 = num1 * 10 + (key - 1);
				LCD_VIntegerToString(num1);
			} else if (key == 16) {
				num1 = 0;
				LCD_VClearScreen();
			} else if (key >= 11 && key <= 15){
				switch (key) {
					case 11: operator = '+'; LCD_VSendChar('+'); break;
					case 12: operator = '-'; LCD_VSendChar('-'); break;
					case 13: operator = '*'; LCD_VSendChar('*'); break;
					case 14: operator = '/'; LCD_VSendChar('/'); break;
					case 15: operator = '='; LCD_VSendChar('='); break;
				}
				break;
			}
		}

		if(operator != '='){
			while (1) {
				KPD_VGetValue(&key);
				if (key >= 1 && key <= 10) {
					LCD_VClearScreen();
					LCD_VIntegerToString(num1);
					LCD_VSendChar(operator);
					num2 = num2 * 10 + (key - 1);
					LCD_VIntegerToString(num2);
				} else if (key == 16) {
					num2 = 0;
					LCD_VClearScreen();
					LCD_VIntegerToString(num1);
					LCD_VSendChar(operator);
				} else if (key == 15) {
					break;
				}
			}
			LCD_VSendChar('=');
			UINT16 result = calculate(num1, num2, operator);
			LCD_VIntegerToString(result);
		}

		else{
			LCD_VSendChar('=');
			LCD_VIntegerToString(num1);
		}
    }
    return 0;
}

UINT16 calculate(UINT16 num1, UINT16 num2, UINT8 operator) {
    UINT16 result;
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num2 != 0 ? num1 / num2 : 0;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

