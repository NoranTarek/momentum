/*
 * KPD_config.h
 *
 *  Created on: Oct 17, 2024
 *      Author: mylap
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_NOT_PRESSED_KEY   20

#define KPD_ARR {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define KPD_ROW0_PORT  DIO_PORTA
#define KPD_ROW0_PIN   DIO_PIN1

#define KPD_ROW1_PORT  DIO_PORTA
#define KPD_ROW1_PIN   DIO_PIN4

#define KPD_ROW2_PORT  DIO_PORTA
#define KPD_ROW2_PIN   DIO_PIN7

#define KPD_ROW3_PORT  DIO_PORTB
#define KPD_ROW3_PIN   DIO_PIN0

#define KPD_COL0_PORT  DIO_PORTB
#define KPD_COL0_PIN   DIO_PIN5

#define KPD_COL1_PORT  DIO_PORTB
#define KPD_COL1_PIN   DIO_PIN6

#define KPD_COL2_PORT  DIO_PORTC
#define KPD_COL2_PIN   DIO_PIN2

#define KPD_COL3_PORT  DIO_PORTC
#define KPD_COL3_PIN   DIO_PIN4

#endif /* KPD_CONFIG_H_ */
