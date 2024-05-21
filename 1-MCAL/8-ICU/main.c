/*
 * main.c
 *
 *  Created on: Dec 7, 2023
 *      Author: Ahmed Elshazly
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PWM_interface.h"
#include "GIE_interface.h"
#include "ICU_interface.h"

#include "LCD_interface.h"
u16 Peroid_Tickes=0;
u8 ON_Tickes=0;
void ICU_HW(void);

void main(void){
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN6,DIO_INPUT_FLOATING_MODE);
	Icu_SetTriggerEdge(ICU_EDGE_RISING);
	Icu_EnableInterrupt();
	Icu_SetCallback(&ICU_HW);

	PWM_voidSetOCR0(64);
	PWM_voidTimer0Init();
	PWM_voidTimer1Init();
	LCD_voidInit();
	GIE_voidEnable();
	while (1)
	{
		while (Peroid_Tickes ==0 && ON_Tickes==0);
		LCD_voidDisplayString("Period =");
		LCD_voidDispalyNumber(Peroid_Tickes);
		LCD_voidGotoXandY(1,0);
		LCD_voidDisplayString("On =");
		LCD_voidDispalyNumber(ON_Tickes);
	}
}
void ICU_HW(void)
{
	static u16 Reading1 ,Reading2 ,Reading3;
	static u8 Local_u8Counter;
	Local_u8Counter++;
	if (Local_u8Counter==1)
	{
		Reading1=ICU_u16ReadInputCaputre();
	}
	if (Local_u8Counter==2)
	{
		Reading2=ICU_u16ReadInputCaputre();
		Peroid_Tickes=Reading2-Reading1;
		Icu_SetTriggerEdge(ICU_EDGE_FALLING);
	}
	else if (Local_u8Counter==3)
	{
		Reading3=ICU_u16ReadInputCaputre();
		ON_Tickes=Reading3-Reading2;
		Icu_DisableInterrupt();
	}



}

