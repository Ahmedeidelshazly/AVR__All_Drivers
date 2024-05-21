/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : SPI               ***************/
/********************************************************/
/********************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

/************************************************************************/
#define  SPDR				*((volatile u8*)0x2F) /** SPI Data Register*/
/************************************************************************/

/*************************************************************************/
#define  SPSR				*((volatile u8*)0x2E) /** SPI Status Register*/
#define  SPSR_SPI2X			0                     /*Clock Rate Select Two and double the speed */
#define  SPSR_WCOL			6                     /*Write Colision Flag */
#define  SPSR_SPIF			7                     /*SPI Interrupt Flag*/
/**************************************************************************/


/***************************************************************************/
#define  SPCR				*((volatile u8*)0x2D) /** SPI Control Register*/
#define  SPCR_SPR0			0                     /*Clock Rate Select One  */
#define  SPCR_SPR1			1                     /*Clock Rate Select One */
#define  SPCR_CPHA			2                     /*Clock Phase */
#define  SPCR_CPOL			3                     /*Clock Polarity*/
#define  SPCR_MSTR			4                     /*Master Slave Select */
#define  SPCR_DORD			5                     /*Data Order */
#define  SPCR_SPE			6                     /*SPI Enable */
#define  SPCR_SPIE			7                     /*SPI interrupt enable */

/****************************************************************************/

#endif
