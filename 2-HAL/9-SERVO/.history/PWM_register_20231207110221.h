/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     Name   : PWM               ***************/
/********************************************************/
/********************************************************/

#ifndef PWM_REGISTER_H_
#define PWM_REGISTER_H_

#define TCCR0  *((volatile u8*) 0x53 )     /* Timer0  Counter /Control Register */
#define TCCR1A *((volatile u8*) 0x4F )     /* Timer1A Counter /Control Register */
#define TCCR1B *((volatile u8*) 0x4E )     /* Timer1B Counter /Control Register */
#define TCCR2  *((volatile u8*) 0x45 )     /* Timer2  Counter /Control Register */
/********************************************************************************************/
#define TCNT0  *((volatile u8*) 0x52 )     /* Timer / Counter  Register */
#define TCNT1  *((volatile u16*) 0x4C)     /* Timer / Counter  Register */
#define TCNT2  *((volatile u8*) 0x44 )     /* Timer / Counter  Register */
/*********************************************************************************************/
#define OCR0   *((volatile u8*) 0x5C )     /* Output Compare Register              */
#define OCR1A  *((volatile u16*) 0x4A)     /* Output Compare Register for timer 1A */
#define OCR1B  *((volatile u16*) 0x48)     /* Output Compare Register for timer 1B */
#define OCR2   *((volatile u8*) 0x43 )     /* Output Compare Register for timer 2  */
/********************************************************************************************/
#define TIMSK  *((volatile u8*) 0x59 )     /* Timer / Counter Interrput Mask Register */
#define TIFR   *((volatile u8*) 0x58 )     /* Timer / Counter Interrput Flag Register */
#define SFIOR  *((volatile u8*) 0x50 )     /*Special Function Input Output  Register  */

/***********************************************************************************************/
#define ICR1  *((volatile u16*) 0x46 )     /* Input Capture Register  */








#endif 
