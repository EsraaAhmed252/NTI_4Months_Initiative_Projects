/*
 * EXI.h
 *
 *  Created on: Jul 24, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTINT_INTERFACE_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTINT_INTERFACE_H_

#include "EXTINT_Private.h"
#include "../../inc/Bit_Math.h"
#include "../../inc/Std_Types.h"

typedef enum {
	EXTI0,
	EXTI1,
	EXTI2
}EXTI_Source;

typedef enum {
	Sence_LOW,
	Sence_ANY,
	Sence_Falling,
	Sence_Rising
}EXTI_Sence_Mode;

void EXTI_VEnable (EXTI_Source source, EXTI_Sence_Mode mode);
void EXTI_VDisable (EXTI_Source source);
void EXTI0_SetCallBack (void (*p2f_var) (void));
void EXTI1_SetCallBack (void (*p2f_var) (void));
void EXTI2_SetCallBack (void (*p2f_var) (void));

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTINT_INTERFACE_H_ */
