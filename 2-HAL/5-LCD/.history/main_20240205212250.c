#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"

void main (void)
{
    DIO_u8SetPortValue(DIO_PORTA,DIO_HIGH);
    DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
    DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
    DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
    LCD_voidInit();
    unsigned char Number[] = {
        0b00100,
        0b00100,
        0b00100,
        0b11111,
        0b10001,
        0b10001,
        0b10001,
        0b00000
    };
    LCD_voidWriteSpecialCharacter(&Number,0,0,0);
    while (1)
    {

    }
}