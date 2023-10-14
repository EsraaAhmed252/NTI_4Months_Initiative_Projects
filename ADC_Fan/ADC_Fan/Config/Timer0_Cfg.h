/*
 * Timer_Cfg.h
 *
 *  Created on: Jul 28, 2023
 *      Author: Esraa Ahmed Taha
 */

#ifndef CONFIG_TIMER0_CFG_H_
#define CONFIG_TIMER0_CFG_H_

#define Timer0_Mode						Timer0_Fast_PWM_Mode
#define Timer0_Fast_PWM_MODE			Timer0_Fast_PWM_NONINVERTING
#define Timer0_Phase_Correct_PWM_MODE	Timer0_Phase_Correct_PWM_NONINVERTING
#define Timer0_Prescaler				Timer0_Prescalling_64
#define Timer0_Enable_INT				Timer0_No_INT
#define Timer0_Init_Value				0
#define Timer0_OCR_Value				16

#endif /* CONFIG_TIMER0_CFG_H_ */
