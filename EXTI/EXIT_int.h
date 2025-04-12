/*
 * EXIT_int.h
 *
 *  Created on: Dec 4, 2024
 *      Author: mylap
 */

#ifndef EXIT_INT_H_
#define EXIT_INT_H_

#define EXTI_LINE0  6
#define EXTI_LINE1  7
#define EXTI_LINE2  5

#define EXTI_FALLING_EDGE   0
#define EXTI_RISING_EDGE    1
#define EXTI_LOW_LEVEL      2
#define EXTI_ON_CHANGE      3

void EXTI_VoidInit (void);

void EXTI_SetSignalLatch (u8 Copy_u8SenseMode , u8 Copy_u8Line);

u8 EXIT_VoidDisableInterrupt(u8 Copy_u8Line);

u8 EXIT_VoidEnableInterrupt(u8 Copy_u8Line);

void EXTI_voidClearFlag(u8 Copy_u8Line);

u8 EXTI_voidGetFlag(u8 Copy_u8Line);

void EXTI_voidSetCallBack(void(*Copy_pvoidCallBack)(void),u8 Copy_u8EXTILine);

void SET_BIT(u8 Copy_u8Reg , u8 Copy_u8Bit);

void CLR_BIT(u8 Copy_u8Reg , u8 Copy_u8Bit);

#endif /* EXIT_INT_H_ */
