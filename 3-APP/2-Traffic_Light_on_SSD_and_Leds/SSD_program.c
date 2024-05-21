/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : LIB              ****************/
/*********     SWC   : SSD               ****************/
/********************************************************/
/********************************************************/


#include "STD_TYPES.h"
#include"BIT_MATH.h"



#include "DIO_interface.h"
#include "SSD_config.h"
#include "SSD_private.h" 
#include "SSD_interface.h"


/*********************Local array store the values of the number on it **************/
static u8 Local_u8Arr[10]= SSD_NUMBER_ARRAY;
/******************Intiliaze for SSD only ***********/
void SSD_voidInit     (SSD_Type SSD_Configuration)
{
    DIO_u8SetPortDirection(SSD_Configuration.Data_Port, SSD_OUPUT_PINS);
}

/****************Enable SSD Pin for common *********************************/
void SSD_voidEnable (SSD_Type SSD_Configuration)
{
     if (SSD_Configuration.Type == SSD_COMMON_CATHODE)
     {
        DIO_u8SetPinDirection(SSD_Configuration.Enable_Port , SSD_Configuration.Enable_pin,DIO_OUTPUT_MODE);
        DIO_u8SetPinValue(SSD_Configuration.Enable_Port, SSD_Configuration.Enable_pin,DIO_PIN_LOW);
     }
      if (SSD_Configuration.Type == SSD_COMMON_ANODE)
     {
        DIO_u8SetPinDirection(SSD_Configuration.Enable_Port , SSD_Configuration.Enable_pin,DIO_OUTPUT_MODE);
        DIO_u8SetPinValue(SSD_Configuration.Enable_Port, SSD_Configuration.Enable_pin,DIO_PIN_HIGH);
     }
}

/*****************Disable SSD Pin for common ********************************/
void SSD_voidDisable (SSD_Type SSD_Configuration)
{
     if (SSD_Configuration.Type == SSD_COMMON_CATHODE)
     {
        DIO_u8SetPinDirection(SSD_Configuration.Enable_Port , SSD_Configuration.Enable_pin,DIO_OUTPUT_MODE);
        DIO_u8SetPinValue(SSD_Configuration.Enable_Port, SSD_Configuration.Enable_pin,DIO_PIN_HIGH);
     }
      if (SSD_Configuration.Type == SSD_COMMON_ANODE)
     {
        DIO_u8SetPinDirection(SSD_Configuration.Enable_Port , SSD_Configuration.Enable_pin,DIO_OUTPUT_MODE);
        DIO_u8SetPinValue(SSD_Configuration.Enable_Port, SSD_Configuration.Enable_pin,DIO_PIN_LOW);
     }
}

/***********************Display number on SSD **********************************/
void SSD_voidDispalyNumber (SSD_Type SSD_Configuration,u8 Copy_u8Number)
{
    if (SSD_Configuration.Type == SSD_COMMON_CATHODE)
    {
        DIO_u8SetPortValue(SSD_Configuration.Data_Port ,Local_u8Arr[Copy_u8Number] );
    }
    if (SSD_Configuration.Type == SSD_COMMON_ANODE)
    {
        DIO_u8SetPortValue(SSD_Configuration.Data_Port ,~Local_u8Arr[Copy_u8Number] );
    }
}

