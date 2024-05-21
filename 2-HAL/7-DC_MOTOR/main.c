#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DC_interface.h"




DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT_MODE);
DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT_MODE);
DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT_MODE);
DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_OUTPUT_MODE);


DC_Configuration DC_1 =
{  DIO_PORTA,
	DIO_PIN0,
	DIO_PIN1
};
void main (void)
{
    Move_Forward();
    while (1)
    {

    }
}
