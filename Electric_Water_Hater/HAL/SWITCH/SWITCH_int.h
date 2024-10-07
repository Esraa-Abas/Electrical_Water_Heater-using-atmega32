/*
 * SWITCH_int.h
 *
 *  Created on: Feb 12, 2023
 *      Author: esraa
 */

#ifndef HAL_SWITCH_SWITCH_INT_H_
#define HAL_SWITCH_SWITCH_INT_H_

#include"../../LIB/stdtypes.h"
#include"../../LIB/errorstate.h"


#define UP_BUTTON_PORT  DIO_u8PORTA
#define UP_BUTTON_PIN   DIO_PIN0

#define DOWN_BUTTON_PORT  DIO_u8PORTA
#define DOWN_BUTTON_PIN   DIO_PIN1

#define ON_OFF_BUTTON_PORT  DIO_u8PORTA
#define ON_OFF_BUTTON_PIN   DIO_PIN2


ES_t SWITCH_init(void);
ES_t SWITCH_read(u8 copy_SWITCH_port,u8 copy_SWITCH_pin,u8 *value);

#endif /* HAL_SWITCH_SWITCH_INT_H_ */
