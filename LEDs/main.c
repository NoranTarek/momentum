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
#include "util/delay.h"

int main()
{
	DIO_enuInit();
	LED_t led[5] =
	{
			{DIO_u8PORTC , DIO_u8PIN0 , ACTIVE_HIGH},
			{DIO_u8PORTC , DIO_u8PIN1 , ACTIVE_HIGH},
			{DIO_u8PORTC , DIO_u8PIN2 , ACTIVE_HIGH},
			{DIO_u8PORTC , DIO_u8PIN3 , ACTIVE_HIGH},
			{DIO_u8PORTC , DIO_u8PIN4 , ACTIVE_HIGH}
	};
	for(int i = 0 ; i < 5;i++)
		LED_enuInit(led[i]);
	while(1)
	{
		for(int i = 0 ; i < 5;i++)
		{
			LED_enuTurnON(led[i]);
			_delay_ms(1000);
		}
		for(int i = 0 ; i < 5;i++)
		{
			LED_enuTurnOFF(led[i]);
			_delay_ms(1000);
		}
	}
	return 0;
}
