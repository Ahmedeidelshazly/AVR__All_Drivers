#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"

void main (void)
{
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