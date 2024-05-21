/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     Name   : USART             ***************/
/********************************************************/
/********************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


#define BAUDRATE_VALUE 9600UL

/*
 * Select between USART_CHARACTER_SIZE
 *  1==>_5_BIT
 *  2==>_6_BIT
 *  3==>_7_BIT
 *  4==>_8_BIT
 *  5==>_9_BIT
 */
#define _5_BIT 0
#define _6_BIT 1
#define _7_BIT 2
#define _8_BIT 3
#define _9_BIT 4

#define USART_CHARACTER_SIZE _8_BIT

/*
 * Select between USART_STOP_BITS
 *  1==>ONE_BIT  ==>0
 *  2==>TWO_BIT  ==>1
 */

#define ONE_BIT     0
#define TWO_BIT     1
#define USART_STOP_BITS ONE_BIT

#endif
