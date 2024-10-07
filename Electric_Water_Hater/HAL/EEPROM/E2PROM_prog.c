/*
 * E2PROM_prog.c
 *
 *  Created on: Aug 30, 2023
 *      Author: esraa
 */
#include <util/delay.h>
#define F_CPU	1000000UL

#include"../../LIB/stdtypes.h"
#include"../../LIB/errorstate.h"

#include"../../MCAL/TWI/TWI_int.h"

#include"E2PROM_int.h"
#include"E2PROM_priv.h"
#include"E2PROM_config.h"


void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte)
{
	u8 Local_u8AddressPacket;

		Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (u8)(Copy_u16LocationAddress >>8);

		/*Send start condition*/
		TWI_enuSendStartConditionWithACK();


		/*Send the address packet*/
		TWI_enuSendSLA(Local_u8AddressPacket,0);

		/*Send the rest 8bits of the location address*/
		TWI_enuWriteData((u8)Copy_u16LocationAddress);

		/*Send the data byte to the memory location*/
		TWI_enuWriteData(Copy_u8DataByte);

		/*Send stop condition*/
		TWI_enuStopCondition();

		/*Delay until the write cycle is finished*/
		_delay_ms(10);
}

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress){
	u8 Local_u8AddressPacket, Local_u8Data;

		Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (u8)(Copy_u16LocationAddress >>8);

		/*Send start condition*/
		TWI_enuSendStartConditionWithACK();

		/*Send the address packet with write request*/
		TWI_enuSendSLA(Local_u8AddressPacket,0);

		/*Send the rest 8bits of the location address*/
		TWI_enuWriteData((u8)Copy_u16LocationAddress);

		/*Send repeated start to change write request into read request*/
		TWI_ErrorStatusSendRepeatedStartConditionWithACK();

		/*Send the address packet with read request*/
		TWI_enuSendSLA(Local_u8AddressPacket,1);

		/*Get the data from memory*/
		TWI_enuRecieveData(&Local_u8Data,1);

		/*send the stop condition*/
		TWI_enuStopCondition();

		return Local_u8Data;
}






