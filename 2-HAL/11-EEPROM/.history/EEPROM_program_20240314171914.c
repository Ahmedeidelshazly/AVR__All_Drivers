#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"
#include "EEPROM_interface.h"

void EEPROM_voidSendDataByte(u8 Copy_u8Data , u16 Copy_u16Address )
{
    /*Set Start Condition */
    TWI_SendStartCondition();
    /*Send Slave Addres */
    TWI_SendSlaveAddressWithWrite(EEPROM_FIXED_BITS | A2<<2 | Copy_u16Address >>8);
    /* Send Address Location in EEPROM */
    TWI_MasterWriteDataByte((u8)(Copy_u16Address));
    /* Send Data */
    TWI_MasterWriteDataByte(Copy_u8Data);
    /* Stop Condition */
    TWI_voidSendStopCondition();
}

void EEPROM_voidGetDataByte (u8* Copy_u8Data , u16 Copy_u16Address)
{
    /*Set Start Condition */
    TWI_SendStartCondition();
    /*Send Slave Addres */
    TWI_SendSlaveAddressWithWrite(EEPROM_FIXED_BITS | A2<<2 | Copy_u16Address >>8);
    /* Send Address Location in EEPROM */
    TWI_MasterWriteDataByte((u8)(Copy_u16Address))
    /* Send Repeated Start Condition*/
    TWI_SendRepeatedStartCondition();
    /*Send Slave Address With Read */
    TWI_SendSlaveAddressWithRead(EEPROM_FIXED_BITS | A2<<2 | Copy_u16Address >>8);
    /* Get the Data */
    TWI_MasterReadDataByte(&Copy_u8Data);
    /* Stop Condition */
    TWI_voidSendStopCondition();

}