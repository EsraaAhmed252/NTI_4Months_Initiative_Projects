/*
 * ADC_Interface.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "ADC_Private.h"
#include "../../Config/ADC_Cfg.h"
#include "../../inc/Bit_Math.h"
#include "../../inc/Std_Types.h"

void ADC_Init (void);
void ADC_Select_Channel(UINT8 Channel);
UINT16 ADC_Read (void);
void ADC_Start_Conversion(void);
void ADC_Stop(void);
void ADC_INTEnable(void);
void ADC_Complete_Check(void);
void ADC_SetCallBack (void (*p2f) (void));

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
