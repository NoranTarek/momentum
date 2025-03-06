/*
 * LCD_Configuration.h
 *
 *  Created on: Mar 4, 2025
 *      Author: mylap
 */

#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_

#define LCD_MODE  4

#define LCD_DATA_PORT      DIO_u8PORTA
/* RS,RW,EN */
#define LCD_CONTROL_PORT   DIO_u8PORTB

#define LCD_RS             DIO_u8PIN1
#define LCD_RW             DIO_u8PIN2
#define LCD_EN             DIO_u8PIN3

#endif /* LCD_CONFIGURATION_H_ */
