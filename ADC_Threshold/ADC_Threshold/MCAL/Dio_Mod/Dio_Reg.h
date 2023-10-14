/*
 * Dio_Reg.h
 *
 *  Created on: Jul 22, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_DIO_MOD_DIO_REG_H_
#define MCAL_DIO_MOD_DIO_REG_H_

#define PINA *((volatile unsigned char * )(0x39))
#define DDRA *((volatile unsigned char * )(0x3A))
#define PORTA *((volatile unsigned char * )(0x3B))

#define PINB *((volatile unsigned char * )(0x36))
#define DDRB *((volatile unsigned char * )(0x37))
#define PORTB *((volatile unsigned char * )(0x38))

#define PINC *((volatile unsigned char * )(0x33))
#define DDRC *((volatile unsigned char * )(0x34))
#define PORTC *((volatile unsigned char * )(0x35))

#define PIND *((volatile unsigned char * )(0x30))
#define DDRD *((volatile unsigned char * )(0x31))
#define PORTD *((volatile unsigned char * )(0x32))

#endif /* MCAL_DIO_MOD_DIO_REG_H_ */
