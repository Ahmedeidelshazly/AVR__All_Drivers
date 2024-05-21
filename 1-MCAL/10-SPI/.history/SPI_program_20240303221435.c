/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : SPI               ***************/
/********************************************************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"


void SPI_voidMasterInit(void)
{

    /* For Clock Polarity and Clock Phase Should 
    * be same in both master and slave so i let 
    * it as dafult 
    */

    /*Select Master */
    SET_BIT(SPCR,SPCR_MSTR);

    /*Clock Prescaller divide by 16*/
    SET_BIT (SPCR,SPCR_SPR0);
    SET_BIT (SPCR,SPCR_SPR1);
    CLR_BIT(SPSR,SPSR_SPI2X);
    /*SPI Enable */
    SET_BIT(SPCR,SPCR_SPE);
}

void SPI_VoidSlaveInit (void )
{
    /* For Clock Polarity and Clock Phase Should 
    * be same in both master and slave so i let 
    * it as dafult 
    */
    /*Select Slave */
    CLR_BIT(SPCR,SPCR_MSTR);
    /*SPI Enable */
    SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Tranceive (u8 Copy_u8Data , u8* Copy_Ptr_Data);
{
    StdReturnType Return_Value=E_OK;
    u8 Local_u8Counter=0;
    /*Put the value in SPDR */
    SPDR =Copy_u8Data;

    /**wait till transmit complete*/
    while ((GET_BIT(SPSR,SPSR_SPIF)==0) && (Local_u8Counter != SPI_TIME_OUT))
    {
        Local_u8Counter++;
    }

    if (Local_u8Counter == SPI_TIME_OUT)
    {
        Return_Value = E_NOT_OK;
    }
    /*Return it to the user (get the exchange data)*/
    else 
    {
        *Copy_Ptr_Data = UDR;
    }  
    return Return_Value;
}