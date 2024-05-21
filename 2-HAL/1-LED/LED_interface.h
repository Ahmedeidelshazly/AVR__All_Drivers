/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : DIO               ***************/
/********************************************************/
/********************************************************/



#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef struct
{
    u8 Port;
    u8 Pin;
    u8 State;
}LED_Type;


/****************************************************************/
#define ACTIVE_HIGH   1
#define ACTIVE_LOW    0

/****************************************************************/

/*****************************************************************/
void LED_voidInit (LED_Type LED_Configurtion);
void Led_Turn_On  (LED_Type LED_Configurtion );
void Led_Turn_Off (LED_Type LED_Configurtion );
void Led_Toggle   (LED_Type LED_Configurtion );

/*******************************************************************/

#endif
