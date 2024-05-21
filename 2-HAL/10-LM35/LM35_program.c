#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "ADC_config.h"



u8 Lm35_u8GetTemperature (Adc_ChannelType adcChannel,u8 avgCount, u8 delayMs)
{
    u8 i;
    u32 result = 0;
    for (i=0; i<avgCount; i++)
    {
        Adc_StartConversion(adcChannel);
        result += Adc_GetResult();
        _delay_ms(delayMs);
    }
    result /= avgCount;
    return ((result*500)/1024);
}
