/*
 * LED_Interface.h
 *
 *  Created on: Feb 26, 2025
 *      Author: mylap
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef struct
{
	u8 Port;
	u8 Pin;
	u8 Active_State;
}LED_t;

#define ACTIVE_HIGH  1
#define ACTIVE_LOW   0

ES_t LED_enuInit(LED_t Copy_pstrLed);

ES_t LED_enuTurnON(LED_t Copy_pstrLedID);

ES_t LED_enuTurnOFF(LED_t Copy_pstrLedID);

ES_t LED_enuToggle(LED_t Copy_pstrLedID);

#endif /* LED_INTERFACE_H_ */
