/*
 * GI_int.h
 *
 *  Created on: Jun 23, 2023
 *      Author: esraa
 */

#ifndef GI_INT_H_
#define GI_INT_H_

#define SREG *((volatile char *) 0x5F)

void GI_Enable();
void GI_Disable();

#endif /* GI_INT_H_ */
