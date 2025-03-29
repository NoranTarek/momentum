/*
 * main.c
 *
 *  Created on: Oct 17, 2024
 *      Author: mylap
 */

#include "stdTypes.h"
#include "errorStates.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "LCD_int.h"

#include "KPD_int.h"

#include "CALC.h"

int main(void)
{
	u8 Local_u8Key;
	u8 Eqn[MAX];
	DIO_enuInit();
	LCD_enuInit();
	u8 counter=0,i=0;
	while(1)
	{
		do
		{
		}while(Local_u8Key == 0xff);
		LCD_enuDisplayChar(Local_u8Key);
		if(Local_u8Key == '=')
			Calc(Eqn);
		Eqn[counter] = Local_u8Key;
	}
	return 0;
}
