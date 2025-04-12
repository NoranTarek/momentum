/*
 * EXIT_priv.h
 *
 *  Created on: Dec 4, 2024
 *      Author: mylap
 */

#ifndef EXIT_PRIV_H_
#define EXIT_PRIV_H_

#define MCUCR_REG     *((volatile u8 *)0x55)
#define MCUCSR_REG    *((volatile u8 *)0x54)
#define GICR_REG      *((volatile u8 *)0x58)
#define GIFR_REG      *((volatile u8 *)0x5A)

#endif /* EXIT_PRIV_H_ */
