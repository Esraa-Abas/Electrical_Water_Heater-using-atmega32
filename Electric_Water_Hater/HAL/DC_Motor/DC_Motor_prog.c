/*
 * DC_Motor_prog.c
 *
 *  Created on: Sep 21, 2023
 *      Author: esraa
 */

#include"../../MCAL/DIO/DIO_Init.h"
#include"../../MCAL/DIO/DIO_priv.h"

#include"DC_Motor_int.h"
#include"DC_Motor_config.h"


void DC_Motor_Init(void)
{
	DIO_enuSetPinDIR(HEATER_EN_PORT,HEATER_EN_PIN,DIO_PIN_OUTPUT);
	DIO_enuSetPinDIR(HEATER_IN2_PORT,HEATER_IN2_PIN,DIO_PIN_OUTPUT);
	DIO_enuSetPinDIR(HEATER_IN1_PORT,HEATER_IN1_PIN,DIO_PIN_OUTPUT);

	DIO_enuSetPinDIR(COOLER_EN_PORT,COOLER_EN_PIN,DIO_PIN_OUTPUT);
	DIO_enuSetPinDIR(COOLER_IN2_PORT,COOLER_IN2_PIN,DIO_PIN_OUTPUT);
	DIO_enuSetPinDIR(COOLER_IN1_PORT,COOLER_IN1_PIN,DIO_PIN_OUTPUT);
}

void DC_Motor_ON(u8 copy_mode,u8 copy_name)
{
	switch(copy_name)
	{
		case MOTOR_COOLER:
			switch(copy_mode)
			{
				case CLOCK_WISE:
					DIO_enuSetPinVAL(COOLER_EN_PORT,COOLER_EN_PIN,DIO_HIGH);
					DIO_enuSetPinVAL(COOLER_IN1_PORT,COOLER_IN1_PIN,DIO_HIGH);
					DIO_enuSetPinVAL(COOLER_IN2_PORT,COOLER_IN2_PIN,DIO_LOW);
					break;

				case ANTI_CLOCK:
					DIO_enuSetPinVAL(COOLER_EN_PORT,COOLER_EN_PIN,DIO_HIGH);
					DIO_enuSetPinVAL(COOLER_IN1_PORT,COOLER_IN1_PIN,DIO_LOW);
					DIO_enuSetPinVAL(COOLER_IN2_PORT,COOLER_IN2_PIN,DIO_HIGH);
					break;
			}
			break;
		case MOTOR_HEATER:
			switch(copy_mode)
			{
				case CLOCK_WISE:
					DIO_enuSetPinVAL(HEATER_EN_PORT,HEATER_EN_PIN,DIO_HIGH);
					DIO_enuSetPinVAL(HEATER_IN1_PORT,HEATER_IN1_PIN,DIO_HIGH);
					DIO_enuSetPinVAL(HEATER_IN2_PORT,HEATER_IN2_PIN,DIO_LOW);
					break;

				case ANTI_CLOCK:
					DIO_enuSetPinVAL(COOLER_EN_PORT,HEATER_EN_PIN,DIO_HIGH);
					DIO_enuSetPinVAL(COOLER_IN1_PORT,HEATER_IN1_PIN,DIO_LOW);
					DIO_enuSetPinVAL(COOLER_IN2_PORT,HEATER_IN2_PIN,DIO_HIGH);
					break;
			}
			break;
	}
}

void DC_Motor_OFF(u8 copy_name)
{
	switch(copy_name)
	{
		case MOTOR_COOLER:
			DIO_enuSetPinVAL(COOLER_EN_PORT,COOLER_EN_PIN,DIO_LOW);
			break;
		case MOTOR_HEATER:
			DIO_enuSetPinVAL(HEATER_EN_PORT,HEATER_EN_PIN,DIO_LOW);
			break;
	}
}
