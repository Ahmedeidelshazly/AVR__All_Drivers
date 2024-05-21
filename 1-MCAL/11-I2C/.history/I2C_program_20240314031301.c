/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : I2C               ***************/
/********************************************************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "I2C-config.h"
#include "I2C_private.h"
#include "I2C_interface.h"
#include "I2C_register.h"


void TWI_voidMasterInit(u8 Copy_u8MasterAddress)
{
    if (Copy_u8MasterAddress != 0)
    {
        /*Initalize The Node Address */
        /* Most Segnificant 7 bits so should shiffted by 1*/
        TWAR = Copy_u8MasterAddress<<1;
    }
    else 
    {
        /* Set Clock By the equation which hold TWBR and TWPS ==> Clock 400KBPS */
        /*Make TWSR ==> TWSR_TWPS0 =0  ,  TWSR_TWPS1 =0  then Make TWBR =2 */
        TWBR = 2;
        TWSR = 0;
    }
    /* Enable TWI */
    SET_BIT(TWCR , TWCR_TWEN);
}

void TWI_voidSlaveInit (u8 Copy_u8SlaveAddress )
{
    /*Initalize The Node Address */
    TWAR = Copy_u8SlaveAddress <<1;
    /* Enable TWI */
    SET_BIT(TWCR , TWCR_TWEN);
}

TWI_ErrorStatus TWI_SendStartCondition (void)
{
    TWI_ErrorStatus Local_ErrorStatus =  NO_ERROR;
    /* Send Start Condition */
    SET_BIT(TWCR , TWCR_TWSTA);

    /*Clear the Interrput Flag To start the pervious operation (start condition)*/
    SET_BIT (TWCR , TWCR_TWINT);

    /*Waiting till the Flag is rised again and the pervious operation is complete*/
    while (GET_BIT (TWCR , TWCR_TWINT)==0);

    if ((TWSR && 0xf8)!=Start_AC)
    {
        Local_ErrorStatus = START_ERROR;
    }
    else
    {
        //do nothing
    }
    return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendRepeatedStartCondition(void)
{
    TWI_ErrorStatus Local_ErrorStatus =  NO_ERROR;
    /* Send Start Condition */
    SET_BIT(TWCR , TWCR_TWSTA);

    /*Clear the Interrput Flag To start the pervious operation (start condition)*/
    SET_BIT (TWCR , TWCR_TWINT);

    /*Waiting till the Flag is rised again and the pervious operation is complete*/
    while (GET_BIT (TWCR , TWCR_TWINT)==0);

    if ((TWSR && 0xf8)!=RE_Start_AC)
    {
        Local_ErrorStatus = REPEATE_START_ERROR;
    }
    else
    {
        //do nothing
    }
    return Local_ErrorStatus;

}

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress )
{
    TWI_ErrorStatus Local_ErrorStatus =  NO_ERROR;
    /* Clear Start Condition */
    CLR_BIT(TWCR , TWCR_TWSTA);
    /*Send Slave Address With Write Slave 1 : 7 and Write 0 */
    TWDR = Copy_u8SlaveAddress <<1;  /* Address is in 7 Most bits                  */
    CLR_BIT (TWDR ,0);               /* For make Sure that the bit of write is zero */

     /*Clear the Interrput Flag To start the pervious operation (start condition)*/
    SET_BIT (TWCR , TWCR_TWINT);

    /*Waiting till the Flag is rised again and the pervious operation is complete*/
    while (GET_BIT (TWCR , TWCR_TWINT)==0);

    if ((TWSR && 0xf8)!=Salve_Add_WR_AC)
    {
        Local_ErrorStatus = SEND_SLAVE_ADD_WITH_WR;
    }
    else
    {
        //do nothing
    }
    return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithRead (u8 Copy_u8SlaveAddress )
{
    TWI_ErrorStatus Local_ErrorStatus =  NO_ERROR;
    /* Clear Start Condition */
    CLR_BIT(TWCR , TWCR_TWSTA);
    /*Send Slave Address With Write Slave 1 : 7 and Write 0 */
    TWDR = Copy_u8SlaveAddress <<1;  /* Address is in 7 Most bits                  */
    SET_BIT (TWDR ,0);               /* For make Sure that the bit of Read is one */

     /*Clear the Interrput Flag To start the pervious operation (start condition)*/
    SET_BIT (TWCR , TWCR_TWINT);

    /*Waiting till the Flag is rised again and the pervious operation is complete*/
    while (GET_BIT (TWCR , TWCR_TWINT)==0);

    if ((TWSR && 0xf8)!=Salve_Add_RD_AC)
    {
        Local_ErrorStatus = SEND_SLAVE_ADD_WITH_RD;
    }
    else
    {
        //do nothing
    }
    return Local_ErrorStatus; 
}

TWI_ErrorStatus TWI_MasterWriteDataByte (u8 Copy_u8DataByte   )
{
    TWI_ErrorStatus Local_ErrorStatus =  NO_ERROR;
    /*Write the Data Byte */
    TWDR = Copy_u8DataByte;
     /*Clear the Interrput Flag To start the pervious operation (start condition)*/
    SET_BIT (TWCR , TWCR_TWINT);

    /*Waiting till the Flag is rised again and the pervious operation is complete*/
    while (GET_BIT (TWCR , TWCR_TWINT)==0);

    if ((TWSR && 0xf8)!=Master_WR_AC)
    {
        Local_ErrorStatus = MASTER_WR_DATA_ERROR;
    }
    else
    {
        //do nothing
    }
    return Local_ErrorStatus; 

}
TWI_ErrorStatus TWI_MasterReadDataByte (u8* Copy_pu8DataByte )
{
    TWI_ErrorStatus Local_ErrorStatus =  NO_ERROR;
    /*Enable TWI */
    SET_BIT (TWCR,TWCR_TWEN);
     /*Clear the Interrput Flag To start the pervious operation (start condition)*/
    SET_BIT (TWCR , TWCR_TWINT);
    /*Waiting till the Flag is rised again and the pervious operation is complete*/
    while (GET_BIT (TWCR , TWCR_TWINT)==0);
    if ((TWSR && 0xf8)!=Master_RD_AC)
    {
        Local_ErrorStatus = MASTER_RD_DATA_ERROR;
    }
    else
    {
        *Copy_pu8DataByte - TWDR;
    }
    return Local_ErrorStatus; 

}

void TWI_voidSendStopCondition (Void)
{
    
}