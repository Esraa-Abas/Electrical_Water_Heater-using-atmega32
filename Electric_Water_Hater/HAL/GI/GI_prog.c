/*
 * GI_prog.c
 *
 *  Created on: Jun 23, 2023
 *      Author: esraa
 */

#include"GI_int.h"

void GI_Enable()
{
	SREG|=(1<<7);
}
void GI_Disable()
{
	SREG&=~(1<<7);
}
