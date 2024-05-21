/*
 * main.c
 *
 *  Created on: Mar 2, 2024
 *      Author: Ahmed Elshazly
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "USART_interface.h"
#include "DIO_interface.h"
int main (void)
{
	u8 Local_u8Result;
	PORT_voidInit();
	USART_voidInit();
	USART_voidTransmit_String_Synchronous("Send o for make the led on\r\nsend f for make the led off");
	while (1)
	{

		Local_u8Result =USART_u8ReceiveSynchronous();
		switch (Local_u8Result)
		{
		case 'o':
			USART_voidTransmit_String_Synchronous("\r\nLED ON");
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			break;
		case 'f':
			USART_voidTransmit_String_Synchronous("\r\nLED ON");
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			break;
		default : break;
		}

	}
}
