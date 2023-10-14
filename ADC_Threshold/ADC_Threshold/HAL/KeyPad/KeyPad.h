/*
 * KeyPad.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../MCAL/Dio_Mod/Dio.h"
#include "../../Config/KPD_Cfg.h"

#define Key_Not_Pressed 200

void KPD_VGetValue (UINT16 * Return_Value);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
