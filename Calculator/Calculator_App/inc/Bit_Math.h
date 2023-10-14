/*
 * Bit_Math.h
 *
 *  Created on: Jul 22, 2023
 *      Author: dell
 */

#ifndef INC_BIT_MATH_H_
#define INC_BIT_MATH_H_

/*Bit Masking*/
#define SETBIT(REG,PIN) 	REG |= (1<<PIN)
#define CLRBIT(REG,PIN) 	REG &= (~(1<<PIN))
#define TOGBIT(REG,PIN) 	REG ^= (1<<PIN)
#define READBIT(REG,PIN)	((REG >> PIN) & 1)

#endif /* INC_BIT_MATH_H_ */
