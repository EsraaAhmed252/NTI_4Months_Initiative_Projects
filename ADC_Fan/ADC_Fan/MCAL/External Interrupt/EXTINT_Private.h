/*
 * EXT_Private.h
 *
 *  Created on: Jul 24, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTINT_PRIVATE_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTINT_PRIVATE_H_

#define MCUCR *((volatile unsigned char * )(0x55))
#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3

#define MCUCSR *((volatile unsigned char * )(0x54))
#define ISC2 6

#define GICR *((volatile unsigned char * )(0x5B))
#define INT0 6
#define INT1 7
#define INT2 5

#define GIFR *((volatile unsigned char * )(0x5A))

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTINT_PRIVATE_H_ */
