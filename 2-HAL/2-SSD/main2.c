#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include"SSD_interface.h"


void main (void )
{
	SSD_Type SSD_1 ={SSD_COMMON_CATHODE,DIO_PORTA,DIO_PORTB,DIO_PIN0};
	SSD_Type SSD_2 ={SSD_COMMON_CATHODE,DIO_PORTA,DIO_PORTB,DIO_PIN1};
	SSD_voidInit(SSD_1);
	SSD_voidInit(SSD_2);

	while (1)
	{
		for (int i = 0; i <= 9; i++)
		{
			// Display on SSD_1 (count up)
			SSD_voidDisable(SSD_2);
			SSD_voidEnable(SSD_1);
			SSD_voidDispalyNumber(SSD_1, i);

			_delay_ms(20); // Adjust delay as needed

			// Display on SSD_2 (count down)
			SSD_voidDisable(SSD_1);
			SSD_voidEnable(SSD_2);
			SSD_voidDispalyNumber(SSD_2, 9 - i);

			_delay_ms(20); // Adjust delay as needed
		}
	}
}
