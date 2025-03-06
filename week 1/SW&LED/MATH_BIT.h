/*
 * MATH_BIT.h
 *
 *  Created on: Feb 26, 2025
 *      Author: mylap
 */

#ifndef MATH_BIT_H_
#define MATH_BIT_H_

#define SET_BIT(reg,bit)  reg|=(1<<bit)
#define CLR_BIT(reg,bit)  reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)  reg^=(1<<bit)
#define GET_BIT(reg,bit)  ((reg>>bit)&1)

#endif /* MATH_BIT_H_ */
