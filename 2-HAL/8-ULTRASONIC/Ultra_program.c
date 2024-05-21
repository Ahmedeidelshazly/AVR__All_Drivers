/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : HAL              ************/
/*********     SWC    : ultrasonic       ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "Ultra_config.h"
#include "Ultra_interface.h"
#include "Ultra_private.h"
#include "PWM_interface.h"
#include "DIO_interface.h"
#include "ICU_interface.h"
#include <util/delay.h>

static u16 Ultra_Reading;
static u16 Ultra_Distance;

static u16 reading1;
static u16 reading2;

void Ultrasonic_voidInit(void)
{
	DIO_u8SetPinDirection(ULTRA_TRIGGAR,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(ULTRA_ECHO,DIO_INPUT_FLOATING_MODE);
	PWM_voidTimer1Init(); //set prescaller only 8 MHZ
	ICU_voidInit();
	Icu_SetCallback(&Ultrasonic_voidISR);

}
void Ultrasonic_voidISR(void)
{
	static u8 Counter=0;
	Counter++;
	if (Counter==1)
	{
		reading1=ICU_u16ReadInputCaputre();
		Icu_SetTriggerEdge(ICU_EDGE_FALLING);
	}
	else if (Counter==2)
	{
		reading2=ICU_u16ReadInputCaputre();
		Ultra_Reading=reading2-reading1;
		Icu_SetTriggerEdge(ICU_EDGE_RISING);
		Icu_DisableInterrupt();
		Counter=0;

	}

}
void Ultrasonic_voidTrigger_Edge(void)
{
	DIO_u8SetPinValue(ULTRA_TRIGGAR, DIO_PIN_HIGH);
	_delay_us(10);
	DIO_u8SetPinValue(ULTRA_TRIGGAR, DIO_PIN_LOW);
}
u16 Ultrasonic_u16Distance(void)
{
	Ultrasonic_voidTrigger_Edge();
	Icu_EnableInterrupt();
	Ultra_Distance=Ultra_Reading/58;
	return Ultra_Distance;
}
