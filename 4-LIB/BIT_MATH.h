/********************************************************/
/********************************************************/
/*********     Author : Ahmed el.shazly   ***************/
/*********     Layer  : LIB               ***************/
/*********     Name   : BIT_MATH               **********/
/********************************************************/
/********************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Var,BIT_NO)  Var|=(1<<BIT_NO)
#define CLR_BIT(Var,BIT_NO)  Var&=(~(1<<BIT_NO))
#define TOG_BIT(Var,BIT_NO)  Var^=((1<<BIT_NO))
#define GET_BIT(Var,BIT_NO)  0x01&((Var>>BIT_NO))


#endif
