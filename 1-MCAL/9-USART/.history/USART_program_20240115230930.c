/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     Name   : USART             ***************/
/********************************************************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_config.h"
#include "USART_interface.h"
#include "USART_register.h"

void USART_voidInit (void)
{














     /*************************modes select synchronous mode or aysnchronoous */







    /**********************enable transmiter and the reciever ***********************************/
    SET_BIT(UCSRB,UCSRB_RXEN);
    SET_BIT(UCSRB,UCSRB_TXEN);
}