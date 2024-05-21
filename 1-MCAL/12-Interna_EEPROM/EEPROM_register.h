/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : EEPROM            ***************/
/********************************************************/
/********************************************************/

#ifndef EEPROM_REGISTER_H_
#define EEPROM_REGISTER_H_
/*01114644170*/

/*<<<<<<<<<<<<<<<<<EEPROM Address Register >>>>>>>*/
#define EEPROM_EEARL      *((volatile u16*)0X3E)
/*<<<<<<<<<<<<<<<<<EEPROM Data Register >>>>>>>>>>*/
#define EEPROM_EEDR       *((volatile u8*)0X3D)
/*<<<<<<<<<<<<<<<<<EEPROM Control Register >>>>>>>*/
#define EEPROM_EECR       *((volatile u8*)0X3C)
#define EEPROM_EECR_EERIE 3
#define EEPROM_EECR_EEMWE 2
#define EEPROM_EECR_EEWE  1
#define EEPROM_EECR_EERE  0

#define EEPROM_SPMCR       *((volatile u8*)0X57)
#define EEPROM_SPMCR_SPMEN 0
/*<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>*/
#endif 
