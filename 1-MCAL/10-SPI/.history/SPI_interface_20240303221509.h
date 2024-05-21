/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : SPI               ***************/
/********************************************************/
/********************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMasterInit(void                              );
void SPI_VoidSlaveInit (void                              );
u8   SPI_u8Tranceive   (u8 Copy_u8Data , u8* Copy_Ptr_Data);




#endif