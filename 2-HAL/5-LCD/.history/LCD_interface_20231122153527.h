/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : HAL               ***************/
/*********     SWC    : LCD               ***************/
/********************************************************/
/********************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define LCD_MODE_8_BIT  0
#define LCD_MODE_4_BIT  1
#define LCD_MODE  LCD_MODE_4_BIT



/*  Commmends which i will need in the driver  */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33  // 0b0011 0011
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32  // 0b0011 0010
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80


void LCD_voidInit ();
void LCD_voidSendCommend    (u8 Copy_u8Commend);
void LCD_voidSendData       (u8 Copy_u8Data   );
void LCD_voidDispalyNumber  (s32 Copy_u8Number );
void LCD_voidGotoXandY      (u8 Copy_u8Xpos , u8 Copy_u8Ypos);
void LCD_voidDisplayString  ( u8* Copy_ptrString);





#endif 
