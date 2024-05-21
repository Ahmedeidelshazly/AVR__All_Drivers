/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : MCAL              ***************/
/*********     SWC    : BIT_MATH               **********/
/********************************************************/
/********************************************************/

#ifndef DIO_Interface_H_
#define DIO_Interface_H_

#define SET_BIT(Var,BIT_NO)  Var|=(1<<BIT_NO)
#define CLR_BIT(Var,BIT_NO)  Var&=(~(1<<BIT_NO))
#define TOG_BIT(Var,BIT_NO)  Var^=((1<<BIT_NO))
#define GET_BIT(Var,BIT_NO)  0x01&((Var>>BIT_NO))


#endif
