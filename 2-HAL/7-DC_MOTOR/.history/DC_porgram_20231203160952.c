#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DC_config.h"
#include "DC_private.h"
#include "DC_interface.h"

u8 DC_voidControl(DC_Configuration* config ,DC_StateType State )
{
    StdReturnType Retval=E_OK;
    switch (State)
    {
    case DC_CW: DIO_u8SetPinValue(config->DC_PORT,config->DC_PINA,DIO_PIN_LOW);
                DIO_u8SetPinValue(config->DC_PORT,config->DC_PINB,DIO_PIN_HIGH);
    break;
    case DC_CCW: DIO_u8SetPinValue(config->DC_PORT,config->DC_PINA,DIO_PIN_HIGH);
                 DIO_u8SetPinValue(config->DC_PORT,config->DC_PINB,DIO_PIN_LOW);
    break;
    case DC_STOP: DIO_u8SetPinValue(config->DC_PORT,config->DC_PINA,DIO_PIN_LOW);
                DIO_u8SetPinValue(config->DC_PORT,config->DC_PINB,DIO_PIN_LOW);
    break;

    default: Retval=E_NOT_OK; break;
    }

    return Retval ;
}