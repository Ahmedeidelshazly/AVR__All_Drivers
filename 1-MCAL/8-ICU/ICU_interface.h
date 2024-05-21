/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : MCAL             ************/
/*********     SWC    : ICU              ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/


#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#define FALLING_EDGE  0
#define RISING_EDGE   1


#define ICU_PIN_ICP1    DIO_PORTD,DIO_PIN6
typedef enum
{
    ICU_EDGE_FALLING,
    ICU_EDGE_RISING
} Icu_EdgeType;

void Icu_SetTriggerEdge(Icu_EdgeType edge);
void Icu_EnableInterrupt(void);
void Icu_DisableInterrupt(void);
void Icu_SetCallback(void (*callbackPtr)(void));
u16  ICU_u16ReadInputCaputre(void);









#endif
