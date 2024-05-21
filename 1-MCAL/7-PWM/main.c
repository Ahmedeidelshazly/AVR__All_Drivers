#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "PWM_interface.h"

u8 Counter=0 ,degree;
void Test (void);
void main (void)
{
    u16 Local_u8Iterator;
    DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT_MODE);
    PWM_voidTimer1Init();
    PWM_voidSetICR1(20000);
    while (1)
    {
        Test ();
        if (Counter==1)
        {
            servo(degree);
            _delay_ms(1000);
        }
        else if (Counter==2)
        {
            servo(degree);
            _delay_ms(1000);
        }

        else if (Counter==3)
        {
            servo(degree);
            _delay_ms(1000);
        }

    }
    

  
}
void Test (void)
{
    Counter++;
    if (Counter == 1)
    {
        degree=0;
    }
    else if (Counter==2)
    {
        degree==90;
    }
    else if (Counter==3)
    {
        degree==180;
    }
}
