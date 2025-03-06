/*
 * DIO_Program.c
 *
 *  Created on: Feb 26, 2025
 *      Author: mylap
 */

#include "STD_Types.h"
#include "ErrorState.h"
#include "MATH_BIT.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Configuration.h"

ES_t DIO_enuInit(void)
{
	ES_t Local_enuErrorstate = ES_NOK;
	DDRA = CONC(PA_PIN7_DIR,PA_PIN6_DIR,PA_PIN5_DIR,PA_PIN4_DIR,PA_PIN3_DIR,PA_PIN2_DIR,PA_PIN1_DIR,PA_PIN0_DIR);
	DDRB = CONC(PB_PIN7_DIR,PB_PIN6_DIR,PB_PIN5_DIR,PB_PIN4_DIR,PB_PIN3_DIR,PB_PIN2_DIR,PB_PIN1_DIR,PB_PIN0_DIR);
	DDRC = CONC(PC_PIN7_DIR,PC_PIN6_DIR,PC_PIN5_DIR,PC_PIN4_DIR,PC_PIN3_DIR,PC_PIN2_DIR,PC_PIN1_DIR,PC_PIN0_DIR);
	DDRD = CONC(PD_PIN7_DIR,PD_PIN6_DIR,PD_PIN5_DIR,PD_PIN4_DIR,PD_PIN3_DIR,PD_PIN2_DIR,PD_PIN1_DIR,PD_PIN0_DIR);

	PORTA = CONC(PA_PIN7_VAL,PA_PIN6_VAL,PA_PIN5_VAL,PA_PIN4_VAL,PA_PIN3_VAL,PA_PIN2_VAL,PA_PIN1_VAL,PA_PIN0_VAL);
	PORTB = CONC(PB_PIN7_VAL,PB_PIN6_VAL,PB_PIN5_VAL,PB_PIN4_VAL,PB_PIN3_VAL,PB_PIN2_VAL,PB_PIN1_VAL,PB_PIN0_VAL);
	PORTC = CONC(PC_PIN7_VAL,PC_PIN6_VAL,PC_PIN5_VAL,PC_PIN4_VAL,PC_PIN3_VAL,PC_PIN2_VAL,PC_PIN1_VAL,PC_PIN0_VAL);
	PORTD = CONC(PD_PIN7_VAL,PD_PIN6_VAL,PD_PIN5_VAL,PD_PIN4_VAL,PD_PIN3_VAL,PD_PIN2_VAL,PD_PIN1_VAL,PD_PIN0_VAL);

	Local_enuErrorstate = ES_OK;

	return Local_enuErrorstate;
}

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value)
{
	ES_t Local_EnuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_u8PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_u8PORTA: DDRA = Copy_u8Value; break;
		case DIO_u8PORTB: DDRB = Copy_u8Value; break;
		case DIO_u8PORTC: DDRC = Copy_u8Value; break;
		case DIO_u8PORTD: DDRD = Copy_u8Value; break;
		}
		Local_EnuErrorState = ES_OK;
	}
	else
	{
		Local_EnuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_EnuErrorState;
}
ES_t DIO_enuSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value)
{
	ES_t Local_EnuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_u8PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_u8PORTA: PORTA = Copy_u8Value; break;
		case DIO_u8PORTB: PORTB = Copy_u8Value; break;
		case DIO_u8PORTC: PORTC = Copy_u8Value; break;
		case DIO_u8PORTD: PORTD = Copy_u8Value; break;
		}
		Local_EnuErrorState = ES_OK;
	}
	else
	{
		Local_EnuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_EnuErrorState;
}
ES_t DIO_enuTogPort(u8 Copy_u8PortID)
{
	ES_t Local_EnuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_u8PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_u8PORTA: PORTA = ~PORTA; break;
		case DIO_u8PORTB: PORTB = ~PORTB; break;
		case DIO_u8PORTC: PORTC = ~PORTC; break;
		case DIO_u8PORTD: PORTD = ~PORTD; break;
		}
		Local_EnuErrorState = ES_OK;
	}
	else
	{
		Local_EnuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_EnuErrorState;
}
ES_t DIO_enuGetPortValue(u8 Copy_u8PortID , u8 *Copy_u8Value)
{
	ES_t Local_EnuErrorState = ES_NOK;
	if(Copy_u8Value == NULL)
	{
		Local_EnuErrorState = ES_NULL_POINTER;
	}
	else
	{
		if(Copy_u8PortID <= PORTD)
		{
			switch(Copy_u8PortID)
			{
			case DIO_u8PORTA: *Copy_u8Value = PINA; break;
			case DIO_u8PORTB: *Copy_u8Value = PINB; break;
			case DIO_u8PORTC: *Copy_u8Value = PINC; break;
			case DIO_u8PORTD: *Copy_u8Value = PIND; break;
			}
			Local_EnuErrorState = ES_OK;
		}
		else
		{
			Local_EnuErrorState = ES_OUT_OF_RANGE;
		}
	}
	return Local_EnuErrorState;
}
ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value)
{
	ES_t Local_EnuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_u8PORTD && Copy_u8PinID <= DIO_u8PIN7 && Copy_u8Value <= DIO_u8OUTPUT)
	{
		if(Copy_u8Value == DIO_u8OUTPUT)
		{
			switch(Copy_u8PortID)
			{
			case DIO_u8PORTA: SET_BIT(DDRA,Copy_u8PinID); break;
			case DIO_u8PORTB: SET_BIT(DDRB,Copy_u8PinID); break;
			case DIO_u8PORTC: SET_BIT(DDRC,Copy_u8PinID); break;
			case DIO_u8PORTD: SET_BIT(DDRD,Copy_u8PinID); break;
			}
		}
		else if(Copy_u8Value == DIO_u8INPUT)
		{
			switch(Copy_u8PortID)
			{
			case DIO_u8PORTA: CLR_BIT(DDRA,Copy_u8PinID); break;
			case DIO_u8PORTB: CLR_BIT(DDRB,Copy_u8PinID); break;
			case DIO_u8PORTC: CLR_BIT(DDRC,Copy_u8PinID); break;
			case DIO_u8PORTD: CLR_BIT(DDRD,Copy_u8PinID); break;
			}
		}
		Local_EnuErrorState = ES_OK;
	}
	else
	{
		Local_EnuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_EnuErrorState;
}
ES_t DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
	ES_t Local_EnuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_u8PORTD && Copy_u8PinID <= DIO_u8PIN7 && Copy_u8Value <= DIO_u8OUTPUT)
	{
		if(Copy_u8Value == DIO_u8OUTPUT)
		{
			switch(Copy_u8PortID)
			{
			case DIO_u8PORTA: SET_BIT(PORTA,Copy_u8PinID); break;
			case DIO_u8PORTB: SET_BIT(PORTB,Copy_u8PinID); break;
			case DIO_u8PORTC: SET_BIT(PORTC,Copy_u8PinID); break;
			case DIO_u8PORTD: SET_BIT(PORTD,Copy_u8PinID); break;
			}
		}
		else if(Copy_u8Value == DIO_u8INPUT)
		{
			switch(Copy_u8PortID)
			{
			case DIO_u8PORTA: CLR_BIT(PORTA,Copy_u8PinID); break;
			case DIO_u8PORTB: CLR_BIT(PORTB,Copy_u8PinID); break;
			case DIO_u8PORTC: CLR_BIT(PORTC,Copy_u8PinID); break;
			case DIO_u8PORTD: CLR_BIT(PORTD,Copy_u8PinID); break;
			}
		}
		Local_EnuErrorState = ES_OK;
	}
	else
	{
		Local_EnuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_EnuErrorState;
}
ES_t DIO_enuTogPin(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	ES_t Local_EnuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_u8PORTD && Copy_u8PinID <= DIO_u8PIN7)
	{
		switch(Copy_u8PortID)
		{
		case DIO_u8PORTA: TOG_BIT(DDRA,Copy_u8PinID); break;
		case DIO_u8PORTB: TOG_BIT(DDRB,Copy_u8PinID); break;
		case DIO_u8PORTC: TOG_BIT(DDRC,Copy_u8PinID); break;
		case DIO_u8PORTD: TOG_BIT(DDRD,Copy_u8PinID); break;
		}
	}
	else
	{
		Local_EnuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_EnuErrorState;
}
ES_t DIO_enuGetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 *Copy_u8Value)
{
	ES_t Local_EnuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_u8PORTD && Copy_u8PinID <= DIO_u8PIN7 && *Copy_u8Value <= DIO_u8OUTPUT)
	{
		switch(Copy_u8PortID)
		{
		case DIO_u8PORTA: *Copy_u8Value = GET_BIT(PINA,Copy_u8PinID); break;
		case DIO_u8PORTB: *Copy_u8Value = GET_BIT(PINB,Copy_u8PinID); break;
		case DIO_u8PORTC: *Copy_u8Value = GET_BIT(PINC,Copy_u8PinID); break;
		case DIO_u8PORTD: *Copy_u8Value = GET_BIT(PIND,Copy_u8PinID); break;
		}
		Local_EnuErrorState = ES_OK;

	}
	else
	{
		Local_EnuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_EnuErrorState;
}
