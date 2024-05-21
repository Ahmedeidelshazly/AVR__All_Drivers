#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EEPROM_config.h"
#include "EEPROM_register.h"
#include "EEPROM_private.h"
#include "EEPROM_interface.h"

void EEPROM_voidSendDataByte(u8 Copy_u8Data , u16 Copy_u16Address )
{
    /*********Wait until EEWE becomes zero ********/
    while (GET_BIT(EEPROM_EECR,EEPROM_EECR_EEWE)==1);
    /*********************************************/
    EEPROM_EEARL =Copy_u16Address;
    EEPROM_EEDR  = Copy_u8Data   ;
    /*********************************************/
    SET_BIT(EEPROM_EECR,EEPROM_EECR_EEMWE);
    EEPROM_EECR = EEWE;
}

u8 EEPROM_voidGetDataByte (u16 Copy_u16Address)
{
    /*********Wait until EEWE becomes zero ********/
    while (GET_BIT(EEPROM_EECR,EEPROM_EECR_EEWE)==1);
    /*********************************************/
    EEPROM_EEARL =Copy_u16Address;
    /*********************************************/
    SET_BIT(EEPROM_EECR,EEPROM_EECR_EERE);
    return EEPROM_EEDR;
}
