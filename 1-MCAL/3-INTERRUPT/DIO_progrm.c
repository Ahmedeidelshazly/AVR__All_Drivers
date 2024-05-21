/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : DIO               ***************/
/********************************************************/
/********************************************************/


/*Includes Libarary*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*Includes Relative files */
#include "DIO_config.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_interface.h"



u8  DIO_u8SetPortDirection (DIO_PortType port ,u8 Copy_u8Direciton )
{
    StdReturnType ReturnValue = E_OK;

    switch (port)
    {
    case DIO_PORTA: DDRA = Copy_u8Direciton ; break;
    case DIO_PORTB: DDRB = Copy_u8Direciton ; break;  
    case DIO_PORTC: DDRC = Copy_u8Direciton ; break;
    case DIO_PORTD: DDRD = Copy_u8Direciton ; break;
        
    default:ReturnValue=E_NOT_OK; break;
    }

    return ReturnValue;
}


u8 DIO_u8SetPortValue (DIO_PortType port ,u8 Copy_u8Value )
{
    StdReturnType ReturnValue = E_OK;

    switch (port)
    {
    case DIO_PORTA: PORTA = Copy_u8Value ; break;
    case DIO_PORTB: PORTB = Copy_u8Value ; break;  
    case DIO_PORTC: PORTC = Copy_u8Value ; break;
    case DIO_PORTD: PORTD = Copy_u8Value ; break;
        
    default:ReturnValue=E_NOT_OK; break;
    }

    return ReturnValue;
}


/**************************************************************************************/
u8 DIO_u8SetPinDirection (DIO_PortType port ,DIO_PinType pin , DIO_PinMode mode)
{
    StdReturnType ReturnValue=E_OK;
    if (pin>=DIO_PIN0 && pin<=DIO_PIN7)
    {
        switch (port)
        {
            case DIO_PORTA: 
                switch (mode)
                {
                    case DIO_OUTPUT_MODE:         SET_BIT(DDRA , pin);                     break;
                    case DIO_INPUT_PULL_UP_MODE:  CLR_BIT(DDRA , pin); SET_BIT(PORTA,pin); break;
                    case DIO_INPUT_FLOATING_MODE: CLR_BIT(DDRA , pin); CLR_BIT(PORTA,pin); break;
                    default :ReturnValue=E_NOT_OK; break;
                }
                break;
            case DIO_PORTB: 
                switch (mode)
                {
                    case DIO_OUTPUT_MODE:         SET_BIT(DDRB , pin);                     break;
                    case DIO_INPUT_PULL_UP_MODE:  CLR_BIT(DDRB , pin); SET_BIT(PORTB,pin); break;
                    case DIO_INPUT_FLOATING_MODE: CLR_BIT(DDRB , pin); CLR_BIT(PORTB,pin); break;
                    default :ReturnValue=E_NOT_OK; break;
                }
                break;
            case DIO_PORTC: 
                switch (mode)
                {
                    case DIO_OUTPUT_MODE:         SET_BIT(DDRC , pin);                     break;
                    case DIO_INPUT_PULL_UP_MODE:  CLR_BIT(DDRC , pin); SET_BIT(PORTC,pin); break;
                    case DIO_INPUT_FLOATING_MODE: CLR_BIT(DDRC , pin); CLR_BIT(PORTC,pin); break;
                    default :ReturnValue=E_NOT_OK; break;
                }
                break;
            case DIO_PORTD: 
                switch (mode)
                {
                    case DIO_OUTPUT_MODE:         SET_BIT(DDRD , pin);                     break;
                    case DIO_INPUT_PULL_UP_MODE:  CLR_BIT(DDRD , pin); SET_BIT(PORTD,pin); break;
                    case DIO_INPUT_FLOATING_MODE: CLR_BIT(DDRD , pin); CLR_BIT(PORTD,pin); break;
                    default :ReturnValue=E_NOT_OK; break;
                }
                break;
            
        }
    }
    else 
    {
         ReturnValue=E_NOT_OK;
    }
    return ReturnValue;
}


u8 DIO_u8SetPinValue (DIO_PortType port ,DIO_PinType pin , DIO_PinLevel level)
{
    StdReturnType ReturnValue=E_OK;
    if (pin>=DIO_PIN0 && pin<=DIO_PIN7)
    {
        switch (port)
        {
            case DIO_PORTA: 
                switch (level)
                {
                    case DIO_PIN_HIGH: SET_BIT(PORTA , pin); break;
                    case DIO_PIN_LOW:  CLR_BIT(PORTA , pin); break;
                    default :ReturnValue=E_NOT_OK; break;
                }
                break;
            case DIO_PORTB: 
                switch (level)
                {
                    case DIO_PIN_HIGH: SET_BIT(PORTB , pin); break;
                    case DIO_PIN_LOW:  CLR_BIT(PORTB , pin); break;
                    default :ReturnValue=E_NOT_OK; break;
                }
                break;
            case DIO_PORTC: 
                switch (level)
                {
                    case DIO_PIN_HIGH: SET_BIT(PORTC , pin); break;
                    case DIO_PIN_LOW:  CLR_BIT(PORTC , pin); break;
                    default :ReturnValue=E_NOT_OK; break;
                }
                break;
            case DIO_PORTD: 
                switch (level)
                {
                    case DIO_PIN_HIGH: SET_BIT(PORTD , pin); break;
                    case DIO_PIN_LOW:  CLR_BIT(PORTD , pin); break;
                    default :ReturnValue=E_NOT_OK; break;
                }
                break;
            
        }
    }
    else 
    {
         ReturnValue=E_NOT_OK;
    }
    return ReturnValue;
}

/*****************************************************************************/
u8 DIO_u8GetPinValue(DIO_PortType port ,DIO_PinType pin ,u8* Store_Result)
{
    StdReturnType ReturnValue = E_OK;
    if (pin > DIO_PIN7)
    {
        ReturnValue =E_NOT_OK;
    }

    else 
    {
        switch (port)
        {
        case DIO_PORTA: *Store_Result=GET_BIT(PINA,pin); break;
        case DIO_PORTB: *Store_Result=GET_BIT(PINB,pin); break;
        case DIO_PORTC: *Store_Result=GET_BIT(PINC,pin); break;
        case DIO_PORTD: *Store_Result=GET_BIT(PIND,pin); break;
        
        default: ReturnValue =E_NOT_OK; break;
        }
    }
    return ReturnValue;


}
/***************************************************************************/

DIO_LevelType Dio_FlipPinLevel(DIO_PortType port, DIO_PinType pin)
{
	DIO_LevelType level = DIO_LOW;
    switch (port)
    {
    case DIO_PORTA:  TOG_BIT(PORTA, pin);  level = GET_BIT(PINA, pin);  break;
    case DIO_PORTB:  TOG_BIT(PORTB, pin);  level = GET_BIT(PINB, pin);  break;
    case DIO_PORTC:  TOG_BIT(PORTC, pin);  level = GET_BIT(PINC, pin);  break;
    case DIO_PORTD:  TOG_BIT(PORTD, pin);  level = GET_BIT(PIND, pin);  break;
    default:  break;
    }
    return level;
}

