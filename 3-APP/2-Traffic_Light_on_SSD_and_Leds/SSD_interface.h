/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : LIB              ****************/
/*********     SWC   : SSD               ****************/
/********************************************************/
/********************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_OUPUT_PINS      0xff
#define SSD_COMMON_CATHODE  1
#define SSD_COMMON_ANODE    0
typedef struct SSD_interface
{
    u8 Type ;
    u8 Data_Port ;
    u8 Enable_Port;
    u8 Enable_pin ;
}SSD_Type;
 
 /** this function for initlization the SSD port Output only */
void SSD_voidInit                           (SSD_Type SSD_Configuration);
void SSD_voidEnable                         (SSD_Type SSD_Configuration);
void SSD_voidDisable                        (SSD_Type SSD_Configuration);
void SSD_voidDispalyNumber (SSD_Type SSD_Configuration,u8 Copy_u8Number);

#endif


