/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: Ahmed Elshazly
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "SPI_interface.h"

int main (void)
{
	u8 Local_u8Result;

	PORT_voidInit();
	SPI_voidMasterInit();
	while (1)
	{
		SPI_u8Tranceive(1,&Local_u8Result);
		_delay_ms(10);

	}
}
