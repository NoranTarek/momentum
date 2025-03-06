/*
 * LCD_Program.c
 *
 *  Created on: Mar 4, 2025
 *      Author: mylap
 */

#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "MATH_BIT.h"

#include "DIO_int.h"

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Configuration.h"



void CLCD_voidInit        ( void )
{
	#if   CLCD_MODE == 8

	_delay_ms(50);

	DIO_enumSetPortDirection ( CLCD_DATA_PORT    , DIO_PORT_OUTPUT           );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT  );

	CLCD_voidSendCommand(lcd_Home);
	_delay_ms(1);

	CLCD_voidSendCommand( EIGHT_BITS );
	_delay_ms(1);

	CLCD_voidSendCommand( lcd_DisplayOn_CursorOff );
	_delay_ms(1);


	CLCD_voidClearScreen();

	CLCD_voidSendCommand( lcd_EntryMode );
	_delay_ms(1);




	#elif   CLCD_MODE == 4

	_delay_ms(50);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT  );



	CLCD_voidSendCommand( lcd_Home );
	_delay_ms(30);

	CLCD_voidSendCommand( FOUR_BITS );
	_delay_ms(1);

	CLCD_voidSendCommand( lcd_DisplayOn_CursorOff );
	_delay_ms(1);

	CLCD_voidClearScreen();

	CLCD_voidSendCommand( lcd_EntryMode );
	_delay_ms(1);


	#endif




}

void CLCD_voidSendData    ( u8 Copy_u8Data ){

	#if   CLCD_MODE == 8

	DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Data        );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	CLCD_voidSendFallingEdge();

	#elif   CLCD_MODE == 4

	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,(Copy_u8Data>>4));
	CLCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Data);
	CLCD_voidSendFallingEdge();

	#endif

	_delay_ms(1);

}


void CLCD_voidSendCommand ( u8 Copy_u8Command ){

	#if   CLCD_MODE == 8

	DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Command     );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	DIO_enumSetPinValue          (CLCD_CONTROL_PORT,CLCD_RW , DIO_PIN_LOW    );
	CLCD_voidSendFallingEdge();

	#elif   CLCD_MODE == 4

	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command>>4);
	CLCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command);
	CLCD_voidSendFallingEdge();

	#endif

	_delay_ms(1);

}


void CLCD_voidSendString  ( const u8 * Copy_u8ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[LOC_u8Iterator] != '\0' ){

		CLCD_voidSendData( Copy_u8ptrString[LOC_u8Iterator] );
		LOC_u8Iterator++ ;

	}

}


void CLCD_voidSendNumber   ( u64 Copy_u64Number    ){

	u64 LOC_u64Reversed = 1 ;

	if( Copy_u64Number == 0 ){ CLCD_voidSendData('0'); }

	else{

		while( Copy_u64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
			Copy_u64Number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			CLCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}


void CLCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col ){

	u8 LOC_u8data ;

	if(Copy_u8Row>2||Copy_u8Row<1||Copy_u8Col>16||Copy_u8Col<1)  //check
	{
		LOC_u8data = lcd_SetCursor ;   // first location
	}

	else if( Copy_u8Row == CLCD_ROW_1 ){

		LOC_u8data = ( ( lcd_SetCursor ) + ( Copy_u8Col - 1 ) );

	}

	else if( Copy_u8Row == CLCD_ROW_2 ){

		LOC_u8data = ( ( lcd_SetCursor ) + (64) + ( Copy_u8Col - 1 ) );

	}
	CLCD_voidSendCommand ( LOC_u8data );
	_delay_ms(1);

}


void CLCD_voidClearScreen(void)
{
	CLCD_voidSendCommand(lcd_Clear);
	_delay_ms(10);
}


static void CLCD_voidSendFallingEdge(void)
{
	DIO_enuSetPinValue   ( LCD_CONTROL_PORT , LCD_EN , DIO_u8HIGH );
	_delay_ms(1);
	DIO_enuSetPinValue  ( LCD_CONTROL_PORT , LCD_EN , DIO_u8LOW  );
	_delay_ms(1);
}
