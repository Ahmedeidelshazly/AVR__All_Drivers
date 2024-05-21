/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : MCAL             ************/
/*********     SWC    : INTERRUPT        ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/


#ifndef EXT_REGISTER_H_
#define EXT_REGISTER_H_


#define MCUCR  *((volatile u8*)0x55)  // MCU control register has control bits to control the register 
#define MCUCSR *((volatile u8*)0x54)  // MCU control and status register has control bits to control the register 
#define GICR   *((volatile u8*)0x5B)  // General Interrupt Control Register
#define GIFR   *((volatile u8*)0x5A)  // General Interrupt Flag Register








#endif