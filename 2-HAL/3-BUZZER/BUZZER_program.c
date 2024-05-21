/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : HAL              ************/
/*********     SWC    :BUZZER            ************/
/****************************************************/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "BUZZER_config.h"
#include "BUZZER_interface.h"
#include "BUZZER_private.h"
#include "BUZZER_interface.h"

void BUZZER_voidInit()
{
    /* set the two pins as a output pins */
    DIO_u8SetPinDirection (BUZZER_PORT , BUZZER_PIN_POSTIVER, DIO_OUTPUT_MODE);
    DIO_u8SetPinDirection (BUZZER_PORT , BUZZER_PIN_NEGATIVE, DIO_OUTPUT_MODE);

    /* set the two pins as a output low */
    DIO_u8SetPinValue(BUZZER_PORT , BUZZER_PIN_POSTIVER,DIO_PIN_LOW);
    DIO_u8SetPinValue(BUZZER_PORT , BUZZER_PIN_NEGATIVE,DIO_PIN_LOW);

}

void BUZZER_voidOn()
{
    /*set postive pin and reset negative pin or closed it */
    DIO_u8SetPinValue(BUZZER_PORT , BUZZER_PIN_POSTIVER,DIO_PIN_HIGH);
    DIO_u8SetPinValue(BUZZER_PORT , BUZZER_PIN_NEGATIVE,DIO_PIN_LOW);

}
void BUZZER_voidOff()
{
    
    /*clear postive pin and set negative pin  */
    DIO_u8SetPinValue(BUZZER_PORT , BUZZER_PIN_POSTIVER,DIO_PIN_LOW);
    DIO_u8SetPinValue(BUZZER_PORT , BUZZER_PIN_NEGATIVE,DIO_PIN_HIGH);



}
