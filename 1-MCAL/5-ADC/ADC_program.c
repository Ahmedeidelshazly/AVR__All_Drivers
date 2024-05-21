/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MHAL              ***************/
/*********     SWC    : ADC               ***************/
/*********     Date   : 3/10/2023         ***************/
/********************************************************/
/********************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"

void (*Callback_Adc) (Adc_ChannelType channel, u16 result) = NULL;
StdReturnType ADC_INIT(Adc_ConfigurationType* config)
{
	StdReturnType retval=E_OK;
	if (ADC_REF_AREF==config->reference)
	{
		CLR_BIT(ADMUX ,ADMUX_REF0);
		CLR_BIT(ADMUX ,ADMUX_REF1);
	}
	else if (ADC_REF_AVCC==config->reference)
	{
		SET_BIT(ADMUX ,ADMUX_REF0);
		CLR_BIT(ADMUX ,ADMUX_REF1);
	}
	else if (ADC_REF_INTERNAL==config->reference)
	{
		SET_BIT(ADMUX ,ADMUX_REF0);
		SET_BIT(ADMUX ,ADMUX_REF1);
	}
	else
	{
		retval =E_NOT_OK;
	}
	/*ADC LEFT ADJUST RESULT (OFF)*/
	CLR_BIT(ADMUX ,ADMUX_ADLAR);
	switch(config->autoTrigger)
	{
	case ADC_AUTO_TRIGGER_OFF:
		CLR_BIT(ADCSRA,ADCSRA_ADATE);
		break;
	case ADC_AUTO_TRIGGER_FREE_RUNNING:
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		CLR_BIT(SFIOR,SFIOR_ADTS0);
		CLR_BIT(SFIOR,SFIOR_ADTS1);
		CLR_BIT(SFIOR,SFIOR_ADTS2);
		break;
	case ADC_AUTO_TRIGGER_ANAL_COMP:
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		SET_BIT(SFIOR,SFIOR_ADTS0);
		CLR_BIT(SFIOR,SFIOR_ADTS1);
		CLR_BIT(SFIOR,SFIOR_ADTS2);
		break;
	case ADC_AUTO_TRIGGER_EXTI0:
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		CLR_BIT(SFIOR,SFIOR_ADTS0);
		SET_BIT(SFIOR,SFIOR_ADTS1);
		CLR_BIT(SFIOR,SFIOR_ADTS2);
		break;
	case ADC_AUTO_TRIGGER_TIM0_COMP:
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		SET_BIT(SFIOR,SFIOR_ADTS0);
		SET_BIT(SFIOR,SFIOR_ADTS1);
		CLR_BIT(SFIOR,SFIOR_ADTS2);
		break;
	case ADC_AUTO_TRIGGER_TIM0_OVF:
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		CLR_BIT(SFIOR,SFIOR_ADTS0);
		CLR_BIT(SFIOR,SFIOR_ADTS1);
		SET_BIT(SFIOR,SFIOR_ADTS2);
		break;
	case ADC_AUTO_TRIGGER_TIMB_COMP:
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		SET_BIT(SFIOR,SFIOR_ADTS0);
		CLR_BIT(SFIOR,SFIOR_ADTS1);
		SET_BIT(SFIOR,SFIOR_ADTS2);
		break;
	case ADC_AUTO_TRIGGER_TIM1_OVF:
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		CLR_BIT(SFIOR,SFIOR_ADTS0);
		SET_BIT(SFIOR,SFIOR_ADTS1);
		SET_BIT(SFIOR,SFIOR_ADTS2);
		break;
	case ADC_AUTO_TRIGGER_TIM1_CAP:
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		SET_BIT(SFIOR,SFIOR_ADTS0);
		SET_BIT(SFIOR,SFIOR_ADTS1);
		SET_BIT(SFIOR,SFIOR_ADTS2);
		break;
	default :retval=E_NOT_OK;

	}
	switch(config->prescaler)
	{
	case ADC_PRESCALER_2:
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
		break;

	case ADC_PRESCALER_4:
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
		break;

	case ADC_PRESCALER_8:
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
		break;

	case ADC_PRESCALER_16:
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		break;

	case ADC_PRESCALER_32:
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		break;

	case ADC_PRESCALER_64:
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	case ADC_PRESCALER_128:
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	default:retval=E_NOT_OK;
	}
	/* ADC Enable */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	return retval;
}

u16 ADC_u8GetChannelReading(Adc_ChannelType Copy_u8Channel)
{

	/*clear the mux bits to ADMUX register and equall ob11100000*/
	ADMUX&=0b11100000;
	/*set the required channel into the mux bits */
	ADMUX|=Copy_u8Channel;
	/*start conversion */
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*polling busy waiting till the conversion complete flag is set */
	while (GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	/*clear the conversion complete flag */
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	/*return the value */
	return ADC;
}

u16 ADC_u8GetChannelReadingSynchronous(Adc_ChannelType Copy_u8Channel , u16* Copy_PtvReading)
{
	u32 Local_u32Counter=0 ;
	u8 ADC_BUSY_STATE;
	StdReturnType Return_Value = E_OK;
	if (Copy_u8Channel <=ADC_CHANNEL_GND)
	{
		if (ADC_BUSY_STATE == IDLE)
		{
			/*Make The State of The ADC ==> Busy*/
			ADC_BUSY_STATE=BUSY;
			/*clear the mux bits to ADMUX register and equall ob11100000*/
			ADMUX&=0b11100000;
			/*set the required channel into the mux bits */
			ADMUX|=Copy_u8Channel;
			/*start conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*polling busy waiting till the conversion complete flag is set */
			while ((GET_BIT(ADCSRA,ADCSRA_ADIF)==0) && ADC_U32TIME_OUT !=Local_u32Counter)
			{
				Local_u32Counter ++;
			}
			/*clear the conversion complete flag */
			if (ADC_U32TIME_OUT == Local_u32Counter)
			{
				/*The Loop is broken by The Counter */
				Return_Value = E_NOT_OK;
			}
			else
			{
				/*The Loop is broken by the Flag */
				/*Set the Flag for the next time */
				SET_BIT(ADCSRA,ADCSRA_ADIF);
				*Copy_PtvReading =ADC;
				ADC_BUSY_STATE =IDLE;
			}
		}
		else
		{
			Local_u32Counter=BUSY_FUNC;
		}
	}
	else
	{
		Return_Value = E_NOT_OK;
	}
	/*return the value */
	return Return_Value;
}

StdReturnType ADC_StartConversion(Adc_ChannelType channel)
{
	StdReturnType retval=E_OK;
	if (channel<=ADC_CHANNEL_GND)
	{
		while (GET_BIT(ADCSRA,ADCSRA_ADSC));
		ADMUX&=0b111000000;
		ADMUX|=channel;
		SET_BIT(ADCSRA,ADCSRA_ADSC);
	}
	else
	{
		retval=E_NOT_OK;
	}

	return retval;
}

u16 ADC_u16GetResult (void)
{
	/*polling busy waiting till the conversion complete flag is set */
	while (GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	/*clear the conversion complete flag */
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	/*return the value */
	return ADC;
}
void ADC_InterrruptEnable(void)
{
	SET_BIT(ADCSRA,ADCSRA_ADIE);
}

void ADC_InterrruptDisable(void)
{
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

}
