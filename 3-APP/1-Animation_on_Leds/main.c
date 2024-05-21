/*
 * main.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Ahmed Elshazly
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_register.h"
#include <util/delay.h>
#include "DIO_interface.h"

int main (void)
{

	DIO_u8SetPortDirection(DIO_PORTA,0xff); // for eight leds
	DIO_u8SetPortDirection(DIO_PORTB,0); // for dipper switches
	DIO_u8SetPortValue(DIO_PORTB,0xff);  // set the switches as a input pull up
	/*input pull means set the direction 0 for input and set the value 1 for pull up --> active low switch */
	while (1)
	{
		if ((GET_BIT(PINB,DIO_PIN0)) ==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
		}
		else if ((GET_BIT(PINB,DIO_PIN1)) ==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		}
		else if ((GET_BIT(PINB,DIO_PIN2)) ==0)
		{
			DIO_u8TogglePin(DIO_PORTA,DIO_PIN0);
			DIO_u8TogglePin(DIO_PORTA,DIO_PIN1);
			DIO_u8TogglePin(DIO_PORTA,DIO_PIN2);
			DIO_u8TogglePin(DIO_PORTA,DIO_PIN3);
			DIO_u8TogglePin(DIO_PORTA,DIO_PIN4);
			DIO_u8TogglePin(DIO_PORTA,DIO_PIN5);
			DIO_u8TogglePin(DIO_PORTA,DIO_PIN6);
			DIO_u8TogglePin(DIO_PORTA,DIO_PIN7);
			_delay_ms(100);

		}
		else if ((GET_BIT(PINB,DIO_PIN3)) ==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
		}
		else if ((GET_BIT(PINB,DIO_PIN4)) ==0)
		{

			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);

		}
		else if ((GET_BIT(PINB,DIO_PIN5)) ==0)
		{

			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);

			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);


			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);

		}
		if ((GET_BIT(PINB,DIO_PIN6)) ==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		}

		else if ((GET_BIT(PINB,DIO_PIN7)) ==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPortValue(DIO_PORTA,0xff);
		}

	}
}

