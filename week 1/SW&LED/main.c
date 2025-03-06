/*
 * main.c
 *
 *  Created on: Feb 26, 2025
 *      Author: mylap
 */

#include "STD_Types.h"
#include "ErrorState.h"
#include "DIO_Interface.h"
#include "LED_Interface.h"
#include "SWITCH_Interface.h"
#include "util/delay.h"

int main()
{
	u8 SWState;
	DIO_enuInit();
	LED_t led = {DIO_u8PORTC,DIO_u8PIN1,ACTIVE_HIGH};
	LED_enuInit(led);
	SW_t sw = {DIO_u8PORTC,DIO_u8PIN0,DIO_u8PULL_UP};
	Switch_enuInit(sw);
	while(1)
	{
		Switch_enuGetState(sw,&SWState);
		if(SWState == SW_PRESSED)
			LED_enuTurnON(led);
		else if(SWState == SW_NOTPRESSED)
			LED_enuTurnOFF(led);
	}
	return 0;
}
