/*
 * E2PROM_Int.h
 *
 *  Created on: Aug 30, 2023
 *      Author: esraa
 */

#ifndef E2PROM_E2PROM_INT_H_
#define E2PROM_E2PROM_INT_H_

#include"../../LIB/stdtypes.h"
#include"../../LIB/errorstate.h"

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress);

#endif /* E2PROM_E2PROM_INT_H_ */
