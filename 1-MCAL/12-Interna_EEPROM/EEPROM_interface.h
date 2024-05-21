/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : HAL               ***************/
/*********     SWC    : EEPROM            ***************/
/********************************************************/
/********************************************************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidSendDataByte(u8 Copy_u8Data , u16 Copy_u16Address );
u8 EEPROM_voidGetDataByte (u16 Copy_u16Address);



#endif 
