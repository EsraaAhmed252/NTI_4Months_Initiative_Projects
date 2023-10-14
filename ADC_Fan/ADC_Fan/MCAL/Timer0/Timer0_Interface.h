/*
 * Timer_Interface.h
 *
 *  Created on: Jul 28, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

#include "../../inc/Bit_Math.h"
#include "../../inc/Std_Types.h"
#include "Timer0_Private.h"

void Timer0_VInit(void);
void Timer0_OVERFLOW_Check(void);
void Timer0_INTEnable(void);
void Timer0_OVF_SetCallBack (void (*p2f_var) (void));
void Timer0_COM_SetCallBack (void (*p2f_var) (void));
void Set_OCR_Value (UINT8 val);
void Set_Init_Value (UINT8 val);
void Timer0_Stop (void);
void Timer0_Duty_FastPWM (UINT8 Duty);
void Timer0_Duty_Phase_Correct_PWM (UINT8 Duty);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
