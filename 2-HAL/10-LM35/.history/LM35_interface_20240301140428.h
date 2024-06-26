/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : HAL               ***************/
/*********     SWC    : LM35              ***************/
/********************************************************/
/********************************************************/


#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

u8 Lm35_u8GetTemperature (Adc_ChannelType adcChannel,u8 avgCount, u8 delayMs);

#endif 