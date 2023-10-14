/*
 * LCD_Private.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

static void Private_VWriteHalfPort(UINT8 value);
static void Private_VEnable(void);
static void Private_VintToStr(UINT16 num, UINT8 str[]);

#define LCD_Function_Set	0b00101000
#define LCD_Display_Control 0b00001111
#define LCD_Display_Clear	0b00000001
#define LCD_Entry_Mode		0b00000110
#define SET_CURSOR_LOCATION 0x80

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
