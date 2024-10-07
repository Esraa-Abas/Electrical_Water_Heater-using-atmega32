/*
 * TWI_priv.h
 *
 *  Created on: Feb 9, 2023
 *      Author: esraa
 */

#ifndef TWI_PRIV_H_
#define TWI_PRIV_H_

#define F_CPU  1000000UL

#define TWDR   *((u8 *)0x23)
#define TWAR   *((u8 *)0x22)
#define TWSR   *((u8 *)0x21)
#define TWBR   *((u8 *)0x20)
#define TWCR   *((u8 *)0x56)

/******************************************************************************
* !comment : TWI Control Register (TWCR) PINS Definition.       	          *
******************************************************************************/

#define TWIE      (u8)0
#define TWEN      (u8)2
#define TWWC      (u8)3
#define TWSTO     (u8)4
#define TWSTA     (u8)5
#define TWEA      (u8)6
#define TWINT     (u8)7

/******************************************************************************
* !comment : TWI Status Register (TWSR) PINS Definition.       	              *
******************************************************************************/

#define TWPS0     (u8)0
#define TWPS1     (u8)1

/******************************************************************************
* !comment : TWI (Slave) Address Register (TWAR) PINS Definition.             *
******************************************************************************/

#define TWGCE     (u8)0
#define TWA1      (u8)1

/******************************************************************************
* !comment : TWI Data Register(TWDR) PINS Definition.       	              *
******************************************************************************/

#define START_ACK                0x08 //start has been sent
#define REP_START_ACK            0x10 //repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 //Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 //Master transmit ( slave address + Read request ) ACK
#define MSTR_WR_BYTE_ACK         0x28 //Master transmit data ACK
#define MSTR_RD_BYTE_WITH_ACK    0x50 //Master received data with ACK
#define MSTR_RD_BYTE_WITH_NACK   0x58 //Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 //means that slave address is received with read request
#define SLAVE_ADD_RCVD_WR_REQ    0x60 //means that slave address is received with write request
#define SLAVE_DATA_RECEIVED      0x80 //means that a byte is received
#define SLAVE_BYTE_TRANSMITTED   0xB8 //means that the written byte is transmitted



#define IIC_MASTER   0
#define IIC_SLAVE    1



#define BITRATE(IIC_SPEED,TWI_PRES)     ((F_CPU-16ul*IIC_SPEED)/(2ul*IIC_SPEED*TWI_PRES))

#define TWI_PRES01   1ul
#define TWI_PRES04   4ul
#define TWI_PRES16   16ul
#define TWI_PRES64   64ul

#define TWI_NEGLECT_CALL    0
#define TWI_RECOGNIZE_CALL  1

#define LOGICAL_ONE  1
#define LOGICLA_ZERO 0

#define TWI_NACK  0
#define TWI_ACK   1

#define STATUS_BIT_MASK		0xF8

#define SCMT_DATA_RECIEIVED_ACK     0x28 //STATUES CODE MASTER TRANS
#define SCST_DATA_RECIEIVED_ACK     0xB8 //STATUES CODE SLAVE TRANS
#endif /* TWI_PRIV_H_ */
