/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : I2C               ***************/
/********************************************************/
/********************************************************/

#ifndef I2c_INTERFACE_H_
#define I2C_INTERFACE_H_

/* Enum for Error Types */
typedef enum 
{
    NO_ERROR   ,
    START_ERROR,
    REPEATE_START_ERROR,
    SEND_SLAVE_ADD_WITH_WR,
    SEND_SLAVE_ADD_WITH_RD,
    MASTER_WR_DATA_ERROR,
    MASTER_RD_DATA_ERROR,

}TWI_ErrorStatus;

/*********************************************************************/
/*
    pass 0 if Master Init So there is No address for the master 
    else   for Slave Init So there is a address for the slave 
*/
void TWI_voidMasterInit(u8 Copy_u8MasterAddress);
void TWI_voidSlaveInit (u8 Copy_u8SlaveAddress );
/*********************************************************************/
TWI_ErrorStatus TWI_SendStartCondition        (void);
TWI_ErrorStatus TWI_SendRepeatedStartCondition(void);
/*********************************************************************/
TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress );
TWI_ErrorStatus TWI_SendSlaveAddressWithRead (u8 Copy_u8SlaveAddress );
/**********************************************************************/
TWI_ErrorStatus TWI_MasterWriteDataByte  (u8 Copy_u8DataByte   );
TWI_ErrorStatus TWI_MasterReadDataByte   (u8* Copy_pu8DataByte );
/**********************************************************************/
void TWI_voidSendStopCondition (Void);
/**********************************************************************/





#endif