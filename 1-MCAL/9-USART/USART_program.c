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
#include "USART_private.h"
#include "USART_interface.h"
#include "USART_register.h"

void USART_voidInit (void)
{
	u16 Local_u16BuadRate=BAUD_RATE_EQUATION;
    u8 Local_u8Variable =0;
    SET_BIT(Local_u8Variable,7);

    /*******************Select between the number of data bits****************/
    #if USART_CHARACTER_SIZE == _5_BIT
    CLR_BIT(Local_u8Variable,UCSRC_UCSZ0);
    CLR_BIT(Local_u8Variable,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);

    #elif USART_CHARACTER_SIZE == _6_BIT
    SET_BIT(Local_u8Variable,UCSRC_UCSZ0);
    CLR_BIT(Local_u8Variable,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);


    #elif USART_CHARACTER_SIZE == _7_BIT
    CLR_BIT(Local_u8Variable,UCSRC_UCSZ0);
    SET_BIT(Local_u8Variable,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);


    #elif USART_CHARACTER_SIZE == _8_BIT
    SET_BIT(Local_u8Variable,UCSRC_UCSZ0);
    SET_BIT(Local_u8Variable,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);


    #elif USART_CHARACTER_SIZE == _9_BIT 
    SET_BIT(Local_u8Variable,UCSRC_UCSZ0);
    SET_BIT(Local_u8Variable,UCSRC_UCSZ1);
    SET_BIT(UCSRB,UCSRB_UCSZ2);
    
    #else 
    #error "Wrong Configuration for the Character Size "
    #endif

    /********************Select the bits of stop******************************/
    #if USART_STOP_BITS == ONE_BIT
    CLR_BIT(Local_u8Variable,UCSRC_USBS);

    #elif USART_STOP_BITS == TWO_BIT
    SET_BIT(Local_u8Variable,UCSRC_USBS);
    #else
    #error "Wrong configuration for the stop bits"
    #endif
    /*********************Select parity bits if find***************************/
    #if USART_PARITY_SELECTION == DISABLED_PARITY
    CLR_BIT(Local_u8Variable,UCSRC_UPM1);
    CLR_BIT(Local_u8Variable,UCSRC_UPM0);

    #elif USART_PARITY_SELECTION == EVEN_PARITY
    SET_BIT(Local_u8Variable,UCSRC_UPM1);
    CLR_BIT(Local_u8Variable,UCSRC_UPM0);

    #elif USART_PARITY_SELECTION == ODD_PARITY
    SET_BIT(Local_u8Variable,UCSRC_UPM1);
    SET_BIT(Local_u8Variable,UCSRC_UPM0);
    #else
    #error "Wrong configuration for the parity bits"    
    #endif
    /******************modes select synchronous mode or aysnchronoous ***************/

	#if USART_MODE_SELECT== ASYNCHRONOUS_MODE
    CLR_BIT(Local_u8Variable,UCSRC_UMSEL);

	#elif USART_MODE_SELECT== SYNCHRONOUS_MODE
    SET_BIT(Local_u8Variable,UCSRC_UMSEL);


    #else
    #error "Wrong configuration for the mode "
    #endif 
    /**********************Setting The Baud Rate**************************************/
    UBBRL= (u8)(Local_u16BuadRate) ;
    UBBRH=( (Local_u16BuadRate)  >> 8);

    /**********************enable transmiter and the reciever ************************/
    SET_BIT(UCSRB,UCSRB_RXEN);
    SET_BIT(UCSRB,UCSRB_TXEN);
}


u8 USART_u8ReceiveSynchronous(void)
{

	/*Polling till the receive is complete*/
	while ((GET_BIT(UCSRA,UCSRA_RXC)==0));
	return UDR;

}


u8 USART_voidTransmitSynchronous (u8 Copy_u8Value)
{
	StdReturnType Return_Value = E_OK ;
	u16 Local_u16Counter =0;
	/*Polling till transmit buffer is empty*/
	while ((GET_BIT(UCSRA,UCSRA_UDRE)==0) && (USART_TIME_OUT !=Local_u16Counter))
	{
		Local_u16Counter++;
	}
	if (Local_u16Counter == USART_TIME_OUT)
	{
		Return_Value = E_NOT_OK;
	}
	else
	{
		 UDR=Copy_u8Value;
	}
	return Local_u16Counter;

}
u8 USART_u8Receive_String_Synchronous(u8* Copy_String )
{
	StdReturnType Return_Value =E_OK;
	while (*Copy_String != '\0')
	{
		Return_Value=USART_u8ReceiveSynchronous();
		if (Return_Value == E_NOT_OK)
		{
			break;
		}
		Copy_String++;
	}
	return Return_Value;
}

	/*can do it by using for loop if he give me the size of the string */
void USART_voidTransmit_String_Synchronous (u8* Copy_String)
{

	while (*Copy_String > 0 )
	{
		USART_voidTransmitSynchronous(*Copy_String++);
	}

}
