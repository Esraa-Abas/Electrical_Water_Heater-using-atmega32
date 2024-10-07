/*
 * SSD_prog.c
 *
 *  Created on: Sep 24, 2023
 *      Author: esraa
 */
#include <util/delay.h>
#include"SSD_int.h"


void SSD_voidDispaly(char copy_value)
{

	DDRB=0x0F;
	DDRA|=(1<<4)|(1<<5);

	PORTA=0b00010111;//(1<<4);
	PORTB=(PORTB & 0xF0)| ((copy_value/10) & 0x0F);

	_delay_ms(3);

	PORTA=0b00100111;//(1<<5);
	PORTB=(PORTB & 0xF0)| ((copy_value%10) & 0x0F);// to display sec0 on first segment
	_delay_ms(3);

//	DDRB|=0x0f;
//	DDRD|=0x30;
//
//	PORTD|=(1<<B);//disable cathode
//	PORTD&=~(1<<A);
//	//PORTB|=(copy_value/10);
//	PORTB=(PORTB & 0xF0)| ((copy_value%10)& 0x0F);
//	_delay_ms(3);
//
//	PORTD|=(1<<A);//disable cathode
//	PORTD&=~(1<<B);
//	//PORTB|=(copy_value%10);
//	PORTB=(PORTB & 0xF0)| ((copy_value/10)& 0x0F);
//	_delay_ms(3);
}

void SSD_voidDispalyBlink(char copy_value)
{
	DDRB=0x0F;
	DDRA|=(1<<4)|(1<<5);

	PORTA=0b00010111;
	PORTB=(PORTB & 0xF0)| ((copy_value/10) & 0x0F);

	_delay_ms(3);

	PORTA=0b00100111;
	PORTB=(PORTB & 0xF0)| ((copy_value%10) & 0x0F);// to display sec0 on first segment
	_delay_ms(3);

	PORTA=0b11000111;
	_delay_ms(200);
}

void Display_Off()
{
	PORTA=0b11000111;
}
