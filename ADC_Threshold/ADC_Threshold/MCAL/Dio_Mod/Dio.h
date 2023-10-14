/*
 * Dio.h
 *
 *  Created on: Jul 22, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_DIO_MOD_DIO_H_
#define MCAL_DIO_MOD_DIO_H_

#include "Dio_Types.h"
#include "Dio_Reg.h"
#include "../../inc/Bit_Math.h"
#include "../../inc/Std_Types.h"
#include "../../Config/Dio_Cfg.h"

void Dio_Init();
void Dio_WriteChannel(Pin_Channel_Type channel, Pin_Status_Type status);
Pin_Status_Type Dio_ReadChannel (Pin_Channel_Type channel);
void Dio_WritePort(Dio_Port_Type port, UINT8 value);
UINT8 Dio_ReadPort (Dio_Port_Type port);

#endif /* MCAL_DIO_MOD_DIO_H_ */
