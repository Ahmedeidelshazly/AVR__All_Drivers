/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MHAL              ***************/
/*********     SWC    : ADC               ***************/
/*********     Date   : 3/10/2023         ***************/
/********************************************************/
/********************************************************/



#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX             *((volatile u8*)0x27)//ADC multiplexer selector register
#define ADMUX_REF1        7                   //reference selection bit1
#define ADMUX_REF0        6                   //reference selection bit1
#define ADMUX_ADLAR       5                   //ADC Left Adjust result  

#define ADCSRA            *((volatile u8*)0x26)//ADC contorl and status registerA
#define ADCSRA_ADEN       7                   //ADC enable 
#define ADCSRA_ADSC       6                   //ADC start conversion
#define ADCSRA_ADATE	  5                   //Auto trigger enable
#define ADCSRA_ADIF       4                   //Interrupt flag
#define ADCSRA_ADIE       3                   //Interrupt enable
#define ADCSRA_ADPS2      2                   //prescaller bit 2
#define ADCSRA_ADPS1      1                   //prescaller bit 1
#define ADCSRA_ADPS0      0                   //prescaller bit 0

/*ADC Auto Trigger Source Select Bits*/
#define SFIOR             *((volatile u8*)0x50)
#define SFIOR_ADTS0       5
#define SFIOR_ADTS1       6
#define SFIOR_ADTS2       7




#define ADC      *((volatile u16*)0x24)       //ADC LOW  register
#define ADCH     *((volatile u8*)0x25)        //ADC High register
#define ADCL     *((volatile u8*)0x24)        //ADC all data form both Low and High  registers


#endif
