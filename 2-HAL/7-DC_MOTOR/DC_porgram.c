#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DC_config.h"
#include "DC_private.h"
#include "DC_interface.h"

DC_Configuration DC_1 =
{  DIO_PORTA,
	DIO_PIN0,
	DIO_PIN1
};

DC_Configuration DC_2 =
{  DIO_PORTA,
	DIO_PIN2,
	DIO_PIN3
};

u8 DC_voidControl(DC_Configuration* config ,DC_StateType State )
{
    StdReturnType Retval=E_OK;
    switch (State)
    {
    case DC_CW: DIO_u8SetPinValue(config->DC_PORT,config->DC_PINA,DIO_PIN_LOW);
                DIO_u8SetPinValue(config->DC_PORT,config->DC_PINB,DIO_PIN_HIGH);
    break;
    case DC_ACW: DIO_u8SetPinValue(config->DC_PORT,config->DC_PINA,DIO_PIN_HIGH);
                 DIO_u8SetPinValue(config->DC_PORT,config->DC_PINB,DIO_PIN_LOW);
    break;
    case DC_STOP: DIO_u8SetPinValue(config->DC_PORT,config->DC_PINA,DIO_PIN_LOW);
                DIO_u8SetPinValue(config->DC_PORT,config->DC_PINB,DIO_PIN_LOW);
    break;
    default: Retval=E_NOT_OK; break;
    }

    return Retval ;
}

void Move_Forward (void)
{
    DC_voidControl(&DC_1,DC_CW);
    DC_voidControl(&DC_2,DC_CW);
}

void Move_Backword (void)
{
    DC_voidControl(&DC_1,DC_ACW);
    DC_voidControl(&DC_2,DC_ACW);
}

void Move_Right(void)
{
    DC_voidControl(&DC_1,DC_ACW);
    DC_voidControl(&DC_2,DC_STOP);

}

void Move_Left(void)
{
    DC_voidControl(&DC_1,DC_STOP);
    DC_voidControl(&DC_2,DC_ACW);

}

void Motor_Stop(void)
{
    DC_voidControl(&DC_1,DC_STOP);
    DC_voidControl(&DC_2,DC_STOP);

}

void Motor_Rotate_Right_By90(void)
{
    Move_Right();
    _delay_ms(1500);
    Motor_Stop();
}

void Motor_Rotate_Left_By90(void)
{
    Move_Left();
    _delay_ms(1500);
    Motor_Stop();
}