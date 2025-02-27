/*
 * SWITCH_Program.c
 *
 *  Created on: Feb 26, 2025
 *      Author: mylap
 */

#include "STD_Types.h"
#include "ErrorState.h"

#include "DIO_Interface.h"
#include "SWITCH_Interface.h"
#include "SWITCH_Configuration.h"
#include "SWITCH_Private.h"


ES_t Switch_enuInit(SW_t copy_SWAstr)
{
	ES_t Local_enuErrorState = ES_NOK;
	Local_enuErrorState = DIO_enuSetPinDirection(copy_SWAstr.Switch_PortID,copy_SWAstr.Switch_PinID,DIO_u8INPUT);
	Local_enuErrorState = DIO_enuSetPinValue(copy_SWAstr.Switch_PortID,copy_SWAstr.Switch_PinID,copy_SWAstr.Switch_status);
	return Local_enuErrorState;
}
ES_t Switch_enuGetState(SW_t copy_SWAstr, u8 *copy_SWState)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 PinValue;
	if(copy_SWState == NULL)
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	else
	{
		Local_enuErrorState = DIO_enuGetPinValue(copy_SWAstr.Switch_PortID, copy_SWAstr.Switch_PinID,&PinValue);
		if(PinValue == 1)
		{
			*copy_SWState = SW_NOTPRESSED;
		}
		else if(PinValue == 0)
		{
			*copy_SWState = SW_PRESSED;
		}
	}
	return Local_enuErrorState;
}
