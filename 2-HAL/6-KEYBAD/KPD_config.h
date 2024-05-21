/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : HAL               ***************/
/*********     SWC    : KPD               ***************/
/********************************************************/
/********************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/**********Keypad port in the microcontroller **********************/
#define KPD_PORT    DIO_PORTC


/***********Colums pins in the microcontroller ******************/
#define KPD_COLUM0  DIO_PIN4
#define KPD_COLUM1  DIO_PIN5
#define KPD_COLUM2  DIO_PIN6
#define KPD_COLUM3  DIO_PIN7

/***********Rows pins in the microcontroller ******************/
#define KPD_ROW0  DIO_PIN0
#define KPD_ROW1  DIO_PIN1
#define KPD_ROW2  DIO_PIN2
#define KPD_ROW3  DIO_PIN3

/****************************************************************/
#define KPD_NO_PRESSED_KEY 0xff

/***********Keypad array elments in the microcontroller ********/

#define KPD_ARRAY {{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'+'},{'C',0,'=','-'}}






#endif 
