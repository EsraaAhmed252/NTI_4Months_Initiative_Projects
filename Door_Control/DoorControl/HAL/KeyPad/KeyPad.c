/*
 * KeyPad.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Esraa Ahmed Taha
 */

#include "KeyPad.h"

static UINT8 Keypad [4][4]={{14,10,9,8},
							{13,7,6,5},
							{12,4,3,2},
							{11,15,1,16}};

void KPD_VGetValue (UINT16 * Return_Value){

	*Return_Value = Key_Not_Pressed;
	UINT8 Row , Col ;
	UINT8 Arr_Row [4] = {ROW1 , ROW2 ,ROW3 ,ROW4};
	UINT8 Arr_Col [4] = {COL1 , COL2 ,COL3 ,COL4};

		for(Row=0 ; Row<4 ; Row++){

			Dio_WriteChannel(Arr_Row[Row],LOW);

			for (Col=0 ; Col<4 ; Col++)
				if( Dio_ReadChannel(Arr_Col[Col]) == 0){
//					*Return_Value = (Row * 4) + Col + 1 ;
					*Return_Value = Keypad[Row][Col];
					while(Dio_ReadChannel(Arr_Col[Col]) == 0);
					Dio_WriteChannel(Arr_Row[Row],HIGH);
					return;
				}

			Dio_WriteChannel(Arr_Row[Row],HIGH);

		}
}

