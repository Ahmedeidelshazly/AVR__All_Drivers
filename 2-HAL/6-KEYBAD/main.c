#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"
#include "DIO_interface.h"
#include "KPD_interface.h"


void main (void )
{

	LCD_voidInit();
    u8 Local_u8Pressed;
    KPD_voidInit();
    while (1)
    {
        do 
        {
            Local_u8Pressed =KPD_GetPressedKey();
        }while (Local_u8Pressed == 0xff);

          LCD_voidDispalyNumber(Local_u8Pressed);
    }
}
