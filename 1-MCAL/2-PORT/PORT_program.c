/************************************************************************/
/*******************  Author : Ahmed Elshazly   *************************/
/*******************  layer  : MCAL             *************************/
/*******************  SWC    : PORT             *************************/
/************************************************************************/
/************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_register.h"
#include "PORT_interface.h"

void PORT_voidInti(void)
{
	/**Set Port Direction */
	DDRA=PORTA_dri;
	DDRB=PORTB_dri;
	DDRC=PORTC_dri;
	DDRD=PORTD_dri;
	
	/**Set Port Value */
	PORTA=PORTA_INTI_VALUE;
	PORTB=PORTB_INTI_VALUE;
	PORTC=PORTC_INTI_VALUE;
	PORTD=PORTD_INTI_VALUE;

}
