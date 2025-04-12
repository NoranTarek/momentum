/*
 * EXIT_prog.c
 *
 *  Created on: Dec 4, 2024
 *      Author: mylap
 */

#include "errorStates.h"
#include "stdTypes.h"
#include "EXIT_int.h"
#include "EXIT_config.h"
#include "EXIT_priv.h"

void (*EXTI_CallBack[3])(void) = {NULL};

void EXTI_VoidInit (void)
{
	#ifdef EXTI_LINE
		#if EXTI_LINE == EXTI_LINE1
			#if EXTI_SENSE_MODE == EXTI_LOW_LEVEL
				CLR_BIT(MCUCR_REG , 2);
				CLR_BIT(MCUCR_REG , 3);
			#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
				SET_BIT(MCUCR_REG , 2);
				CLR_BIT(MCUCR_REG , 3);
			#elif EXTI_SENSE_MODE == EXTI_FALLING_EDGE
				CLR_BIT(MCUCR_REG , 2);
				SET_BIT(MCUCR_REG , 3);
			#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
				SET_BIT(MCUCR_REG , 2);
				SET_BIT(MCUCR_REG , 3);
			#endif
		#elif EXTI_LINE == EXTI_LINE0
			#if EXTI_SENSE_MODE == EXTI_LOW_LEVEL
				CLR_BIT(MCUCR_REG , 0);
				CLR_BIT(MCUCR_REG , 1);
			#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
				SET_BIT(MCUCR_REG , 0);
				CLR_BIT(MCUCR_REG , 1);
			#elif EXTI_SENSE_MODE == EXTI_FALLING_EDGE
				CLR_BIT(MCUCR_REG , 0);
				SET_BIT(MCUCR_REG , 1);
			#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
				SET_BIT(MCUCR_REG , 0);
				SET_BIT(MCUCR_REG , 1);
			#endif
		#elif EXTI_LINE == EXTI_LINE2
			#if EXTI_SENSE_MODE == EXTI_FALLING_EDGE
				CLR_BIT(MCUCSR_REG , 6);
			#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
				SET_BIT(MCUCSR_REG , 6);
			#endif
		#endif
	#endif
}

void EXTI_SetSignalLatch (u8 Copy_u8SenseMode , u8 Copy_u8Line)
{
	if((Copy_u8Line >= EXTI_LINE0) && (Copy_u8Line <= EXTI_LINE1))
	{
		Copy_u8Line = (6 - Copy_u8Line) * -2;
		switch(Copy_u8SenseMode)
		{
		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG , Copy_u8Line);
			CLR_BIT(MCUCR_REG , Copy_u8Line+1);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR_REG , Copy_u8Line);
			CLR_BIT(MCUCR_REG , Copy_u8Line+1);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG , Copy_u8Line);
			SET_BIT(MCUCR_REG , Copy_u8Line+1);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG , Copy_u8Line);
			SET_BIT(MCUCR_REG , Copy_u8Line+1);
			break;
		}
	}
	else
	{
		switch(Copy_u8SenseMode)
		{
		case EXTI_FALLING_EDGE :
			CLR_BIT(MCUCSR_REG , 6);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR_REG , 6);
			break;
		}
	}
}

u8 EXIT_VoidDisableInterrupt(u8 Copy_u8Line)
{
	ES_t Local_ErrorState = ES_NOK;
	if((Copy_u8Line > EXTI_LINE2) && (Copy_u8Line < EXTI_LINE1))
	{
		CLR_BIT(GICR_REG , Copy_u8Line);
		Local_ErrorState = ES_OK;
	}
	return Local_ErrorState;
}

u8 EXIT_VoidEnableInterrupt(u8 Copy_u8Line)
{
	ES_t Local_ErrorState = ES_NOK;
	if((Copy_u8Line > EXTI_LINE2) && (Copy_u8Line < EXTI_LINE1))
	{
		SET_BIT(GICR_REG , Copy_u8Line);
		Local_ErrorState = ES_OK;
	}
	return Local_ErrorState;
}

void EXTI_voidClearFlag(u8 Copy_u8Line)
{
	SET_BIT(GIFR_REG , Copy_u8Line);
}

u8 EXTI_voidGetFlag(u8 Copy_u8Line)
{
	return (1&(GIFR_REG>>Copy_u8Line));
}

void EXTI_voidSetCallBack(void(*Copy_pvoidCallBack)(void),u8 Copy_u8EXTILine)
{
	if(Copy_pvoidCallBack != NULL)
	{
		EXTI_CallBack[Copy_u8EXTILine] = Copy_pvoidCallBack;
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_CallBack[0] != NULL)
	{
		EXTI_CallBack[0]();
		EXTI_voidClearFlag(EXTI_LINE2);
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_CallBack[1] != NULL)
	{
		EXTI_CallBack[1]();
		EXTI_voidClearFlag(EXTI_LINE2);
	}
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_CallBack[2] != NULL)
	{
		EXTI_CallBack[2]();
		EXTI_voidClearFlag(EXTI_LINE2);
	}
}

void SET_BIT(u8 Copy_u8Reg , u8 Copy_u8Bit)
{
	Copy_u8Reg |= (1<<Copy_u8Bit);
}

void CLR_BIT(u8 Copy_u8Reg , u8 Copy_u8Bit)
{
	Copy_u8Reg &= ~(1<<Copy_u8Bit);
}


