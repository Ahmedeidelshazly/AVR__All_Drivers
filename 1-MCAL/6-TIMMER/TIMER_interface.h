/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : MCAL             ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


typedef enum
{
    GPT_MODE_OFF,
    GPT_MODE_NORMAL,
    GPT_MODE_CTC,
    GPT_MODE_CTC_ICR1
} Gpt_ModeType;

typedef enum 
{
    GPT_COMP0,
    GPT_COMP1A,
    GPT_COMP1B,
    GPT_COMP2
}Gpt_CompareChannelType;

typedef enum
{
    GPT_CLK_OFF,
    GPT_CLK_PRESCALLER_1,
    GPT_CLK_PRESCALLER_8,
    GPT_CLK_PRESCALLER_32,
    GPT_CLK_PRESCALLER_64,
    GPT_CLK_PRESCALLER_128,
    GPT_CLK_PRESCALLER_256,
    GPT_CLK_PRESCALLER_1024,
    GPT_CLK_EXT_FALLIGN_EDGE,
    GPT_CLK_EXT_RISING_EDGE ,
 
}Gpt_Clk_Prescaller_Type;

typedef enum 
{
    GPT_OUT_DISCONCTED,
    GPT_OUT_TOGGLE,
    GPT_OUT_CLR,
    GPT_OUT_SET,

}Gpt_OutputModeType;

typedef enum 
{
    GPT_CHANNEL_TIMER0,
    GPT_CHANNEL_TIMER1,
    GPT_CHANNEL_TIMER2,
}Gpt_Channel_Type;

typedef enum
{
    GPT_INIT_SOURCE_TIMER0_OVF ,
    GPT_INIT_SOURCE_TIMER0_COMP,
    GPT_INIT_SOURCE_TIMER1_OVF ,
    GPT_INIT_SOURCE_TIMER1_COMPA ,
    GPT_INIT_SOURCE_TIMER1_COMPB,
    GPT_INIT_SOURCE_TIMER2_OVF ,
    GPT_INIT_SOURCE_TIMER2_COMP,
}Gpt_SourceInterrputType;


typedef struct 
{
    Gpt_ModeType            Timer0_Mode;
    Gpt_Clk_Prescaller_Type Timer0_Clk;
    Gpt_OutputModeType      Timer0_Output;
    Gpt_ModeType            Timer1_Mode;
    Gpt_Clk_Prescaller_Type Timer1_Clk;
    Gpt_OutputModeType      Timer1A_Output;
    Gpt_OutputModeType      Timer1B_Output;
    Gpt_ModeType            Timer2_Mode;
    Gpt_Clk_Prescaller_Type Timer2_Clk;
    Gpt_OutputModeType      Timer2_Output;
 
}Gpt_ConfigurationType;

extern Gpt_ConfigurationType Gpt_Configuration;
void GPT_voidInit(Gpt_ConfigurationType* config );
void GPT_voidSetCompareValue (Gpt_CompareChannelType  Channel, u16 Copy_u16Value);
void GPT_voidSetCounterValue (Gpt_Channel_Type  Channel, u16 Copy_u16Value);
void GPT_voidSetClockSource  (Gpt_Channel_Type  Channel,Gpt_Clk_Prescaller_Type Clock );
u16  GPT_voidGetTimerValue   (Gpt_Channel_Type Channel);
void GPT_voidInerruptEnable  (Gpt_SourceInterrputType Channel);
void GPT_voidInerruptDisable (Gpt_SourceInterrputType Channel);
void GPT_voidSetCallBack     (Gpt_SourceInterrputType Source , void (*CallBack)(void));

#endif 
