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
    u8 Local_u8Variable =0;
    SET_BIT(Local_u8Variable,7);

    /*******************Select between the number of data bits****************/
    #if USART_CHARACTER_SIZE == _5_BIT
    CLR_BIT(UCSRC,UCSRC_UCSZ0);
    CLR_BIT(UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);

    #elif USART_CHARACTER_SIZE == _6_BIT
    SET_BIT(UCSRC,UCSRC_UCSZ0);
    CLR_BIT(UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);


    #elif USART_CHARACTER_SIZE == _7_BIT
    CLR_BIT(UCSRC,UCSRC_UCSZ0);
    SET_BIT(UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);


    #elif USART_CHARACTER_SIZE == _8_BIT
    SET_BIT(UCSRC,UCSRC_UCSZ0);
    SET_BIT(UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);


    #elif USART_CHARACTER_SIZE == _9_BIT 
    SET_BIT(UCSRC,UCSRC_UCSZ0);
    SET_BIT(UCSRC,UCSRC_UCSZ1); 
    SET_BIT(UCSRB,UCSRB_UCSZ2);
    
    #else 
    #error "Wrong Configuration for the Character Size "
    #endif

    /********************Select the bits of stop******************************/
    #if USART_STOP_BITS == ONE_BIT
    CLR_BIT(UCSRC,UCSRC_USBS);

    #elif USART_STOP_BITS == TWO_BIT
    SET_BIT(UCSRC,UCSRC_USBS);
    #else
    #error "Wrong configuration for the stop bits"
    #endif
    /*********************Select parity bits if find***************************/
    #if USART_PARITY_SELECTION == DISABLED_PARITY
    CLR_BIT(UCSRC,UCSRC_UPM1);
    CLR_BIT(UCSRC,UCSRC_UPM0);

    #elif USART_PARITY_SELECTION == EVEN_PARITY
    SET_BIT(UCSRC,UCSRC_UPM1);
    CLR_BIT(UCSRC,UCSRC_UPM0);

    #elif USART_PARITY_SELECTION == ODD_PARITY
    SET_BIT(UCSRC,UCSRC_UPM1);
    SET_BIT(UCSRC,UCSRC_UPM0);
    #else
    #error "Wrong configuration for the parity bits"    
    #endif
    /******************modes select synchronous mode or aysnchronoous ***************/
    #if USART_MODE_SELECT== ASYNCHRONOUS_MODE
    CLR_BIT(UCSRC,UCSRC_UMSEL);

    #elif USART_MODE_SELECT== SYNCHRONOUS_MODE
    SET_BIT(UCSRC,UCSRC_UMSEL);
    #else
    #error "Wrong configuration for the mode "
    #endif 
    /**********************enable transmiter and the reciever ************************/
    SET_BIT(UCSRB,UCSRB_RXEN);
    SET_BIT(UCSRB,UCSRB_TXEN);
}