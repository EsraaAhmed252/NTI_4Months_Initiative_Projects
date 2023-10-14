/*
 * ADC_Private.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADC_Prescalling_2			1
#define ADC_Prescalling_4			2
#define ADC_Prescalling_8			3
#define ADC_Prescalling_16			4
#define ADC_Prescalling_32			5
#define ADC_Prescalling_64			6
#define ADC_Prescalling_128			7

#define External_AREF		1
#define Internal_AVCC		2
#define Internal_Voltage	3

#define ADMUX *((volatile unsigned char * )(0x27))
#define MUX0	0
#define MUX1	1
#define MUX2	2
#define MUX3	3
#define MUX4	4
#define ADLAR	5
#define REFS0	6
#define REFS1	7

#define ADCSRA *((volatile unsigned char * )(0x26))
#define ADPS0	0
#define ADPS1	1
#define ADPS2	2
#define ADIE	3
#define ADIF	4
#define ADATE	5
#define ADSC	6
#define ADEN	7

#define ADCH *((volatile unsigned char * )(0x25))
#define ADCL *((volatile unsigned char * )(0x24))

#define ADC  *((volatile unsigned short * )(0x24))

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
