/*
 * SWITCH_prog.c
 *
 *  Created on: Feb 12, 2023
 *      Author: esraa
 */

#include"../../LIB/stdtypes.h"
#include"../../LIB/errorstate.h"

#include"../../MCAL/DIO/DIO_Init.h"

//#include"SWITCH_int.h"
#include"SWITCH_config.h"




ES_t SWITCH_init(void)
{
	DIO_enuSetPinDIR(SWITCH1_PORT,SWITCH1_PIN,DIO_PIN_INPUT);
	DIO_enuSetPinVAL(SWITCH1_PORT,SWITCH1_PIN,DIO_HIGH);

	DIO_enuSetPinDIR(SWITCH2_PORT,SWITCH2_PIN,DIO_PIN_INPUT);
	DIO_enuSetPinVAL(SWITCH2_PORT,SWITCH2_PIN,DIO_HIGH);

	DIO_enuSetPinDIR(SWITCH3_PORT,SWITCH3_PIN,DIO_PIN_INPUT);
	DIO_enuSetPinVAL(SWITCH3_PORT,SWITCH3_PIN,DIO_HIGH);

}


ES_t SWITCH_read(u8 copy_SWITCH_port,u8 copy_SWITCH_pin,u8 *value)
{
	DIO_enuGetPinval(copy_SWITCH_port,copy_SWITCH_pin,value); ///////////////////////////////!!!!!!!
	u8 read;
	DIO_enuGetPinval(copy_SWITCH_port,copy_SWITCH_pin,&read);
	while(read==0)
	{
		DIO_enuGetPinval(copy_SWITCH_port,copy_SWITCH_pin,&read);
	}

}
