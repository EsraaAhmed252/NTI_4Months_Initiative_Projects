/*
 * Std_Types.h
 *
 *  Created on: Jul 22, 2023
 *      Author: dell
 */

#ifndef INC_STD_TYPES_H_
#define INC_STD_TYPES_H_

typedef	signed char			INT8;
typedef	unsigned char		UINT8;

typedef unsigned char		BOOL;

typedef	signed short		INT16;
typedef	unsigned short		UINT16;


typedef	signed long			INT32;
typedef	unsigned long		UINT32;

typedef	signed long	long 	INT64;
typedef	unsigned long long	UINT64;

#define TRUE		((BOOL) 1)
#define FALSE		((BOOL) 0)

#define NULL ((void *)0)

#endif /* INC_STD_TYPES_H_ */
