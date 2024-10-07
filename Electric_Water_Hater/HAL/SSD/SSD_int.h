/*
 * SSD_int.h
 *
 *  Created on: Sep 24, 2023
 *      Author: esraa
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

#define DDRA  		*((char*)0x3A)
#define PORTA		*((char*)0x3B)

#define DDRD		*(char*)0x31
#define PORTD		*(char*)0x32

#define DDRB	    *(char*)0x37
#define PORTB		*(char*)0x38

#define A  4
#define B  5

void SSD_voidDispaly(char copy_value);
void SSD_voidDispalyBlink(char copy_value);
void Display_Off();

#endif /* HAL_SSD_SSD_INT_H_ */
