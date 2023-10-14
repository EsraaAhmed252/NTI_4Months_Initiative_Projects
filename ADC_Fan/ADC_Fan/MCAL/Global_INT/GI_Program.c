/*
 * GI.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "GI_Interface.h"

void GI_VEnable(void){
	SETBIT(SREG , GI_Pin);
}

void GI_VDisable(void){
	CLRBIT(SREG , GI_Pin);
}
