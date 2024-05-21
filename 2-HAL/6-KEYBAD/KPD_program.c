#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"
#include "KPD_interface.h"




/************* KeyPad Key Index ***************/                         
/*         Col_0    Col_1   Col_2   Col_3     */
/*	                                          */
/* row_0      1        2       3       4      */
/*	                                          */
/* row_1  	  5        6       7       8      */
/*	                                          */
/* row_2	  9        10      11      12     */
/*	                                          */
/* row_3	  13       14      15      16     */
/**********************************************/

/******** This function for initlize pins for the keypad *************/
void KPD_voidInit ()
{
    /*****************Set all colums pins as a output ***********************/
    DIO_u8SetPinDirection(KPD_PORT,KPD_COLUM0,DIO_OUTPUT_MODE);
    DIO_u8SetPinDirection(KPD_PORT,KPD_COLUM1,DIO_OUTPUT_MODE);
    DIO_u8SetPinDirection(KPD_PORT,KPD_COLUM2,DIO_OUTPUT_MODE);
    DIO_u8SetPinDirection(KPD_PORT,KPD_COLUM3,DIO_OUTPUT_MODE);

    /*****************Set all colums pins as a output High*******************/
    DIO_u8SetPinValue(KPD_PORT,KPD_COLUM0,DIO_PIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT,KPD_COLUM1,DIO_PIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT,KPD_COLUM2,DIO_PIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT,KPD_COLUM3,DIO_PIN_HIGH);


    /*******************Set all Rows pins as a input pull up *****************/
    DIO_u8SetPinDirection(KPD_PORT,KPD_ROW0,DIO_INPUT_PULL_UP_MODE);
    DIO_u8SetPinDirection(KPD_PORT,KPD_ROW1,DIO_INPUT_PULL_UP_MODE);
    DIO_u8SetPinDirection(KPD_PORT,KPD_ROW2,DIO_INPUT_PULL_UP_MODE);
    DIO_u8SetPinDirection(KPD_PORT,KPD_ROW3,DIO_INPUT_PULL_UP_MODE);

}

u8 KPD_GetPressedKey ()
{
    /*************************Using helper variables ***************************/
    /*Local_u8ColumIndex ==> iterator for the array of the colums 
    * Local_u8RowIndex   ==> iterator for the array of the Rows 
    * Local_u8Result     ==> store the value of the row in it if it pressed or not  
    * Local_u8PressedKey ==> store the value of the array which defined in the config like '9'
    */
    u8 Local_u8ColumIndex =0 ,Local_u8RowIndex =0 ,Local_u8Result,Local_u8PressedKey=KPD_NO_PRESSED_KEY;
    /* arrays you will use in the driver */
    static u8 Arr [ROWS_NUM][COLUMS_NUM]=KPD_ARRAY;
    static u8 Arr_Colums[COLUMS_NUM]={KPD_COLUM0,KPD_COLUM1,KPD_COLUM2,KPD_COLUM3};
    static u8 Arr_Rows[ROWS_NUM]={KPD_ROW0,KPD_ROW1,KPD_ROW2,KPD_ROW3};

    for (Local_u8ColumIndex=0 ;Local_u8ColumIndex<COLUMS_NUM ;Local_u8ColumIndex++)
    {
        /*******   activate colums as a output high **********/
        DIO_u8SetPinValue(KPD_PORT,Arr_Colums[Local_u8ColumIndex],DIO_PIN_LOW);
        for (Local_u8RowIndex=0 ;Local_u8RowIndex<ROWS_NUM;Local_u8RowIndex++)
        {
            /***********Read Current Row to know if it is pressed or not ********/
            DIO_u8GetPinValue(KPD_PORT,Arr_Rows[Local_u8RowIndex],&Local_u8Result);
        	/*check if the switch is pressed */
			/*why low because I make pull up already if the switch is pressed */
            if (Local_u8Result==DIO_PIN_LOW)
            {
                Local_u8PressedKey=Arr[Local_u8RowIndex][Local_u8ColumIndex];
                
                /* polling means when i pressed at the switch 
                * nothing happen untill the user take his hand away from the switch */
				/*busy waiting */
				//while because i need to wait for the specifc condition
                //busy waiting untill the key is release

                while (Local_u8Result==DIO_PIN_LOW)
                {
                    DIO_u8GetPinValue(KPD_PORT,Arr_Rows[Local_u8RowIndex],&Local_u8Result);
                }
                return Local_u8PressedKey;
            }
        }
        /*deactivate current column */
        DIO_u8SetPinValue(KPD_PORT,Arr_Colums[Local_u8ColumIndex],DIO_PIN_HIGH);
    }

    return Local_u8PressedKey;
}
