#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PWM_config.h"
#include "PWM_private.h"
#include "PWM_register.h"
#include "PWM_interface.h"

void PWM_voidTimer0Init(void)
{
    /* Set Compare Output Mode as a non inverting */
    #if COMPARE_OUT_MODE0 ==NORMAL
    CLR_BIT(TCCR0,4);
    CLR_BIT(TCCR0,5);
    #elif COMPARE_OUT_MODE0 ==NON_INVERTING
    CLR_BIT(TCCR0,4);
    SET_BIT(TCCR0,5);
    #elif COMPARE_OUT_MODE0 ==INVERTING
    SET_BIT(TCCR0,4);
    SET_BIT(TCCR0,5);
    #endif

    /* Wave Form Generation Mode */
    #if PWM_GenerationWaveForm0 == PWM_NORMAL
    CLR_BIT(TCCR0,3);
    CLR_BIT(TCCR0,6);
	#elif PWM_GenerationWaveForm0 == PWM_PHASE_CORRECT
    CLR_BIT(TCCR0,3);
    SET_BIT(TCCR0,6);
	#elif PWM_GenerationWaveForm0 == PWM_CTC
    SET_BIT(TCCR0,3);
    CLR_BIT(TCCR0,6);
	#elif PWM_GenerationWaveForm0 == PWM_FAST
    SET_BIT(TCCR0,3);
    SET_BIT(TCCR0,6);
    #endif

    /*Setting prescaller */
    #if PRESCALLER_SELECT ==NO_PRESCALLER
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=NO_PRESCALLER;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_8
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_8;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_64
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_64;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_256
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_256;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_1024
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_1024;

    #elif PRESCALLER_SELECT ==FALLING_EDGE_EX_CLK
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=FALLING_EDGE_EX_CLK;

    #elif PRESCALLER_SELECT ==RISING_EDGE_EX_CLK
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=RISING_EDGE_EX_CLK;

    #endif
}


void PWM_voidTimer1Init(void)
{
    /* Set Compare Output Mode as a non inverting */
#if CHANNEL_SELECT==CHANNEL_A
    #if COMPARE_OUT_MODE ==NORMAL
    CLR_BIT(TCCR1A,6);
    CLR_BIT(TCCR1A,7);
    #elif COMPARE_OUT_MODE ==NON_INVERTING
    CLR_BIT(TCCR1A,6);
    SET_BIT(TCCR1A,7);
    #elif COMPARE_OUT_MODE ==INVERTING
    SET_BIT(TCCR1A,6);
    SET_BIT(TCCR1A,7);
    #endif

#elif CHANNEL_SELECT==CHANNEL_B
    #if COMPARE_OUT_MODE ==NORMAL
    CLR_BIT(TCCR1B,6);
    CLR_BIT(TCCR1B,7);
    #elif COMPARE_OUT_MODE ==NON_INVERTING
    CLR_BIT(TCCR1B,6);
    SET_BIT(TCCR1B,7);
    #elif COMPARE_OUT_MODE ==INVERTING
    SET_BIT(TCCR1B,6);
    SET_BIT(TCCR1B,7);
    #endif 
#endif


    /* Wave Form Generation Mode */
    #if PWM_GenerationWaveForm == PWM_NORMAL
    CLR_BIT(TCCR1A,0);
    CLR_BIT(TCCR1A,1);
    CLR_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4); 
    #elif PWM_GenerationWaveForm ==PWM_PHASE_CORRECT_8BIT
    SET_BIT(TCCR1A,0);
    CLR_BIT(TCCR1A,1);
    CLR_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4); 
    #elif PWM_GenerationWaveForm ==PWM_PHASE_CORRECT_9BIT
    CLR_BIT(TCCR1A,0);
    SET_BIT(TCCR1A,1);
    CLR_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4); 
    #elif PWM_GenerationWaveForm ==PWM_PHASE_CORRECT_10BIT
    SET_BIT(TCCR1A,0);
    SET_BIT(TCCR1A,1);
    CLR_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4); 
    #elif PWM_GenerationWaveForm ==PWM_PHASE_CORRECT_ICR1
    CLR_BIT(TCCR1A,0);
    SET_BIT(TCCR1A,1);
    CLR_BIT(TCCR1B,3);
    SET_BIT(TCCR1B,4); 
    #elif PWM_GenerationWaveForm ==PWM_FASE_8BIT
    SET_BIT(TCCR1A,0);
    CLR_BIT(TCCR1A,1);
    SET_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4); 
    #elif PWM_GenerationWaveForm ==PWM_FASE_9BIT
    CLR_BIT(TCCR1A,0);
    SET_BIT(TCCR1A,1);
    SET_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4); 
    #elif PWM_GenerationWaveForm ==PWM_FASE_10BIT
    SET_BIT(TCCR1A,0);
    SET_BIT(TCCR1A,1);
    SET_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4);
    #elif PWM_GenerationWaveForm ==PWM_FAST_ICR1
    CLR_BIT(TCCR1A,0);
    SET_BIT(TCCR1A,1);
    SET_BIT(TCCR1B,3);
    SET_BIT(TCCR1B,4); 
    #endif


    /*Setting prescaller */
    #if PRESCALLER_SELECT ==NO_PRESCALLER
    TCCR1B&=PRESCALLER_MASK;
    TCCR1B|=NO_PRESCALLER;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_8
    TCCR1B&=PRESCALLER_MASK;
    TCCR1B|=DIVIDE_BY_8;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_64
    TCCR1B&=PRESCALLER_MASK;
    TCCR1B|=DIVIDE_BY_64;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_256
    TCCR1B&=PRESCALLER_MASK;
    TCCR1B|=DIVIDE_BY_256;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_1024
    TCCR1B&=PRESCALLER_MASK;
    TCCR1B|=DIVIDE_BY_1024;

    #elif PRESCALLER_SELECT ==FALLING_EDGE_EX_CLK
    TCCR1B&=PRESCALLER_MASK;
    TCCR1B|=FALLING_EDGE_EX_CLK;

    #elif PRESCALLER_SELECT ==RISING_EDGE_EX_CLK
    TCCR1B&=PRESCALLER_MASK;
    TCCR1B|=RISING_EDGE_EX_CLK;

    #endif    
}

void PWM_voidTimer2Init(void)
{
    /* Set Compare Output Mode as a non inverting */
    #if COMPARE_OUT_MODE0 ==NORMAL
    CLR_BIT(TCCR2,4);
    CLR_BIT(TCCR2,5);
    #elif COMPARE_OUT_MODE0 ==NON_INVERTING
    CLR_BIT(TCCR2,4);
    SET_BIT(TCCR2,5);
    #elif COMPARE_OUT_MODE0 ==INVERTING
    SET_BIT(TCCR2,4);
    SET_BIT(TCCR2,5);
    #endif

    /* Wave Form Generation Mode */
    #if PWM_GenerationWaveForm0 == PWM_NORMAL
    CLR_BIT(TCCR2,3);
    CLR_BIT(TCCR2,6);
	#elif PWM_GenerationWaveForm0 == PWM_PHASE_CORRECT
    CLR_BIT(TCCR2,3);
    SET_BIT(TCCR2,6);
	#elif PWM_GenerationWaveForm0 == PWM_CTC
    SET_BIT(TCCR2,3);
    CLR_BIT(TCCR2,6);
	#elif PWM_GenerationWaveForm0 == PWM_FAST
    SET_BIT(TCCR2,3);
    SET_BIT(TCCR2,6);
    #endif

    /*Setting prescaller */
    #if PRESCALLER_SELECT ==NO_PRESCALLER
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=NO_PRESCALLER;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_8
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_8;


    #elif PRESCALLER_SELECT ==DIVIDE_BY_32
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_32;



    #elif PRESCALLER_SELECT ==DIVIDE_BY_64_T2
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_64;

    
    #elif PRESCALLER_SELECT ==DIVIDE_BY_128
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_128;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_256_T2
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_256;

    #elif PRESCALLER_SELECT ==DIVIDE_BY_1024_T2
    TCCR0&=PRESCALLER_MASK;
    TCCR0|=DIVIDE_BY_1024;

    #endif
}



void PWM_voidSetICR1(u16 Copy_u16Top)
{
    ICR1 = Copy_u16Top;
}

void PWM_voidSetOCR (u16 Copy_u16CompareValue)
{
    #if CHANNEL_SELECT==CHANNEL_A
    OCR1A=Copy_u16CompareValue;
    #elif CHANNEL_SELECT==CHANNEL_B
    OCR1B=Copy_u16CompareValue;
    #endif

}

void PWM_voidSetOCR0 (u8 Copy_u16CompareValue)
{
    
    OCR0=Copy_u16CompareValue;
}

void PWM_voidSetOCR2 (u8 Copy_u16CompareValue)
{
    
    OCR2=Copy_u16CompareValue;
}


void servo (u8 Copy_u8Degree)
{
    if (Copy_u8Degree==0)
    {
        OCR1A=1000;
    }
    else if (Copy_u8Degree==90)
    {
        OCR1A=1500;
    }
    else if (Copy_u8Degree==180)
    {
        OCR1A=2000;
    }
}


