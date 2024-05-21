/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : HAL               ***************/
/*********     SWC    : LED               ***************/
/********************************************************/
/********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "LED_config.h"
#include "LED_private.h"
#include "LED_interface.h"


/**********************Intiliaze configuration for the led only ************************/
void LED_voidInit (LED_Type LED_Configurtion)
{
    DIO_u8SetPinDirection(LED_Configurtion.Port,LED_Configurtion.Pin , DIO_OUTPUT_MODE);
}

/**************************Turn on led ************************************************/
void Led_Turn_On (LED_Type LED_Configurtion )
{
    if (LED_Configurtion.State==ACTIVE_HIGH)
    DIO_u8SetPinValue(LED_Configurtion.Port , LED_Configurtion.Pin , DIO_PIN_HIGH);

    else if (LED_Configurtion.State==ACTIVE_LOW)
    DIO_u8SetPinValue(LED_Configurtion.Port , LED_Configurtion.Pin , DIO_PIN_LOW);

}


/**************************Turn off led ************************************************/
void Led_Turn_Off (LED_Type LED_Configurtion )
{
    if (LED_Configurtion.State==ACTIVE_HIGH)
    DIO_u8SetPinValue(LED_Configurtion.Port , LED_Configurtion.Pin , DIO_PIN_LOW);

    else if (LED_Configurtion.State==ACTIVE_LOW)
    DIO_u8SetPinValue(LED_Configurtion.Port , LED_Configurtion.Pin , DIO_PIN_HIGH);

}

/**************************Toggle led  ************************************************/

void Led_Toggle   (LED_Type LED_Configurtion )
{
    Dio_FlipPinLevel(LED_Configurtion.Port ,LED_Configurtion.Pin);
}
