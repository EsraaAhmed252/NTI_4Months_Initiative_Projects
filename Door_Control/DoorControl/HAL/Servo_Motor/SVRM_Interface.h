/*
 * Servo_Motor.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef HAL_SERVO_MOTOR_SVRM_INTERFACE_H_
#define HAL_SERVO_MOTOR_SVRM_INTERFACE_H_

#include "../../inc/Std_Types.h"
#include "../../MCAL/Timer1/Timer1_Interface.h"

void SRVM_voidOn (UINT8 Angle);
void SRVM_voidOff(void);

#endif /* HAL_SERVO_MOTOR_SVRM_INTERFACE_H_ */
