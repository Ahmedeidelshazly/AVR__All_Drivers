/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : MCAL             ************/
/*********     SWC    : ICU              ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ICU_interface.h"
#include "ICU_private.h"
#include "ICU_register.h"


static void (*Callback_Icu) (void) = NULL_PTR;

ISR(VECTOR_TIM1_CAPT)
{
    if (NULL_PTR != Callback_Icu)
    {
        Callback_Icu();
    }
}

void Icu_SetTriggerEdge(Icu_EdgeType edge)
{
    if(edge == ICU_EDGE_FALLING)
    {
        CLR_BIT(TIMER_TCCR1B, 6);
    }
    else if(edge == ICU_EDGE_RISING)
    {
        SET_BIT(TIMER_TCCR1B, 6);
    }
    else
    {
        /* Do Nothing. */
    }
}

void Icu_EnableInterrupt(void)
{
    SET_BIT(TIMER_TIMSK, 5);
}

void Icu_DisableInterrupt(void)
{
    CLR_BIT(TIMER_TIMSK, 5);
}
u16  ICU_u16ReadInputCaputre(void)
{
	return TIMER_ICR1;
}
void Icu_SetCallback(void (*callbackPtr)(void ))
{
	if (callbackPtr!=NULL)
	{
		Callback_Icu = callbackPtr;
	}
}
