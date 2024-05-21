#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include"SSD_interface.h"


void main (void )
{
    SSD_Type SSD_1 ={SSD_COMMON_CATHODE,DIO_PORTA,DIO_PORTA,DIO_PIN7};
    SSD_voidInit(SSD_1);
    SSD_voidEnable(SSD_1);

    while (1)
    {
        for (int i=0 ;i<=9 ; i++)
        {
        	for (int j=0 ;j<10000 ; j++)
        	{
                SSD_voidDispalyNumber(SSD_1,i);

        	}
        }
    }

}


/*another method */
/*
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include"SSD_interface.h"


void main (void )
{
    SSD_Type SSD_1 ={SSD_COMMON_CATHODE,DIO_PORTA,DIO_PORTA,DIO_PIN7};
    SSD_voidInit(SSD_1);
    SSD_voidEnable(SSD_1);

    while (1)
    {
        for (int i=0 ;i<=9 ; i++)
        {

                SSD_voidDispalyNumber(SSD_1,i);
                _delay_ms(1000);

        }
    }

}
*/