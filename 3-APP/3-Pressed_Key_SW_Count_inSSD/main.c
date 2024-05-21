#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SW_interface.h"
/******************************************************************************/
SSD_Type SSD_1 = { SSD_COMMON_CATHODE , DIO_PORTC,DIO_PORTC,DIO_PIN7};
SW_Type  SW_1  = { DIO_PORTA  ,DIO_PIN0,SW_Ext_PULL_UP};
/*******************************************************************************/

/*
void main (void)
{

	SSD_voidInit(SSD_1);
	SSD_voidEnable(SSD_1);
	SW_voidInit (SW_1);


	while (1)
	{

		u8 volatile SW_val = SW_u8GetPressed(SW_1) ;
		u8 var = 0 ;
		if( SW_val == SW_PRESSED_KEY )
		{
			SSD_voidDispalyNumber(SSD_1 , var ) ;
			var = (var + 1) % 10;
			_delay_ms(500) ;

			continue ;

		}

		else
		{

			SSD_voidDisable(SSD_1) ;
		}
	}
}
*/
void main (void )
{
	SSD_voidInit(SSD_1);
	SSD_voidEnable(SSD_1);
	u8 var = 0 ;
	u8 Local_u8Result=0 ;

	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT_PULL_UP_MODE);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT_MODE);


	while (1)
	{
		DIO_u8GetPinValue(DIO_PORTA , DIO_PIN0,&Local_u8Result);
		if (Local_u8Result ==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			SSD_voidDispalyNumber(SSD_1 , var ) ;
			var = (var + 1) % 10;
			_delay_ms(500) ;
			if (var == 10)
			{
				break;
			}

		}
		else if (Local_u8Result == 1)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);

		}

	}


}
