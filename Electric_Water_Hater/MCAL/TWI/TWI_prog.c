/*
 * TWI_prog.c
 *
 *  Created on: Feb 9, 2023
 *      Author: esraa
 */

#include"../../LIB/errorstate.h"
#include"../../LIB/stdtypes.h"
#include"../../LIB/BIT_MATH.h"

#include"TWI_priv.h"
#include"TWI_config.h"

#define F_CPU  1000000UL

ES_t TWI_enuInit(u8 Copy_u8Address)
{
	#if IIC_MODE ==IIC_MASTER
	//Enable ACKnowlega
	TWCR|=(LOGICAL_ONE<<TWEA);

	//set prescaller bits
	#if TWI_PRES==TWI_PRES01
	TWBR&=~(LOGICAL_ONE<<TWPS0);
	TWBR&=~(LOGICAL_ONE<<TWPS1);

	//only for master, set bit rate using the equation
	TWBR=(u8) BITRATE(TWI_CLOCKSPEED,TWI_PRES01);

	#elif TWI_PRES==TWI_PRES04
	TWBR|=(LOGICAL_ONE<<TWPS0);
	TWBR&=~(LOGICAL_ONE<<TWPS1);
	TWBR=(u8) BITRATE(TWI_CLOCKSPEED,TWI_PRES04);

	#elif TWI_PRES==TWI_PRES16
	TWBR&=~(LOGICAL_ONE<<TWPS0);
	TWBR|=(LOGICAL_ONE<<TWPS0);
	TWBR=(u8) BITRATE(TWI_CLOCKSPEED,TWI_PRES16);

	#elif TWI_PRES==TWI_PRES64
	TWBR|=(LOGICAL_ONE<<TWPS0);
	TWBR|=(LOGICAL_ONE<<TWPS0);
	TWBR=(u8) BITRATE(TWI_CLOCKSPEED,TWI_PRES64);

	#endif

	//general call&own address set
	TWAR&=~(LOGICAL_ONE<<TWGCE);

	#if TWI_GENERAL_CALL==TWI_RECOGNIZE_CALL
	TWAR|=(Copy_u8Address<<TWA1)|TWI_RECOGNIZE_CALL;
	#elif TWI_GENERAL_CALL==TWI_NEGLECT_CALL
	TWAR|=(Copy_u8Address<<TWA1)|TWI_NEGLECT_CALL;
	#endif

	/*Check if the master node will be addressed or not*/
	if(Copy_u8Address == 0)
	{
		/*Do Nothing*/
	}
	else
	{
		/*Set The Required Address to The Master*/ //bits from 1 to 7
		TWAR = (Copy_u8Address << 1);
	}

	//clear flag&enable twi
	TWCR|=(LOGICAL_ONE<<TWINT);

	TWCR|=(LOGICAL_ONE<<TWEN);

	#elif ICC_MODE==IIC_SLAVE

	TWAR&=~(LOGICAL_ONE<<TWGCE);

	#if TWI_GENERAL_CALL==TWI_RECOGNIZE_CALL
	TWAR|=(Copy_u8Address<<TWA1)|TWI_RECOGNIZE_CALL;
	#elif TWI_GENERAL_CALL==TWI_NEGLECT_CALL
	TWAR|=(Copy_u8Address<<TWA1)|TWI_NEGLECT_CALL;
	#endif

	TWCR|=(LOGICAL_ONE<<TWEA);

	TWCR|=(LOGICAL_ONE<<TWINT);

	TWCR|=(LOGICAL_ONE<<TWEN);
	#endif



	   return ES_OK;
}


void TWI_enuSendStartConditionWithACK(void)
{
	//TWI_Errorstatus_t Local_ErrorStatus = NoError;

	TWCR |= (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	//clear flag
	TWCR|=(1<< TWINT);

	while(((TWCR>>TWINT)&LOGICAL_ONE)==LOGICLA_ZERO);

	if((TWSR & STATUS_BIT_MASK) != START_ACK)
	{
		//Local_ErrorStatus = StartConditionError;
	}
	else
	{
		/*Do Nothing*/
	}


		//return Local_ErrorStatus;

}

void TWI_ErrorStatusSendRepeatedStartConditionWithACK(void)
{
	//TWI_Errorstatus_t Local_ErrorStatus = NoError;
	// clear INT flag
	// Send Repeated Start Condition
	// Enable TWI
	TWCR |= (1 << TWINT) | (1 <<TWSTA) | (1 << TWEN);
	/*Send Start Condition Bit*/
	//	SET_BIT(TWCR, TWCR_TWSTA);

	/*Clear The TWINT Flag*/
	//	SET_BIT(TWCR, TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised again*/
	while(GET_BIT(TWCR, TWINT) == 0 );

	/*Check For The Condition Status Code*/
	if((TWSR & STATUS_BIT_MASK) != REP_START_ACK)
	{
		//Local_ErrorStatus = RepeatedStartError;
	}
	else
	{
		/*Do Nothing*/
	}
	//return Local_ErrorStatus;
}


void TWI_enuSendSLA(u8 copy_u8Address,u8 copy_u8RW)
{

	//TWI_Errorstatus_t Local_ErrorStatus = NoError;

	TWDR=(copy_u8Address<<LOGICAL_ONE)|copy_u8RW;

	//TWSTA must be cleared by software when the START condition has been transmitted.
	TWCR&=~(LOGICAL_ONE<<TWSTA);

	TWCR|=(LOGICAL_ONE<<TWINT);

	while(((TWCR>>TWINT)&LOGICAL_ONE)==LOGICLA_ZERO);

	if (copy_u8RW==0)
	{
		if((TWSR & STATUS_BIT_MASK) != SLAVE_ADD_AND_WR_ACK)
		{
			//Local_ErrorStatus = SlaveAddressWithWriteError;
		}
	}

	else if (copy_u8RW==1)
	{
		if((TWSR & STATUS_BIT_MASK) != SLAVE_ADD_AND_WR_ACK)
		{
			//Local_ErrorStatus = SlaveAddressWithReadError;
		}
	}

	//return Local_ErrorStatus;
}


void TWI_enuWriteData(u8 copy_u8Data)
{
	//TWI_Errorstatus_t Local_ErrorStatus = NoError;

	//Load DATA into TWDR Register.
	TWDR=copy_u8Data;

	//Clear TWINT bit in TWCR to start transmission of data
	TWCR|=(LOGICAL_ONE<<TWINT);

	//Wait for TWINT Flag set. This indicates that the DATA has been transmitted
	while(((TWCR>>TWINT)&LOGICAL_ONE)==LOGICLA_ZERO);

	//MAKE SURE THAT DATA TRANSIMITTED USING SC
	#if IIC_MODE ==IIC_MASTER

	//MASK PRE SCALER BITS BEFORE READ SC-> 1111 1000 & TWSR
	if( (TWSR & STATUS_BIT_MASK) != MSTR_WR_BYTE_ACK)
	{
		//Local_ErrorStatus=MasterWriteByteWithACKError;
	}
	#elif ICC_MODE==IIC_SLAVE
	if( (TWSR & TWI_Errorstatus_t) !=SLAVE_BYTE_TRANSMITTED)
	{
		//Local_ErrorStatus=SlaveWriteByteWithACKError;
	}

	#endif

	//return Local_ErrorStatus;
}


///there are options - use if (sc) &if (M/S)&if(Ack/ not ack) then read
//another option in all func is to add a para to return sc in
void TWI_enuRecieveData(u8 *copy_u8Data,u8 copy_u8ACK)
{

	//TWI_Errorstatus_t Local_ErrorStatus = NoError;

	switch(copy_u8ACK)
	{
		case TWI_ACK:
			TWCR|=(LOGICAL_ONE<<TWINT)| (LOGICAL_ONE<<TWEA);
			break;
		case TWI_NACK:
			TWCR|=(LOGICAL_ONE<<TWINT);
			break;
	}

	//WAIT ON FALG UNTIL DATA RECEIVED
	while( ( (TWCR>>TWINT) &LOGICAL_ONE ) == LOGICLA_ZERO);

	if((TWSR & STATUS_BIT_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		//Local_ErrorStatus = MasterReadByteWithACKError;
	}
	else
	{
		/*Read The Received Data*/
		*copy_u8Data = TWDR;
	}

		//return Local_ErrorStatus;
}


ES_t TWI_enuCheckAddress(void)
{
	TWCR|=(LOGICAL_ONE<<TWEA);
	TWCR|=(LOGICAL_ONE<<TWINT);
	while(((TWCR>>TWINT)&LOGICAL_ONE)==LOGICLA_ZERO);
	//CHECK SC OR RETURN IT!
}


ES_t TWI_enuStopCondition(void)
{
	TWCR |= (LOGICAL_ONE<<TWSTO);
	//clear the flag to execute this action
	TWCR |= (LOGICAL_ONE<<TWINT);
}
//ES_t TWI_enuGetStatues(u8 *copy_u8Statues);
//ES_t TWI_enuSetBitRate(u8 copy_u8Rate);
//ES_t TWI_enuSetOwnAddress(u8 copy_u8Address);
