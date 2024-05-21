/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : HAL              ************/
/*********     SWC    : ultrasonic       ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/

#ifndef ULTRA_INTERFACE_H_
#define ULTRA_INTERFACE_H_

void Ultrasonic_voidInit(void);
void Ultrasonic_voidISR(void);
void Ultrasonic_voidTrigger_Edge(void);
u16 Ultrasonic_u16Distance(void);




#endif
