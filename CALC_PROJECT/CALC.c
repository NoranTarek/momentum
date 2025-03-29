/*
 * CALC.c
 *
 *  Created on: Mar 20, 2025
 *      Author: mylap
 */

#include "CALC.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KPD_int.h"

static void Float_init(Stack_Float *List);
static u8 Float_isEmpty (Stack_Float *List);
static u8 Float_isFull (Stack_Float *List);
static float Float_Top (Stack_Float *List);
static void Float_Pop(Stack_Float * List);
static void Float_Push(Stack_Float * List, float Data);

static float Calc_res(float Num1, float Num2, u8 sympol);

static u8 Get_Length(float Number);
static void evaluate(void);

u8 Operation[60];
static u8 Postfix[100];


static u8 Precedence(u8 Operator)
{
	switch (Operator)
	{
	case '*' :
	case '/' : return 2;
	case '+' :
	case '-' : return 1;
	}
	return 0;
}
void Calc(u8 *Equ)
{
	Stack_Float stack_t;
	Float_init(&stack_t);
	int j = 0;
	int i = 0;
	while (Equ[j] != '\0')
	{
		u8 Current = Equ[j];
		if ((Current <= '9' && Current >= '0') || Current == '.' )
		{
			while ((Current <= '9' && Current >= '0') || Current == '.' )
			{
				Postfix[i++] = Current;
				Current = Equ[++j];
			}
			Postfix[i++] = ' ';
		}
		else
		{
			while(!(Float_isEmpty(&stack_t)) && Precedence(Current) <= Precedence(Float_Top(&stack_t)))
			{
				Postfix[i++] = Float_Top(&stack_t);
				Float_Pop(&stack_t);
			}
			if (!Float_isFull(&stack_t))
			{
				Float_Push(&stack_t, Current);
			}
			j++;
		}
	}
	while (!Float_isEmpty(&stack_t))
	{
		Postfix[i++] = Float_Top(&stack_t);
		Float_Pop(&stack_t);
	}
	Postfix[i] = '\0';
	evaluate();
}

static void evaluate(void)
{
	Stack_Float stack_t;
	Float_init(&stack_t);

	int i = 0;
	u32 Num = 0;
	u8 Sympol = ' ';
	u8 Check = 1;
	u8 temp = 0;
	float Operand1, Operand2;
	float Res;
	float Float_Num = 0;
	u8 Flag_repeat = 1;
	u8 Flag_Div_0 = 1;
	while (Postfix[i] != '\0')
	{
		u8 Current = Postfix[i];

		if (Current <= '9' && Current >= '0')
		{
			while (Current <= '9' && Current >= '0')
			{
				Num = (Num * 10) + (int)(Current - '0');
				Current = Postfix[++i];
			}
			if (Current == '.' && Flag_repeat == 1)
			{
				Current = Postfix[++i];
				if (temp != Check)
				{
					float j = 0.1;
					while (Current <= '9' && Current >= '0')
					{
						Float_Num +=  ((Current - '0') * j) ;
						Current = Postfix[++i];
						j *= 0.1;
					}
					temp = Check;
				}
				else {
					Flag_repeat = 0;
					break;
				}
			}
			if (Current == ' ')
			{
				Float_Num += (float)Num;
				Check++;
				Float_Push(&stack_t, Float_Num);
				Num = 0;
				Float_Num = 0;
				i++;
				continue;
			}
		}
		else
		{
			Sympol = Current;
			Operand2 = Float_Top(&stack_t);
			Float_Pop(&stack_t);
			Operand1 = Float_Top(&stack_t);
			Float_Pop(&stack_t);
			if (Sympol == '/' && Operand2 == 0)
			{
				LCD_enuDisplayChar("X");
				Flag_Div_0 = 0;
			}
			else
			{
				Float_Push(&stack_t, Calc_res(Operand1, Operand2, Sympol));
				i++;
			}
			if (!Flag_Div_0) break;
		}
	}
	if (Flag_Div_0 && Flag_repeat)
	{
		Res = Float_Top(&stack_t);
		Float_Pop(&stack_t);
		int length = Get_Length(Res);
		LCD_enuDisplayChar(Res);
	}
}

static float Calc_res(float Num1, float Num2, u8 sympol)
{
	switch(sympol)
	{
	case '+':
		return Num1 + Num2;
		break;
	case '-':
		return Num1 - Num2;
		break;
	case '*':
		return Num1 * Num2;
		break;
	case '/':
		return Num1 / Num2;
	default : break;
	}
}

static void Float_init(Stack_Float *List)
{
	List->Top = 0;
}

static u8 Float_isEmpty (Stack_Float *List)
{
	return List->Top == 0;
}

static u8 Float_isFull (Stack_Float *List)
{
	return List->Top >= MAX;
}

static void Float_Push(Stack_Float * List, float Data)
{
	List->Data[(List->Top)++] = Data;
}

static void Float_Pop(Stack_Float * List)
{
	(List->Top)--;
}

static float Float_Top(Stack_Float *List)
{
	return (List->Data[List->Top - 1]);
}
static u8 Get_Length(float Number)
{
	u8 str[10] = {0};
	int Decimal;
	Decimal = (int)Number;
	sprintf(str, "%d", Decimal);
	volatile u8 length = 0;
	while(str[length++] != '\0');
	return length;
}
