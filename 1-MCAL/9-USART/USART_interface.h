/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     Name   : USART             ***************/
/********************************************************/
/********************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define BUSY           0UL
#define IDLE           1UL
#define BUSY_FUNC      2UL

#define USART_TIME_OUT 5000UL
void USART_voidInit (void);
u8   USART_u8Read   (void);
void USART_voidWrite(u8 Copy_u8Value);


u8 USART_u8ReceiveSynchronous(void);
u8 USART_voidTransmitSynchronous (u8 Copy_u8Value);
u8 USART_u8Receive_String_Synchronous(u8* Copy_String );
void USART_voidTransmit_String_Synchronous (u8* Copy_String);
#endif
