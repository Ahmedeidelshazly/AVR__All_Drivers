/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     Name   : USART             ***************/
/********************************************************/
/********************************************************/

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

/**********************************************************************************************/
#define UDR          *(u8*(volatile )0x2C)             // UDR   ==>usart data register 
/***********************************************************************************************/
#define UCSRA        *(u8*(volatile )0x2B)     // UCSRA ==>usart control and status register ==>A
#define UCSRA_RXC    7                         // recieve complete bit  
#define UCSRA_TXC    6                         // Transmit complete bit 
#define UCSRA_UDRE   5                         // Data Register Empty
#define UCSRA_FE     4                         // Frame Error  
#define UCSRA_DOR    3                         // Data Over Run 
#define UCSRA_PE     2                         // Parity Error
#define UCSRA_U2X    1                         // Double the Transmission Speed  
#define UCSRA_MPCM   0                         // Multi-processor Communication Mode
/*************************************************************************************************/
#define UCSRB       *(u8*(volatile )0x2A)      // UCSRB ==>usart control and status register ==>B
#define UCSRB_RXCIE 7                          // recieve Complete Interrupt Enable               
#define UCSRB_TXCIE 6                          // Transmit Complete Interrupt Enable  
#define UCSRB_UDRIE 5                          // Data Register Empty Interrupt Enable
#define UCSRB_RXEN  4                          // Receiver Enable 
#define UCSRB_TXEN  3                          // Transmitter Enable  
#define UCSRB_UCSZ2 2                          // Character Size  
#define UCSRB_RXB8  1                          // Receive Data Bit 8  
#define UCSRB_TXB8  0                          // Transmit Data Bit 8
/*****************************************************************************************************/
#define UCSRC       *(u8*(volatile )0x40)      // UCSRC ==>usart control and status register ==>C
#define UCSRC_URSEL 7                          // Register Select
#define UCSRC_UMSEL 6                          // Mode Select
#define UCSRC_UPM1  5                          // the first bit for Parity select
#define UCSRC_UPM0  4                          // the secand bit for Parity select
#define UCSRC_USBS  3                          // Stop bit select
#define UCSRC_UCSZ2 2                          // the first bit for select the character size 
#define UCSRC_UCSZ1 1                          // the secand bit for select the character size 
#define UCSRC_UCSZ0 0                          // the third  bit for select the character size 
/********************************************************************************************************/
#define UBBRH *(u8*(volatile )0x40)            // UBBRH ==>usart Baud Rate Register
/********************************************************************************************************/
#define UBBRL *(u8*(volatile )0x29)            // UBBRL ==>usart Baud Rate Register




#endif