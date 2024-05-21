/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : MCAL             ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


#define TIMER_TCCR0  *((volatile u8*) 0x53 )     /* Timer0  Counter /Control Register */
#define TIMER_TCCR1A *((volatile u8*) 0x2F )     /* Timer1A Counter /Control Register */
#define TIMER_TCCR1B *((volatile u8*) 0x4E )     /* Timer1B Counter /Control Register */
#define TIMER_TCCR2  *((volatile u8*) 0x45 )     /* Timer2  Counter /Control Register */
/********************************************************************************************/
#define TIMER_TCNT0  *((volatile u8*) 0x52 )     /* Timer / Counter  Register */
#define TIMER_TCNT1  *((volatile u16*) 0x4C)     /* Timer / Counter  Register */
#define TIMER_TCNT2  *((volatile u8*) 0x44 )     /* Timer / Counter  Register */
/*********************************************************************************************/
#define TIMER_OCR0   *((volatile u8*) 0x5C )     /* Output Compare Register              */
#define TIMER_OCR1A  *((volatile u16*) 0x4B)     /* Output Compare Register for timer 1A */
#define TIMER_OCR1B  *((volatile u16*) 0x48)     /* Output Compare Register for timer 1B */
#define TIMER_OCR2   *((volatile u8*) 0x43 )     /* Output Compare Register for timer 2  */
/********************************************************************************************/
#define TIMER_TIMSK  *((volatile u8*) 0x59 )     /* Timer / Counter Interrput Mask Register */
#define TIMER_TIFR   *((volatile u8*) 0x58 )     /* Timer / Counter Interrput Flag Register */
#define TIMER_SFIOR  *((volatile u8*) 0x58 )     /*Special Function Input Output  Register  */


#endif 