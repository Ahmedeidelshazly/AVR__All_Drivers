#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"
#include "GIE_interface.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"

Gpt_ConfigurationType Gpt_Configuration = 
{
    /*<<<<<<<<<<<<<for Timer 0>>>>>>>>>>>>>>>>>>*/
    .Timer0_Mode  =GPT_MODE_CTC,
    .Timer0_Clk   =GPT_CLK_PRESCALLER_8,
    .Timer0_Output=GPT_OUT_DISCONCTED,
    /*<<<<<<<<<<<<<for Timer 1>>>>>>>>>>>>>>>>>>*/
    .Timer1_Mode=GPT_MODE_OFF,
    .Timer1_Clk =GPT_CLK_PRESCALLER_8,
    .Timer1A_Output=GPT_OUT_DISCONCTED,
    .Timer1B_Output=GPT_OUT_DISCONCTED,

    /*<<<<<<<<<<<<<for Timer 2 >>>>>>>>>>>>>>>>>>*/
    .Timer2_Mode=GPT_MODE_OFF,
    .Timer2_Clk=GPT_CLK_PRESCALLER_8,
    .Timer2_Output=GPT_OUT_DISCONCTED, 
};

void Led (void);
void main (void )
{
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT_MODE);
	GPT_voidInit(&Gpt_Configuration);
	LCD_voidInit();
	GPT_voidSetCompareValue(GPT_CHANNEL_TIMER0,250);
	GPT_voidInerruptEnable(GPT_INIT_SOURCE_TIMER0_COMP);
	GPT_voidSetCallBack(GPT_INIT_SOURCE_TIMER0_COMP,&Led);
	LCD_voidDisplayString("Finish");
	GIE_voidEnable();
	while (1)
	{

	}
}

void Led (void)
{
	static u16 Counter ;
	static u8 Local_u8counter;
	Counter++;
	if (Counter==4000)
	{

		LCD_voidDisplayString("Finish2");
		Dio_FlipPinLevel(DIO_PORTB,DIO_PIN7);
		Counter=0;
	}
}
/*
SSD_Type SSD1 =
{
		.Type=SSD_COMMON_CATHODE,
		.Data_Port=DIO_PORTD,
		.EnablePort=DIO_PORTD,
		.Enable_pin=DIO_PIN7,

};
*/
