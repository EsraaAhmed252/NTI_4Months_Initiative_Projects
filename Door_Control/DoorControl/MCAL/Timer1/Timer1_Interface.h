/*
 * Timer1_Interface.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#include "Timer1_Private.h"
#include "../../Config/Timer1_Cfg.h"
#include "../../inc/Bit_Math.h"
#include "../../inc/Std_Types.h"

void Timer1_Init(void);
void Timer1_INTEnable(void);
void Timer1_OVF_SetCallBack (void (*p2f_var) (void));
void Timer1_COMA_SetCallBack (void (*p2f_var) (void));
void Timer1_COMB_SetCallBack (void (*p2f_var) (void));
void Set_Init_Value_Timer1 (UINT16 val);
void Set_OCR_Value_Timer1 (UINT16 val);
void Timer1_Duty_FastPWM (UINT16 Duty);
void Timer1_FastPWM_Mode14 (float Duty , UINT16 freq);
void Timer1_FastPWM_Mode15(float Duty, UINT16 freq);
void Timer1_Stop (void);

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
