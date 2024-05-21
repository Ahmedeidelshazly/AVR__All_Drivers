/****************************************************/
/****************************************************/
/*********     Author : Ahmed el.shazly  ************/
/*********     Layer  : MCAL             ************/
/*********     SWC    : INTERRUPT        ************/
/*********     version: 1.00             ************/
/****************************************************/
/****************************************************/


#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_

typedef enum
{
    EXTINIT_SOURCE_INIT0,
    EXTINIT_SOURCE_INIT1,
    EXTINIT_SOURCE_INIT2,
}EXTINIT_SourcType;

typedef enum
{
    EXTINIT_SENSE_LOW_LEVEL,
    EXTINIT_SENSE_ON_CHANGE,
    EXTINIT_SENSE_FALLING_EDGE,
    EXTINIT_SENSE_RISING_EDGE,
}EXTINIT_SenceControlType;

void EXT_voidSetSenseControl(EXTINIT_SenceControlType sense,EXTINIT_SourcType Source );
void EXT_voidEnableInterrupt(EXTINIT_SourcType Source);
void EXT_voidDisableInterrupt(EXTINIT_SourcType Source);
void EXT_voidSetCallBack(EXTINIT_SourcType Source,void(*pv_CallBack) (void));

#endif