/*
 * LED_Program.c
 *
 *  Created on: Feb 26, 2025
 *      Author: mylap
 */

#include "STD_Types.h"
#include "ErrorState.h"
#include "MATH_BIT.h"

#include "DIO_Interface.h"

#include "LED_Configuration.h"
#include "LED_Interface.h"
#include "LED_Private.h"

ES_t LED_enuInit(LED_t Copy_pstrLed)
{
	ES_t Local_enuErrorState = ES_NOK;
	Local_enuErrorState = DIO_enuSetPinDirection(Copy_pstrLed.Port,Copy_pstrLed.Pin,DIO_u8OUTPUT);
	return Local_enuErrorState;
}
ES_t LED_enuTurnON(LED_t Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrLedID.Active_State == ACTIVE_HIGH)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID.Port,Copy_pstrLedID.Pin,DIO_u8HIGH);
	}
	else if(Copy_pstrLedID.Active_State == ACTIVE_LOW)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID.Port,Copy_pstrLedID.Pin,DIO_u8LOW);
	}
	return Local_enuErrorState;
}
ES_t LED_enuTurnOFF(LED_t Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrLedID.Active_State == ACTIVE_HIGH)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID.Port,Copy_pstrLedID.Pin,DIO_u8LOW);
	}
	else if(Copy_pstrLedID.Active_State == ACTIVE_LOW)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID.Port,Copy_pstrLedID.Pin,DIO_u8HIGH);
	}
	return Local_enuErrorState;
}
ES_t LED_enuToggle(LED_t Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;
	Local_enuErrorState = DIO_enuTogPin(Copy_pstrLedID.Port,Copy_pstrLedID.Pin);
	return Local_enuErrorState;
}
