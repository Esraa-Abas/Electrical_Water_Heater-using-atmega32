/*
 * TWI_int.h
 *
 *  Created on: Feb 9, 2023
 *      Author: esraa
 */

#ifndef TWI_INT_H_
#define TWI_INT_H_

#include"../../LIB/errorstate.h"
#include"../../LIB/stdtypes.h"

#define TWI_NACK  0
#define TWI_ACK   1

typedef enum{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteWithACKError,
	MasterReadByteWithACKError,
	SlaveWriteByteWithACKError
}TWI_Errorstatus_t;


ES_t TWI_enuInit(u8 copy_u8Address);//
//ES_t TWI_enuStartCondition(void);
void TWI_ErrorStatusSendRepeatedStartConditionWithACK(void);//
void TWI_enuRecieveData(u8 *copy_u8Data,u8 copy_u8ACK);//
//ES_t TWI_enuSendData(u8 copy_u8Data);
void TWI_enuRecieveData(u8 *copy_u8Data,u8 copy_u8ACK);
void TWI_enuSendStartConditionWithACK(void);//
void TWI_ErrorStatusSendRepeatedStartConditionWithACK(void);
void TWI_enuSendSLA(u8 copy_u8Address,u8 copy_u8RW);//
void TWI_enuWriteData(u8 copy_u8Data);//
ES_t TWI_enuStopCondition(void);//
//ES_t TWI_enuGetStatues(u8 *copy_u8Statues);
//ES_t TWI_enuSetBitRate(u8 copy_u8Rate);
//ES_t TWI_enuSetOwnAddress(u8 copy_u8Address);
ES_t TWI_enuCheckAddress(void); //only for slave, to listen it is address on the bus

#endif /* TWI_INT_H_ */
