/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MHAL              ***************/
/*********     SWC    : ADC               ***************/
/*********     Date   : 3/10/2023         ***************/
/********************************************************/
/********************************************************/
#include"STD_TYPES.h"
#include"ADC_config.h"
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

extern Adc_ConfigurationType Adc_Configuration;

StdReturnType ADC_INIT(Adc_ConfigurationType* config);
u16 ADC_u8GetChannelReading(Adc_ChannelType Copy_u8Channel);
u16 ADC_u8GetChannelReadingSynchronous(Adc_ChannelType Copy_u8Channel , u16* Copy_PtvReading);
/*************************************************************/
StdReturnType ADC_StartConversion(Adc_ChannelType channel);
u16 ADC_u16GetResult (void);
/*************************************************************/
void ADC_InterrruptEnable(void);
void ADC_InterrruptDisable(void);


#endif
