/*
 * LCD.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "../../MCAL/Dio_Mod/Dio.h"
#include "../../Config/LCD_Cfg.h"

void LCD_VInit (void);
void LCD_VSendCmnd (UINT8 Cmnd);
void LCD_VSendChar (UINT8 Data);
void LCD_VSendString (UINT8 *arr);
void LCD_VGoToRowCol(UINT8 row, UINT8 col);
void LCD_VIntegerToString(UINT16 data);
void LCD_VClearScreen();

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
