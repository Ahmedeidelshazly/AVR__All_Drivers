/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : MCAL             ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_register.h"
#include "TIMER_interface.h"
static void (*Callback_Gpt_TIM0_OVF) (void) = NULL_PTR;
static void (*Callback_Gpt_TIM0_COMP) (void) = NULL_PTR;
static void (*Callback_Gpt_TIM1_OVF) (void) = NULL_PTR;
static void (*Callback_Gpt_TIM1_COMPA) (void) = NULL_PTR;
static void (*Callback_Gpt_TIM1_COMPB) (void) = NULL_PTR;
static void (*Callback_Gpt_TIM2_OVF) (void) = NULL_PTR;
static void (*Callback_Gpt_TIM2_COMP) (void) = NULL_PTR;

ISR(VECTOR_TIM0_OVF)
{
    if (NULL_PTR != Callback_Gpt_TIM0_OVF)
    {
        Callback_Gpt_TIM0_OVF();
    }
}

ISR(VECTOR_TIM0_COMP)
{
    if (NULL_PTR != Callback_Gpt_TIM0_COMP)
    {
        Callback_Gpt_TIM0_COMP();
    }
}

ISR(VECTOR_TIM1_OVF)
{
    if (NULL_PTR != Callback_Gpt_TIM1_OVF)
    {
        Callback_Gpt_TIM1_OVF();
    }
}

ISR(VECTOR_TIM1_COMPA)
{
    if (NULL_PTR != Callback_Gpt_TIM1_COMPA)
    {
        Callback_Gpt_TIM1_COMPA();
    }
}

ISR(VECTOR_TIM1_COMPB)
{
    if (NULL_PTR != Callback_Gpt_TIM1_COMPB)
    {
        Callback_Gpt_TIM1_COMPB();
    }
}

ISR(VECTOR_TIM2_OVF)
{
    if (NULL_PTR != Callback_Gpt_TIM2_OVF)
    {
        Callback_Gpt_TIM2_OVF();
    }
}

ISR(VECTOR_TIM2_COMP)
{
    if (NULL_PTR != Callback_Gpt_TIM2_COMP)
    {
        Callback_Gpt_TIM2_COMP();
    }
}


void GPT_voidInit(Gpt_ConfigurationType* config )
{
	/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Timer0 Init >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	if (config->Timer0_Mode !=GPT_MODE_OFF)
	{
		if (config->Timer0_Mode == GPT_MODE_NORMAL)
		{
			CLR_BIT(TIMER_TCCR0,3);
			CLR_BIT(TIMER_TCCR0,6);
		}
		else if (config->Timer0_Mode == GPT_MODE_CTC)
		{
			CLR_BIT(TIMER_TCCR0,6);
			SET_BIT(TIMER_TCCR0,3);
		}
		else
		{
			//do nothing
		}
		switch (config->Timer0_Output)
		{
		case GPT_OUT_DISCONCTED:
			CLR_BIT(TIMER_TCCR0,4);
			CLR_BIT(TIMER_TCCR0,5);
			break;

		case GPT_OUT_TOGGLE:
			SET_BIT(TIMER_TCCR0,4);
			CLR_BIT(TIMER_TCCR0,5);
			break;

		case GPT_OUT_CLR:
			CLR_BIT(TIMER_TCCR0,4);
			SET_BIT(TIMER_TCCR0,5);
			break;

		case GPT_OUT_SET:
			SET_BIT(TIMER_TCCR0,4);
			SET_BIT(TIMER_TCCR0,5);
			break;

		default:  break;
		}

		GPT_voidSetClockSource(GPT_CHANNEL_TIMER0,config->Timer0_Clk);
	}
	/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Timer1 Init >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	if (config->Timer1_Mode !=GPT_MODE_OFF)
	{
		if (config->Timer1_Mode == GPT_MODE_NORMAL)
		{
			CLR_BIT(TIMER_TCCR1A,0);
			CLR_BIT(TIMER_TCCR1A,1);
			CLR_BIT(TIMER_TCCR1B,3);
			CLR_BIT(TIMER_TCCR1B,4);

		}
		else if (config->Timer0_Mode == GPT_MODE_CTC)
		{
			CLR_BIT(TIMER_TCCR1A,0);
			CLR_BIT(TIMER_TCCR1A,1);
			SET_BIT(TIMER_TCCR1B,3);
			CLR_BIT(TIMER_TCCR1B,4);
		}
		else if (config->Timer0_Mode == GPT_MODE_CTC_ICR1)
		{
			CLR_BIT(TIMER_TCCR1A,0);
			SET_BIT(TIMER_TCCR1A,1);
			CLR_BIT(TIMER_TCCR1B,3);
			SET_BIT(TIMER_TCCR1B,4);
		}
		else
		{
			//do nothing
		}
		switch (config->Timer1A_Output)
		{
		case GPT_OUT_DISCONCTED:
			CLR_BIT(TIMER_TCCR1A,6);
			CLR_BIT(TIMER_TCCR1A,7);
			break;

		case GPT_OUT_TOGGLE:
			SET_BIT(TIMER_TCCR1A,6);
			CLR_BIT(TIMER_TCCR1A,7);
			break;

		case GPT_OUT_CLR:
			CLR_BIT(TIMER_TCCR1A,6);
			SET_BIT(TIMER_TCCR1A,7);
			break;

		case GPT_OUT_SET:
			SET_BIT(TIMER_TCCR1A,6);
			SET_BIT(TIMER_TCCR1A,7);
			break;

		default:  break;
		}

		switch (config->Timer1B_Output)
		{
		case GPT_OUT_DISCONCTED:
			CLR_BIT(TIMER_TCCR1A,4);
			CLR_BIT(TIMER_TCCR1A,5);
			break;

		case GPT_OUT_TOGGLE:
			SET_BIT(TIMER_TCCR1A,4);
			CLR_BIT(TIMER_TCCR1A,5);
			break;

		case GPT_OUT_CLR:
			CLR_BIT(TIMER_TCCR1A,4);
			SET_BIT(TIMER_TCCR1A,5);
			break;

		case GPT_OUT_SET:
			SET_BIT(TIMER_TCCR1A,4);
			SET_BIT(TIMER_TCCR1A,5);
			break;

		default:  break;
		}

		GPT_voidSetClockSource(GPT_CHANNEL_TIMER1,config->Timer1_Clk);
	}
	/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Timer2 Init >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	if (config->Timer2_Mode !=GPT_MODE_OFF)
	{
		if (config->Timer2_Mode == GPT_MODE_NORMAL)
		{
			CLR_BIT(TIMER_TCCR2,3);
			CLR_BIT(TIMER_TCCR2,6);
		}
		else if (config->Timer0_Mode == GPT_MODE_CTC)
		{
			CLR_BIT(TIMER_TCCR2,6);
			SET_BIT(TIMER_TCCR2,3);
		}
		else
		{
			//do nothing
		}

		switch (config->Timer2_Output)
		{
		case GPT_OUT_DISCONCTED:
			CLR_BIT(TIMER_TCCR2,4);
			CLR_BIT(TIMER_TCCR2,5);
			break;

		case GPT_OUT_TOGGLE:
			SET_BIT(TIMER_TCCR2,4);
			CLR_BIT(TIMER_TCCR2,5);
			break;

		case GPT_OUT_CLR:
			CLR_BIT(TIMER_TCCR2,4);
			SET_BIT(TIMER_TCCR2,5);
			break;

		case GPT_OUT_SET:
			SET_BIT(TIMER_TCCR2,4);
			SET_BIT(TIMER_TCCR2,5);
			break;

		default:  break;
		}

		GPT_voidSetClockSource(GPT_CHANNEL_TIMER2,config->Timer2_Clk);
	}


}

void GPT_voidSetClockSource  (Gpt_Channel_Type  Channel,Gpt_Clk_Prescaller_Type Clock )
{
	switch (Channel)
	{
	/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Timer0 Prescaller >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	case GPT_CHANNEL_TIMER0 :
		switch (Clock)
		{
		case GPT_CLK_OFF:
			CLR_BIT(TIMER_TCCR0,0);
			CLR_BIT(TIMER_TCCR0,1);
			CLR_BIT(TIMER_TCCR0,2);
			break;

		case GPT_CLK_PRESCALLER_1:
			SET_BIT(TIMER_TCCR0,0);
			CLR_BIT(TIMER_TCCR0,1);
			CLR_BIT(TIMER_TCCR0,2);
			break;

		case GPT_CLK_PRESCALLER_8:
			CLR_BIT(TIMER_TCCR0,0);
			SET_BIT(TIMER_TCCR0,1);
			CLR_BIT(TIMER_TCCR0,2);
			break;

		case GPT_CLK_PRESCALLER_64:
			SET_BIT(TIMER_TCCR0,0);
			SET_BIT(TIMER_TCCR0,1);
			CLR_BIT(TIMER_TCCR0,2);
			break;

		case GPT_CLK_PRESCALLER_256:
			CLR_BIT(TIMER_TCCR2,0);
			CLR_BIT(TIMER_TCCR2,1);
			SET_BIT(TIMER_TCCR2,2);
			break;

		case GPT_CLK_PRESCALLER_1024:
			SET_BIT(TIMER_TCCR0,0);
			CLR_BIT(TIMER_TCCR0,1);
			SET_BIT(TIMER_TCCR0,2);
			break;

		case GPT_CLK_EXT_FALLIGN_EDGE:
			CLR_BIT(TIMER_TCCR0,0);
			SET_BIT(TIMER_TCCR0,1);
			SET_BIT(TIMER_TCCR0,2);
			break;

		case GPT_CLK_EXT_RISING_EDGE:
			SET_BIT(TIMER_TCCR0,0);
			SET_BIT(TIMER_TCCR0,1);
			SET_BIT(TIMER_TCCR0,2);
			break;
		default: break;
		}
		break;
		/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Timer1 Prescaller >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
		case GPT_CHANNEL_TIMER1 :
			switch (Clock)
			{
			case GPT_CLK_OFF:
				CLR_BIT(TIMER_TCCR1B,0);
				CLR_BIT(TIMER_TCCR1B,1);
				CLR_BIT(TIMER_TCCR1B,2);
				break;

			case GPT_CLK_PRESCALLER_1:
				SET_BIT(TIMER_TCCR1B,0);
				CLR_BIT(TIMER_TCCR1B,1);
				CLR_BIT(TIMER_TCCR1B,2);
				break;

			case GPT_CLK_PRESCALLER_8:
				CLR_BIT(TIMER_TCCR1B,0);
				SET_BIT(TIMER_TCCR1B,1);
				CLR_BIT(TIMER_TCCR1B,2);
				break;

			case GPT_CLK_PRESCALLER_64:
				SET_BIT(TIMER_TCCR1B,0);
				SET_BIT(TIMER_TCCR1B,1);
				CLR_BIT(TIMER_TCCR1B,2);
				break;


			case GPT_CLK_PRESCALLER_256:
				CLR_BIT(TIMER_TCCR1B,0);
				CLR_BIT(TIMER_TCCR1B,1);
				SET_BIT(TIMER_TCCR1B,2);
				break;

			case GPT_CLK_PRESCALLER_1024:
				SET_BIT(TIMER_TCCR1B,0);
				CLR_BIT(TIMER_TCCR1B,1);
				SET_BIT(TIMER_TCCR1B,2);
				break;

			case GPT_CLK_EXT_FALLIGN_EDGE:
				CLR_BIT(TIMER_TCCR1B,0);
				SET_BIT(TIMER_TCCR1B,1);
				SET_BIT(TIMER_TCCR1B,2);
				break;

			case GPT_CLK_EXT_RISING_EDGE:
				SET_BIT(TIMER_TCCR1B,0);
				SET_BIT(TIMER_TCCR1B,1);
				SET_BIT(TIMER_TCCR1B,2);
				break;
			default: break;
			}
			break;
			/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Timer2 Prescaller >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
			case GPT_CHANNEL_TIMER2 :
				switch (Clock)
				{
				case GPT_CLK_OFF:
					CLR_BIT(TIMER_TCCR2,0);
					CLR_BIT(TIMER_TCCR2,1);
					CLR_BIT(TIMER_TCCR2,2);
					break;

				case GPT_CLK_PRESCALLER_1:
					SET_BIT(TIMER_TCCR2,0);
					CLR_BIT(TIMER_TCCR2,1);
					CLR_BIT(TIMER_TCCR2,2);
					break;

				case GPT_CLK_PRESCALLER_8:
					CLR_BIT(TIMER_TCCR2,0);
					SET_BIT(TIMER_TCCR2,1);
					CLR_BIT(TIMER_TCCR2,2);
					break;

				case GPT_CLK_PRESCALLER_32:
					SET_BIT(TIMER_TCCR2,0);
					SET_BIT(TIMER_TCCR2,1);
					CLR_BIT(TIMER_TCCR2,2);
					break;


				case GPT_CLK_PRESCALLER_64:
					CLR_BIT(TIMER_TCCR2,0);
					CLR_BIT(TIMER_TCCR2,1);
					SET_BIT(TIMER_TCCR2,2);
					break;

				case GPT_CLK_PRESCALLER_128:
					SET_BIT(TIMER_TCCR2,0);
					CLR_BIT(TIMER_TCCR2,1);
					SET_BIT(TIMER_TCCR2,2);
					break;

				case GPT_CLK_PRESCALLER_256:
					CLR_BIT(TIMER_TCCR2,0);
					SET_BIT(TIMER_TCCR2,1);
					SET_BIT(TIMER_TCCR2,2);
					break;

				case GPT_CLK_PRESCALLER_1024:
					SET_BIT(TIMER_TCCR2,0);
					SET_BIT(TIMER_TCCR2,1);
					SET_BIT(TIMER_TCCR2,2);
					break;

				default:  break;
				}
				break;

	}
}
/*<<<<<<<<<<<<<<<<<<<<<<<Set Counter Value TCNT Register >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void GPT_voidSetCounterValue (Gpt_Channel_Type  Channel, u16 Copy_u16Value)
{
	switch (Channel)
	{
	case GPT_CHANNEL_TIMER0: TIMER_TCNT0=Copy_u16Value; break;
	case GPT_CHANNEL_TIMER1: TIMER_TCNT1=Copy_u16Value; break;
	case GPT_CHANNEL_TIMER2: TIMER_TCNT2=Copy_u16Value; break;
	default: break;
	}
}

/*<<<<<<<<<<<<<<<<<<<<<<<Set Value in CTC Mode OCR register >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void GPT_voidSetCompareValue (Gpt_CompareChannelType  Channel, u16 Copy_u16Value)
{
	switch (Channel)
	{
	case GPT_COMP0 : TIMER_OCR0 =Copy_u16Value; break;
	case GPT_COMP1A: TIMER_OCR1A=Copy_u16Value; break;
	case GPT_COMP1B: TIMER_OCR1B=Copy_u16Value; break;
	case GPT_COMP2 : TIMER_OCR2 =Copy_u16Value; break;
	default:   break;
	}
}
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<Return Timer Value >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
u16  GPT_voidGetTimerValue   (Gpt_Channel_Type Channel)
{
	u16 Copy_u16TimerValue;
	switch (Channel)
	{
	case GPT_CHANNEL_TIMER0: Copy_u16TimerValue=TIMER_TCNT0; break;
	case GPT_CHANNEL_TIMER1: Copy_u16TimerValue=TIMER_TCNT1; break;
	case GPT_CHANNEL_TIMER2: Copy_u16TimerValue=TIMER_TCNT2; break;

	default:  break;
	}
	return Copy_u16TimerValue;

}
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Interrupt Enable >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void GPT_voidInerruptEnable  (Gpt_SourceInterrputType Source)
{
	switch (Source)
	{
	case GPT_INIT_SOURCE_TIMER0_OVF:   SET_BIT(TIMER_TIMSK,0); break;
	case GPT_INIT_SOURCE_TIMER0_COMP:  SET_BIT(TIMER_TIMSK,1); break;
	case GPT_INIT_SOURCE_TIMER1_OVF:   SET_BIT(TIMER_TIMSK,2); break;
	case GPT_INIT_SOURCE_TIMER1_COMPB: SET_BIT(TIMER_TIMSK,3); break;
	case GPT_INIT_SOURCE_TIMER1_COMPA: SET_BIT(TIMER_TIMSK,4); break;
	case GPT_INIT_SOURCE_TIMER2_OVF:   SET_BIT(TIMER_TIMSK,6); break;
	case GPT_INIT_SOURCE_TIMER2_COMP:  SET_BIT(TIMER_TIMSK,7); break;
	default:  break;
	}
}
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Interrupt Disable >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void GPT_voidInerruptDisable  (Gpt_SourceInterrputType Source)
{
	switch (Source)
	{
	case GPT_INIT_SOURCE_TIMER0_OVF:   CLR_BIT(TIMER_TIMSK,0); break;
	case GPT_INIT_SOURCE_TIMER0_COMP:  CLR_BIT(TIMER_TIMSK,1); break;
	case GPT_INIT_SOURCE_TIMER1_OVF:   CLR_BIT(TIMER_TIMSK,2); break;
	case GPT_INIT_SOURCE_TIMER1_COMPB: CLR_BIT(TIMER_TIMSK,3); break;
	case GPT_INIT_SOURCE_TIMER1_COMPA: CLR_BIT(TIMER_TIMSK,4); break;
	case GPT_INIT_SOURCE_TIMER2_OVF:   CLR_BIT(TIMER_TIMSK,6); break;
	case GPT_INIT_SOURCE_TIMER2_COMP:  CLR_BIT(TIMER_TIMSK,7); break;
	default:  break;
	}
}
void GPT_voidSetCallBack (Gpt_SourceInterrputType Source , void (*CallBack)(void))
{
    switch (Source)
    {
    case GPT_INIT_SOURCE_TIMER0_OVF:   Callback_Gpt_TIM0_OVF=CallBack;   break;
    case GPT_INIT_SOURCE_TIMER0_COMP:  Callback_Gpt_TIM0_COMP=CallBack;  break;
    case GPT_INIT_SOURCE_TIMER1_OVF:   Callback_Gpt_TIM1_OVF=CallBack;   break;
    case GPT_INIT_SOURCE_TIMER1_COMPA: Callback_Gpt_TIM1_COMPA=CallBack; break;
    case GPT_INIT_SOURCE_TIMER1_COMPB: Callback_Gpt_TIM1_COMPB=CallBack; break;
    case GPT_INIT_SOURCE_TIMER2_OVF:   Callback_Gpt_TIM2_OVF=CallBack;   break;
    case GPT_INIT_SOURCE_TIMER2_COMP:  Callback_Gpt_TIM2_COMP=CallBack;  break;
    default:   break;
    }
}


