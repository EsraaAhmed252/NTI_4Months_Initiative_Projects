/*
 * Dio_Types.h
 *
 *  Created on: Jul 22, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_DIO_MOD_DIO_TYPES_H_
#define MCAL_DIO_MOD_DIO_TYPES_H_

typedef enum {

	PINA_0,
	PINA_1,
	PINA_2,
	PINA_3,
	PINA_4,
	PINA_5,
	PINA_6,
	PINA_7,

	PINB_0,
	PINB_1,
	PINB_2,
	PINB_3,
	PINB_4,
	PINB_5,
	PINB_6,
	PINB_7,

	PINC_0,
	PINC_1,
	PINC_2,
	PINC_3,
	PINC_4,
	PINC_5,
	PINC_6,
	PINC_7,

	PIND_0,
	PIND_1,
	PIND_2,
	PIND_3,
	PIND_4,
	PIND_5,
	PIND_6,
	PIND_7,

}Pin_Channel_Type;

typedef enum {
	LOW,
	HIGH
}Pin_Status_Type;

typedef enum {
	INPUT,
	OUTPUT
}Pin_Direction_Type;

typedef enum {
	Dio_PORTA,
	Dio_PORTB,
	Dio_PORTC,
	Dio_PORTD
}Dio_Port_Type;

typedef enum {
	Dio_Pin0,
	Dio_Pin1,
	Dio_Pin2,
	Dio_Pin3,
	Dio_Pin4,
	Dio_Pin5,
	Dio_Pin6,
	Dio_Pin7,
}Dio_Pin_Type;

#endif /* MCAL_DIO_MOD_DIO_TYPES_H_ */
