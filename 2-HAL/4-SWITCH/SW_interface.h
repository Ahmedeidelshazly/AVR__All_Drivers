/******************************************************/
/******************************************************/
/*********     Author  : Ahmed el.shazly  *************/
/*********     Layer   : HAL               ************/
/*********     SWC     : SWITCH            ************/
/*********     version : 1.1              ************/
/******************************************************/
/******************************************************/

#ifndef _SW_INTERFACE_H_
#define _SW_INTERFACE_H_


#define SW_PRESSED_KEY     1
#define SW_NOT_PRESSED_KEY 0

/*
 ==> Options of State
	 1- SW_Int_PULL_UP
	 2- SW_Ext_PULL_UP
	 3- SW_Ext_PULL_DOWN
	 <==
 */
/***************************************/
#define SW_Int_PULL_UP     0
#define SW_Ext_PULL_UP     1
#define SW_Ext_PULL_DOWN   2
/****************************************/

typedef struct{

	u8 Port;
	u8 Pin ;
	u8 Pull_State;

}SW_Type;

void SW_voidInit       ( SW_Type SW_Config );
u8   SW_u8GetPressed   ( SW_Type SW_Config );

#endif
