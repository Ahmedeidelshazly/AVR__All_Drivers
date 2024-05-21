/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : HAL               ***************/
/*********     SWC    : LCD               ***************/
/********************************************************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"


#include "DIO_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"


void LCD_voidInit ()
{
	/*   Set LCD Pins to Output "Controle pins only    */
	DIO_u8SetPinDirection(LCD_CONTROL_PORT,LCD_RS,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT,LCD_RW,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT,LCD_EN,DIO_OUTPUT_MODE);

#if (LCD_MODE == LCD_MODE_8_BIT)
	DIO_u8SetPortDirection(LCD_DATA_PORT,0xff);
	LCD_voidSendCommend(LCD_TWO_LINES_EIGHT_BITS_MODE);
#endif

#if (LCD_MODE == LCD_MODE_4_BIT)
	/* Enter 4-Bit Mode */
	//Lcd_SendCommand(0x02);
	/* make the four bits of the lcd output mode */
	DIO_u8SetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN4,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN5,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN6,DIO_OUTPUT_MODE);
	DIO_u8SetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN7,DIO_OUTPUT_MODE);

	LCD_voidSendCommend(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_voidSendCommend(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);
	LCD_voidSendCommend(LCD_TWO_LINES_FOUR_BITS_MODE);

#endif

	/* Display Control (D=1: Display ON, C=1: Cursor ON, B=1, Cursor Blinks) (0 0 0 0 1 D C B) */
	LCD_voidSendCommend(LCD_CURSOR_ON);
	/* Display Clear */
	LCD_voidSendCommend(LCD_CLEAR_COMMAND);
}
/*********************************************************************/

/**********************************************************************/
void LCD_voidSendCommend (u8 Copy_u8Commend)
{
	/* clear the value of the register select */
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_PIN_LOW);
	/* Clear the value of the register Write  */
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_PIN_LOW);
#if (LCD_MODE == LCD_MODE_8_BIT)
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Commend);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_LOW);
#elif (LCD_MODE == LCD_MODE_4_BIT)
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4, GET_BIT(Copy_u8Commend, 4));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN5, GET_BIT(Copy_u8Commend, 5));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN6, GET_BIT(Copy_u8Commend, 6));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN7, GET_BIT(Copy_u8Commend, 7));
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_LOW);
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4, GET_BIT(Copy_u8Commend, 0));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN5, GET_BIT(Copy_u8Commend, 1));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN6, GET_BIT(Copy_u8Commend, 2));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN7, GET_BIT(Copy_u8Commend, 3));
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_LOW);
#else
#error "[LCD]: Invalid LCD Mode, Options: LCD_MODE_4_BIT, LCD_MODE_8_BIT"
#endif
}
/**************************************************************************/

/**************************************************************************/
void LCD_voidSendData (u8 Copy_u8Data)
{
	/* clear the value of the register select */
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_PIN_HIGH);
	/* Clear the value of the register Write  */
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_PIN_LOW);
#if (LCD_MODE == LCD_MODE_8_BIT)
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Data);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_LOW);
	_delay_ms(2);
#elif (LCD_MODE == LCD_MODE_4_BIT)
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4, GET_BIT(Copy_u8Data, 4));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN5, GET_BIT(Copy_u8Data, 5));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN6, GET_BIT(Copy_u8Data, 6));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN7, GET_BIT(Copy_u8Data, 7));
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_LOW);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4, GET_BIT(Copy_u8Data, 0));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN5, GET_BIT(Copy_u8Data, 1));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN6, GET_BIT(Copy_u8Data, 2));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN7, GET_BIT(Copy_u8Data, 3));
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN, DIO_PIN_LOW);
	_delay_ms(2);
#else
#error "[LCD]: Invalid LCD Mode, Options: LCD_MODE_4_BIT, LCD_MODE_8_BIT"
#endif
}
/************************************************************************/

/************************************************************************/
void LCD_voidDispalyNumber  (s32 Copy_u8Number )
{
	u8 Local_u8DigitsCounter=0 ;
	u32 Resvered=0 ;

	if (Copy_u8Number<0)
	{
		LCD_voidSendData('-');
		Copy_u8Number *= -1;
	}

	do
	{
		Local_u8DigitsCounter++;
		Resvered = (Resvered * 10) + (Copy_u8Number%10);
		Copy_u8Number /=10;

	}while (Copy_u8Number != 0);

	while (Local_u8DigitsCounter > 0)
	{
		LCD_voidSendData (Resvered %10 + '0');
		Resvered /=10;
		Local_u8DigitsCounter --;
	}
}

/**********************************************************************/

void LCD_voidGotoXandY (u8 Copy_u8Xpos , u8 Copy_u8Ypos)  
{                                                         
	u32 Local_u32Address =0 ;
	Local_u32Address = Copy_u8Ypos + (0x40*Copy_u8Xpos);
	/*  this for data sheet Set DDRAM Address  */
	LCD_voidSendCommend(Local_u32Address + 128);

}

/********************** Print String in LCD *************************/
void LCD_voidDisplayString  (u8* Copy_ptrString)
{

	while(*Copy_ptrString !='\0')
	{
		LCD_voidSendData(*Copy_ptrString);
		Copy_ptrString++;
	}
}
/*****************************************************************/

/********************** Print String in LCD *************************/
void LCD_voidDisplayString2 (u8* Copy_ptrString)
{
	u8 Local_u8Counter=0;
	while(Copy_ptrString[Local_u8Counter] !='\0')
	{
		LCD_voidSendData(Copy_ptrString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
/*****************************************************************/

/************************************Write special character ****************************************/

void LCD_voidWriteSpecialCharacter(u8* Copy_PtrARR , u8 Block_Number , u8 Copy_u8Xpos, u8 Copy_u8Xpos)
{
	u8 Local_u8CGRamAddress=0,Local_u8Iterator;

	/***Calculate CG Ram Address Whose each block consist of 8 bytes**/
	Local_u8CGRamAddress = Block_Number*8;

	/**Send Commend for Active CG RAM To LCD with bit 6 is Setting and Clearing Bit 7*/
	Lcd_SendCommand(Local_u8CGRamAddress+64);

	/**Write the pattern in CGRAM*/
	for (Local_u8Iterator =0 ;Local_u8Iterator<8 ;Local_u8Iterator++)
	{
		LCD_voidSendData( Copy_PtrARR[Local_u8Iterator]);
	}

	/**Return back to DDRAM to display the pattern*/
	LCD_voidGotoXandY(Copy_u8Xpos,Copy_u8Ypos);
	
	/**Display the pattern written in CGRAM*/
	LCD_voidSendData(Block_Number);
}

/****************************************************************************************************/