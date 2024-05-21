/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     Name   : USART             ***************/
/********************************************************/
/********************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit (void);
u8   USART_u8Read   (void);
void USART_voidWrite(u8 Copy_u8Value);

#endif