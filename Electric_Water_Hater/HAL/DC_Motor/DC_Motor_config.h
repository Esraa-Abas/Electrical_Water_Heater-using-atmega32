/*
 * DC_Motor_config.h
 *
 *  Created on: Sep 21, 2023
 *      Author: esraa
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_CONFIG_H_
#define HAL_DC_MOTOR_DC_MOTOR_CONFIG_H_

#define HEATER_IN1_PORT  DIO_u8PORTC
#define HEATER_IN2_PORT  DIO_u8PORTC
#define HEATER_EN_PORT   DIO_u8PORTC

#define HEATER_IN1_PIN	 DIO_PIN4
#define HEATER_IN2_PIN   DIO_PIN5
#define HEATER_EN_PIN 	 DIO_PIN6

#define COOLER_IN1_PORT  DIO_u8PORTD
#define COOLER_IN2_PORT  DIO_u8PORTD
#define COOLER_EN_PORT   DIO_u8PORTD

#define COOLER_IN1_PIN	 DIO_PIN0
#define COOLER_IN2_PIN   DIO_PIN1
#define COOLER_EN_PIN    DIO_PIN2

#endif /* HAL_DC_MOTOR_DC_MOTOR_CONFIG_H_ */
