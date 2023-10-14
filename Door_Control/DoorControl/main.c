/*
 * main.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "inc/Std_Types.h"
#include "MCAL/Dio_Mod/Dio.h"
#include "MCAL/Timer1/Timer1_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/Servo_Motor/SVRM_Interface.h"
#include "HAL/KeyPad/KeyPad.h"

const UINT8 CorrectPass[] = "1234";

void SecuritySystem(void);
void OpenDoor(void);

int main() {
    UINT8 maxTrials = 3;
    UINT16 key =0;

    Dio_Init();
    LCD_VInit();

    while(1){
    	LCD_VClearScreen();
    	LCD_VSendString("Welcome! Enter The Password: ");
		UINT8 i =0 ,trialCount = 0 ;
		while (1) {
			KPD_VGetValue(&key);
			if (key >= 1 && key <= 10) {

				if(CorrectPass[i] != ((key-1) + 48)){	//convert number to ASCII and Check every digit of Password
					LCD_VClearScreen();
					LCD_VSendString("Incorrect password. ");
					trialCount++;
					i =0 ;
					if(trialCount == maxTrials){
						LCD_VClearScreen();
						LCD_VSendString("Too many incorrect attempts. Security system activated.");
						SecuritySystem();
						break;
					}
				}
				else{
					LCD_VSendChar('*');
					i++;
					if(i == (sizeof(CorrectPass)-1)){
						LCD_VClearScreen();
						LCD_VSendString("Welcome! Door opening...");
						OpenDoor();
						break;
					}
				}
			}
		}
	}
    return 0;
}

void SecuritySystem(void){
	UINT16 Stop =0;
	Dio_WriteChannel(PINB_5,HIGH);
	Dio_WriteChannel(PINB_6,HIGH);
	while(Stop != 16){				//To Stop Security System & System start again
		KPD_VGetValue(&Stop);
	}
	Dio_WriteChannel(PINB_5,LOW);
	Dio_WriteChannel(PINB_6,LOW);
	return;
}

void OpenDoor(void){
	UINT16 Close = 0;
	SRVM_voidOn (180);
	while(Close != 15){				//To close the Door & System start again
		KPD_VGetValue(&Close);
	}
	SRVM_voidOn (90);
	return;
}
