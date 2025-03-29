/*
 * CALC.h
 *
 *  Created on: Mar 20, 2025
 *      Author: mylap
 */

#ifndef CALC_H_
#define CALC_H_

#define MAX 100

typedef struct
{
	float Data[MAX];
	int Top;
}Stack_Float;

void Calc(u8 *Equ);

void Reset(void);

#endif /* CALC_H_ */
