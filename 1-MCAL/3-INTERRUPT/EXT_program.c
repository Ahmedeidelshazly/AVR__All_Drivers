#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXT_private.h"
#include "EXT_config.h"
#include "EXT_register.h"
#include "EXT_interface.h"

void (*pv_CallBackInit0)(void)=NULL;
void (*pv_CallBackInit1)(void)=NULL;
void (*pv_CallBackInit2)(void)=NULL;


void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
    if (pv_CallBackInit0!=NULL_PTR)
    {
        pv_CallBackInit0;
    }
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
    if (pv_CallBackInit1!=NULL_PTR)
    {
        pv_CallBackInit1;
    }
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
    if (pv_CallBackInit2!=NULL_PTR)
    {
        pv_CallBackInit2;
    }
}

void EXT_voidSetSenseControl(EXTINIT_SenceControlType sense,EXTINIT_SourcType Source )
{
    switch (Source)
    {
    case EXTINIT_SOURCE_INIT0:
        switch (sense)
        {
        case EXTINIT_SENSE_LOW_LEVEL:    CLR_BIT(MCUCR,0);  CLR_BIT(MCUCR,1); break;
        case EXTINIT_SENSE_ON_CHANGE:    SET_BIT(MCUCR,0);  CLR_BIT(MCUCR,1); break; 
        case EXTINIT_SENSE_FALLING_EDGE: CLR_BIT(MCUCR,0);  SET_BIT(MCUCR,1); break; 
        case EXTINIT_SENSE_RISING_EDGE:  SET_BIT(MCUCR,0);  SET_BIT(MCUCR,1); break; 
        default:    break;
        }
        break;
    case EXTINIT_SOURCE_INIT1:
        switch (sense)
        {
        case EXTINIT_SENSE_LOW_LEVEL:    CLR_BIT(MCUCR,2);  CLR_BIT(MCUCR,3); break;
        case EXTINIT_SENSE_ON_CHANGE:    SET_BIT(MCUCR,2);  CLR_BIT(MCUCR,3); break; 
        case EXTINIT_SENSE_FALLING_EDGE: CLR_BIT(MCUCR,2);  SET_BIT(MCUCR,3); break; 
        case EXTINIT_SENSE_RISING_EDGE:  SET_BIT(MCUCR,2);  SET_BIT(MCUCR,3); break; 
        default:    break;
        }
        break;
    case EXTINIT_SOURCE_INIT2:
        switch (sense)
        {
        case EXTINIT_SENSE_FALLING_EDGE: CLR_BIT(MCUCSR,6);   break; 
        case EXTINIT_SENSE_RISING_EDGE:  SET_BIT(MCUCSR,6);   break; 
        default:    break;
        }
        break;
    
    default:   break;
    }
}

void EXT_voidEnableInterrupt(EXTINIT_SourcType Source)
{
    switch (Source)
    {
    case EXTINIT_SOURCE_INIT0: SET_BIT(GICR,6); break;
    case EXTINIT_SOURCE_INIT1: SET_BIT(GICR,7); break;
    case EXTINIT_SOURCE_INIT2: SET_BIT(GICR,5); break;
    
    default:  break;
    }
}

void EXT_voidDisableInterrupt(EXTINIT_SourcType Source)
{
    switch (Source)
    {
    case EXTINIT_SOURCE_INIT0: CLR_BIT(GICR,6); break;
    case EXTINIT_SOURCE_INIT1: CLR_BIT(GICR,7); break;
    case EXTINIT_SOURCE_INIT2: CLR_BIT(GICR,5); break;
 
    default:  break;
    }
}

void EXT_voidSetCallBack(EXTINIT_SourcType Source,void(*pv_CallBack) (void))
{
    switch (Source)
    {
    case EXTINIT_SOURCE_INIT0: 
        if (pv_CallBack!=NULL)
        {
            pv_CallBackInit0=pv_CallBack;
        }
    break;

    case EXTINIT_SOURCE_INIT1: 
        if (pv_CallBack!=NULL)
        {
            pv_CallBackInit1=pv_CallBack;
        }
    break;

    case EXTINIT_SOURCE_INIT2: 
        if (pv_CallBack!=NULL)
        {
            pv_CallBackInit2=pv_CallBack;
        }
    break;
    
    default:  break;
    }

}