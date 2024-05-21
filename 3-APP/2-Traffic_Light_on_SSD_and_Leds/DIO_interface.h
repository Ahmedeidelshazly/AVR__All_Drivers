/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : DIO               ***************/
/********************************************************/
/********************************************************/


/* in this files i do all the implementition of the funcition which i need after 
 * 1 ==> define port direction 
 * 2 ==> define port value
 * 3 ==> define pin direction
 * 4 ==> define pin value 
 * 5 ==> get pin value 
 * 6 ==> toggle pin value 
*/

typedef enum 
{
    DIO_PORTA,
    DIO_PORTB, 
    DIO_PORTC,
    DIO_PORTD, 
}DIO_PortType;

typedef enum 
{
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7,
}DIO_PinType;

typedef enum
{
    DIO_OUTPUT_MODE,
    DIO_INPUT_PULL_UP_MODE,
    DIO_INPUT_FLOATING_MODE,
}DIO_PinMode;

typedef enum
{
    DIO_PIN_HIGH,
    DIO_PIN_LOW,
}DIO_PinLevel;

typedef enum
{
    DIO_LOW,
    DIO_HIGH,


}DIO_LevelType;
/**this two function for port */
u8  DIO_u8SetPortDirection (DIO_PortType port ,u8 Copy_u8Direciton );
u8 DIO_u8SetPortValue (DIO_PortType port ,u8 Copy_u8Value );    

/*this two function for pin*/
u8 DIO_u8SetPinDirection (DIO_PortType port ,DIO_PinType pin , DIO_PinMode mode);
u8 DIO_u8SetPinValue (DIO_PortType port ,DIO_PinType pin , DIO_PinLevel level);

/*this function for get pin*/
u8 DIO_u8GetPinValue(DIO_PortType port ,DIO_PinType pin ,u8* Store_Result);

/*this for toggle pin*/
DIO_LevelType DIO_u8TogglePin(DIO_PortType port ,DIO_PinType pin );
