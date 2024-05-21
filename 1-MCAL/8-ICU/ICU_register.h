/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : MCAL             ************/
/*********     SWC    : ICU              ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/


#ifndef ICU_REGISTER_H_
#define ICU_REGISTER_H_


/********************************************************************************************/
#define TIMER_TIMSK  *((volatile u8*) 0x59 )     /* Timer / Counter Interrput Mask Register */
#define TIMER_TCCR1B *((volatile u8*) 0x4E )     /* Timer1B Counter /Control Register */
#define TIMER_TCCR1A *((volatile u8*) 0x4F )     /* Timer1A Counter /Control Register */
#define TIMER_ICR1   *((volatile u16*) 0x46)    /* Read the value of TCNT1 which stored in ICR1 */

/*************************************************************************************************/





#endif
