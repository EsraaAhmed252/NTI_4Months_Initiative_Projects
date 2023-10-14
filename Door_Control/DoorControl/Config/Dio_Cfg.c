/*
 * Dio_Cfg.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "Dio_Cfg.h"

Pin_Config Pin_Cfg []={
		{Dio_PORTC , Dio_Pin5 , OUTPUT} ,
		{Dio_PORTC , Dio_Pin4 , OUTPUT} ,
		{Dio_PORTC , Dio_Pin3 , OUTPUT} ,
		{Dio_PORTC , Dio_Pin2 , OUTPUT} ,
		{Dio_PORTD , Dio_Pin7 , INPUT} ,
		{Dio_PORTD , Dio_Pin6 , INPUT} ,
		{Dio_PORTD , Dio_Pin4 , INPUT} ,
		{Dio_PORTD , Dio_Pin3 , INPUT} ,
		{Dio_PORTA , Dio_Pin2 , OUTPUT} ,
		{Dio_PORTA , Dio_Pin3 , OUTPUT} ,
		{Dio_PORTB , Dio_Pin0 , OUTPUT} ,
		{Dio_PORTB , Dio_Pin1 , OUTPUT} ,
		{Dio_PORTB , Dio_Pin2 , OUTPUT} ,
		{Dio_PORTB , Dio_Pin4 , OUTPUT} ,
		{Dio_PORTB , Dio_Pin5 , OUTPUT} ,
		{Dio_PORTB , Dio_Pin6 , OUTPUT} ,
		{Dio_PORTD , Dio_Pin5 , OUTPUT}
};

int No_of_DIO = (sizeof(Pin_Cfg)/sizeof(Pin_Cfg[0]));
