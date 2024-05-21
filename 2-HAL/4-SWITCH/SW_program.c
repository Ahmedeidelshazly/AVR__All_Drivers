#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SW_config.h"
#include "SW_private.h"
#include "SW_interface.h"

/******************************************************************************************/
void SW_voidInit ( SW_Type SW_Config )
{
	/* set pin in the port register and clear it in ddr to make it input and pull up */
	DIO_u8SetPinDirection (SW_Config.Port,SW_Config.Pin,DIO_INPUT_PULL_UP_MODE);
}

/******************************************************************************************/
u8 SW_u8GetPressed ( SW_Type SW_Config )
{
	u8 Local_u8GetPressedKey=SW_NOT_PRESSED_KEY;
	u8 Local_u8GetResult=SW_NOT_PRESSED_KEY ;
	if (SW_Config.Pull_State==SW_Ext_PULL_UP ||SW_Config.Pull_State==SW_Int_PULL_UP )
	{
		DIO_u8GetPinValue(SW_Config.Port, SW_Config.Pin,&Local_u8GetResult);
		
		if(Local_u8GetResult == 0)
		{
			Local_u8GetPressedKey = SW_PRESSED_KEY;
		}
		else if(Local_u8GetResult == 1)
		{
			Local_u8GetPressedKey = SW_NOT_PRESSED_KEY;
		}
	}
	else if (SW_Config.Pull_State== SW_Ext_PULL_DOWN )
	{
		DIO_u8GetPinValue(SW_Config.Port, SW_Config.Pin,&Local_u8GetResult);
		
		if(Local_u8GetResult == 1)
		{
			Local_u8GetPressedKey = SW_PRESSED_KEY;
		}
		else if(Local_u8GetResult == 0)
		{
			Local_u8GetPressedKey = SW_NOT_PRESSED_KEY;
		}
	}
}
/*************************************************************************************************/
