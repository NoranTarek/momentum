/*
 * DIO_Private.h
 *
 *  Created on: Feb 26, 2025
 *      Author: mylap
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define NULL    0

#define DDRA    *((volatile u8*)0x3B)
#define PORTA   *((volatile u8*)0x3A)
#define PINA    *((volatile u8*)0x39)

#define DDRB    *((volatile u8*)0x38)
#define PORTB   *((volatile u8*)0x37)
#define PINB    *((volatile u8*)0x36)

#define DDRC    *((volatile u8*)0x35)
#define PORTC   *((volatile u8*)0x34)
#define PINC    *((volatile u8*)0x33)

#define DDRD    *((volatile u8*)0x32)
#define PORTD   *((volatile u8*)0x31)
#define PIND    *((volatile u8*)0x30)

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)  CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#endif /* DIO_PRIVATE_H_ */
