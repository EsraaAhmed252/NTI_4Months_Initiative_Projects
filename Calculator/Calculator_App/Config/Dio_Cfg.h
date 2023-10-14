/*
 * Dio_Cfg.h
 *
 *  Created on: Jul 22, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef CONFIG_DIO_CFG_H_
#define CONFIG_DIO_CFG_H_

#include "../MCAL/Dio_Mod/Dio_Types.h"

typedef struct {
	Dio_Port_Type Port;
	Dio_Pin_Type Pin;
	Pin_Direction_Type Dir;
}Pin_Config;

extern Pin_Config Pin_Cfg [];
extern int No_of_DIO;

#endif /* CONFIG_DIO_CFG_H_ */
