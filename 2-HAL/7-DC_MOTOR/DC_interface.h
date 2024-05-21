/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : HAL               ***************/
/*********     SWC    : DC_MOTOR          ***************/
/********************************************************/
/********************************************************/


#ifndef DC_INTERFACE_H_
#define DC_INTERFACE_H_



typedef enum
{
    DC_CW,
    DC_ACW,
    DC_STOP,
}DC_StateType;

typedef struct 

{
   u8 DC_PORT;
   u8 DC_PINA;
   u8 DC_PINB;
}DC_Configuration;
u8  DC_voidControl(DC_Configuration* config ,DC_StateType State );














#endif