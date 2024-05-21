/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     Name   : PWM               ***************/
/********************************************************/
/********************************************************/

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

/************************************************************/
#define CHANNEL_A  0
#define CHANNEL_B  1
#define CHANNEL_SELECT CHANNEL_A
/***********************************************************/
#define NORMAL        0   // Disconnected 
#define TOGGLE_MDOE   1   //Toggle OC1A on Compare Match
#define NON_INVERTING 2   //Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP
#define INVERTING     3   //Set OC1A/OC1B on compare match, clear OC1A/OC1B at TOP
#define COMPARE_OUT_MODE  NORMAL
#define COMPARE_OUT_MODE0 NON_INVERTING
/***********************************************************/

#define PWM_NORMAL               0   /*For Timer 0 && Timer 1*/
#define PWM_PHASE_CORRECT_8BIT   1  
#define PWM_PHASE_CORRECT_9BIT   2
#define PWM_PHASE_CORRECT_10BIT  3
#define PWM_PHASE_CORRECT_ICR1   4
#define PWM_FAST_8BIT            5
#define PWM_FAST_9BIT            6
#define PWM_FAST_10BIT           7
#define PWM_FAST_ICR1            8 
#define PWM_PHASE_CORRECT        9    /*For Timer 0*/
#define PWM_FAST                 10   /*For Timer 0*/
#define PWM_GenerationWaveForm  PWM_NORMAL  // for timer 1
#define PWM_GenerationWaveForm0 PWM_FAST       // for timer 0
/**************************************************************/
#define PRESCALLER_MASK      0b11111000
#define NO_PRESCALLER        1  //0 0 1
#define DIVIDE_BY_8          2  //0 1 0    
#define DIVIDE_BY_64         3  //0 1 1  
#define DIVIDE_BY_256        4  //1 0 0
#define DIVIDE_BY_1024       5  //1 0 1  
#define FALLING_EDGE_EX_CLK  6  //1 1 0 
#define RISING_EDGE_EX_CLK   7  //1 1 1  
#define PRESCALLER_SELECT    DIVIDE_BY_8
/*******************************************************************/


/**************************************************************/
#define PRESCALLER_MASK      0b11111000
#define NO_PRESCALLER        1  //0 0 1
#define DIVIDE_BY_8          2  //0 1 0    
#define DIVIDE_BY_32         3  //0 1 1  
#define DIVIDE_BY_64_T2      4  //1 0 0
#define DIVIDE_BY_128        5  //1 0 1  
#define DIVIDE_BY_256_T2     6  //1 1 0
#define DIVIDE_BY_1024_T2    7  //1 1 1
#define PRESCALLER2_SELECT   DIVIDE_BY_8
/*******************************************************************/

void PWM_voidTimer0Init(void);
void PWM_voidTimer1Init(void);
void PWM_voidSetICR1(u16 Copy_u16Top);
void PWM_voidSetOCR (u16 Copy_u16CompareValue);
void PWM_voidSetOCR0 (u8 Copy_u16CompareValue);
void PWM_voidSetOCR2 (u8 Copy_u16CompareValue);
void servo (u8 Copy_u8Degree);

#endif 
