/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : HAL               ***************/
/*********     SWC    : LED               ***************/
/********************************************************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"


#include "LED_interface.h"
#include "DIO_interface.h"


void main (void )
{



    LED_Type LED1 = { DIO_PORTA , DIO_PIN0 , ACTIVE_HIGH};
    LED_Type LED2 = { DIO_PORTA , DIO_PIN1 , ACTIVE_HIGH};
    LED_Type LED3 = { DIO_PORTA , DIO_PIN2 , ACTIVE_HIGH};

    LED_voidInit(LED1);
    LED_voidInit(LED2);
    LED_voidInit(LED3);

    while (1)
    {

        u8 counter = 1;
        while (1)
        {
			if (counter % 1 ==0)
			{
			 Led_Toggle(LED1);

			}
			if (counter % 2 ==0)
			{
				Led_Toggle(LED2);

			}
			if (counter %3 ==0)
			{
				Led_Toggle(LED3);

			}
			counter ++ ;
			_delay_ms(1000);
        }
    }



}
