/*
 * DC_Motor_Int.h
 *
 *  Created on: Sep 21, 2023
 *      Author: esraa
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INT_H_
#define HAL_DC_MOTOR_DC_MOTOR_INT_H_

#define MOTOR_HEATER  1
#define MOTOR_COOLER  0

#define CLOCK_WISE  0
#define ANTI_CLOCK  1


void DC_Motor_Init(void);

void DC_Motor_ON(u8 copy_mode,u8 copy_name);

void DC_Motor_OFF(u8 copy_name);

#endif /* HAL_DC_MOTOR_DC_MOTOR_INT_H_ */
