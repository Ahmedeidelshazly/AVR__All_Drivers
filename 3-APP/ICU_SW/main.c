/*
 * main.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Ahmed Elshazly
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "TIMER_interface.h"
#include"DIO_interface.h"
#include"EXT_interface.h"
#include"GIE_interface.h"
#include"PWM_interface.h"
#include"LCD_interface.h"

void ISR (void);
u16 PeriodTicks=0;
u16 OnTicks=0;
void main (void)
{
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT_FLOATING_MODE);
	PWM_voidSetOCR0(64);
	EXT_voidEnableInterrupt(EXTINIT_SOURCE_INIT0);
	EXT_voidSetSenseControl(EXTINIT_SENSE_FALLING_EDGE,EXTINIT_SOURCE_INIT0);
	EXT_voidSetCallBack(EXTINIT_SOURCE_INIT0, ISR);
	LCD_voidInit();
	PWM_voidTimer0Init();
	PWM_voidTimer1Init();
	GIE_voidEnable();

	while ((PeriodTicks ==0) || (OnTicks==0) );
	LCD_voidDisplayString("Period=");
	LCD_voidDispalyNumber(PeriodTicks);
	LCD_voidGotoXandY(1,0);
	LCD_voidDisplayString("On=");
	LCD_voidDispalyNumber(OnTicks);
	while (1)
	{


	}
}

void ISR (void)
{
	static u8 Counter;
	Counter++;
	if (Counter==1)
	{
		GPT_voidSetCounterValue(GPT_CHANNEL_TIMER1,0);
		EXT_voidSetSenseControl(EXTINIT_SENSE_RISING_EDGE,EXTINIT_SOURCE_INIT0);
	}
	else if (Counter==2)
	{
		PeriodTicks=GPT_voidGetTimerValue(GPT_CHANNEL_TIMER1);
		EXT_voidSetSenseControl(EXTINIT_SENSE_FALLING_EDGE,EXTINIT_SOURCE_INIT0);
	}
	else if (Counter==3)
	{
		OnTicks=GPT_voidGetTimerValue(GPT_CHANNEL_TIMER1);
		OnTicks-=PeriodTicks;
		EXT_voidDisableInterrupt(EXTINIT_SOURCE_INIT0);

	}
}
