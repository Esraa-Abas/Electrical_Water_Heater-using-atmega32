/*
 * LED_int.h
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#include "../../LIB/errorstate.h"
#include"../../LIB/stdtypes.h"

#include"../../MCAL/DIO/DIO_Init.h"

#define LED_PORT		DIO_u8PORTC
#define LED_PIN			DIO_PIN2







ES_t LED_init(void);
ES_t LED_enuON(u8 copy_port,u8 copy_pin);
ES_t LED_enuON_Blink(u8 copy_port,u8 copy_pin);
ES_t LED_enuOFF(u8 copy_port,u8 copy_pin);
ES_t LED_enuTOG(u8 copy_port,u8 copy_pin);


#endif /* LED_INT_H_ */
