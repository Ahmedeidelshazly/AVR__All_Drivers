/*
 * main.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Ahmed Elshazly
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SSD_interface.h"
#include "DIO_register.h"
#include <util/delay.h>
#include "DIO_interface.h"

SSD_Type SSD_1 =
{
		SSD_COMMON_CATHODE,
		DIO_PORTA,
		DIO_PORTA,
		DIO_PIN7,
};

SSD_Type SSD_2 =
{
		SSD_COMMON_CATHODE,
		DIO_PORTB,
		DIO_PORTB,
		DIO_PIN7,
};

int main (void)
{
	int i ,j;
	SSD_voidInit(SSD_1);
	SSD_voidInit(SSD_2);
	/* I need three leds for traffic light ==> Output Leds */
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_OUTPUT_MODE);

	while (1)
	{

		for ( i=0 ;i<=15;i++)
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
			if (i<=9)
			{
				SSD_voidDispalyNumber(SSD_1,i);
				SSD_voidDisable(SSD_2);
			}
			else
			{
				SSD_voidDispalyNumber(SSD_1,i-10);
				SSD_voidDispalyNumber(SSD_2,1);
			}
			_delay_ms(1000);

		}
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		for ( i=0 ;i<=5;i++)
		{
			SSD_voidDisable(SSD_2);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
			SSD_voidDispalyNumber(SSD_1,i);
			_delay_ms(1000);

		}
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		for ( i=0 ;i<=15;i++)
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
			if (i<=9)
			{
				SSD_voidDisable(SSD_2);
				SSD_voidDispalyNumber(SSD_1,i);
			}
			else
			{
				SSD_voidDispalyNumber(SSD_1,i-10);
				SSD_voidDispalyNumber(SSD_2,1);
			}
			_delay_ms(1000);

		}
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
	}
}

