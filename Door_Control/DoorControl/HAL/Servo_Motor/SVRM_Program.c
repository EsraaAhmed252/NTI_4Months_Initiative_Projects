/*
 * Servo_Motor.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "SVRM_Interface.h"

void SRVM_voidOn (UINT8 Angle)
{
	/* Range From 0--180 -90--90 */
	float Duty = 0;
	Duty = (Angle+180) / 36.0 ;
	Timer1_FastPWM_Mode14(Duty , 50);
	Timer1_Init();
}


void SRVM_voidOff(void)
{
	Timer1_Stop ();
}
