#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "BUZZER_interface.h"


void main (void )
{
    BUZZER_voidInit();


    while (1)
    {
    	 BUZZER_voidOn();
    	 _delay_ms(1000);
    	 BUZZER_voidOff();
    	 _delay_ms(1000);


    }


}
