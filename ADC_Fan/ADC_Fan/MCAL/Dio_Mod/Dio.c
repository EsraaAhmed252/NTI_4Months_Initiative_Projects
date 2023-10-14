/*
 * Dio.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "Dio.h"

void Dio_Init(){

	for (int i=0 ; i< No_of_DIO ; i++){

		switch (Pin_Cfg[i].Port){

			case Dio_PORTA :
				if(Pin_Cfg[i].Dir){
					SETBIT(DDRA , Pin_Cfg[i].Pin);
				}
				else{
					CLRBIT(DDRA , Pin_Cfg[i].Pin);
					SETBIT(PORTA , Pin_Cfg[i].Pin);
				}
				break;

			case Dio_PORTB :
				if(Pin_Cfg[i].Dir){
					SETBIT(DDRB , Pin_Cfg[i].Pin);
				}
				else{
					CLRBIT(DDRB , Pin_Cfg[i].Pin);
					SETBIT(PORTB , Pin_Cfg[i].Pin);
				}
				break;

			case Dio_PORTC :
				if(Pin_Cfg[i].Dir){
					SETBIT(DDRC , Pin_Cfg[i].Pin);
				}
				else{
					CLRBIT(DDRC , Pin_Cfg[i].Pin);
					SETBIT(PORTC , Pin_Cfg[i].Pin);
				}
				break;

			case Dio_PORTD :
				if(Pin_Cfg[i].Dir){
					SETBIT(DDRD , Pin_Cfg[i].Pin);
				}
				else{
					CLRBIT(DDRD , Pin_Cfg[i].Pin);
					SETBIT(PORTD , Pin_Cfg[i].Pin);
				}
				break;
		}
	}
}

void Dio_WriteChannel(Pin_Channel_Type channel, Pin_Status_Type status){

	Dio_Port_Type port = channel/8;
	UINT8 pin = channel%8;

	switch (port) {
		case Dio_PORTA :
				if(status == LOW){
					CLRBIT(PORTA , pin);
				}
				else{
					SETBIT(PORTA , pin);
				}
				break;

		case Dio_PORTB :
				if(status == LOW){
					CLRBIT(PORTB , pin);
				}
				else{
					SETBIT(PORTB , pin);
				}
				break;

		case Dio_PORTC :
				if(status == LOW){
					CLRBIT(PORTC , pin);
				}
				else{
					SETBIT(PORTC , pin);
				}
				break;

		case Dio_PORTD :
				if(status == LOW){
					CLRBIT(PORTD , pin);
				}
				else{
					SETBIT(PORTD , pin);
				}
				break;
		}
}

Pin_Status_Type Dio_ReadChannel (Pin_Channel_Type channel){

	Dio_Port_Type port = channel/8;
	UINT8 pin = channel%8;

	switch (port) {
			case Dio_PORTA :
					return READBIT(PINA , pin);

			case Dio_PORTB :
					return READBIT(PINB , pin);

			case Dio_PORTC :
					return READBIT(PINC , pin);

			case Dio_PORTD :
					return READBIT(PIND , pin);
		}

	return -1;
}

void Dio_WritePort(Dio_Port_Type port, UINT8 value){

	switch (port) {
		case Dio_PORTA :
				PORTA = value;
				break;

		case Dio_PORTB :
				PORTB = value;
				break;

		case Dio_PORTC :
				PORTC = value;
				break;

		case Dio_PORTD :
				PORTD = value;
				break;
		}
}

UINT8 Dio_ReadPort (Dio_Port_Type port){

	switch (port) {
			case Dio_PORTA :
					return PINA;

			case Dio_PORTB :
					return PINB;

			case Dio_PORTC :
					return PINC;

			case Dio_PORTD :
					return PIND;
		}

	return -1;
}


