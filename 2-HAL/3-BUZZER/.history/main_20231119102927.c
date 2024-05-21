#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "BUZZER_interface.h"


void main (void )
{
    int counter =0 ;
    BUZZER_voidInit();
    BUZZER_voidOn();

    while (1)
    {
        counter ++;
        if (counter == 15)
        {
            BUZZER_voidOff();
        }

    }


}