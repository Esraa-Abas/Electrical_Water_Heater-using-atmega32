/*
 * main.c
 *
 *  Created on: Sep 24, 2023
 *      Author: esraa
 */
#include <util/delay.h>

#include"LIB/stdtypes.h"

#include"MCAL/DIO/DIO_Init.h"
#include"MCAL/TIMER/timer_init.h"
#include"MCAL/ADC/ADC_int.h"
#include"MCAL/TWI/TWI_int.h"
#include"HAL/GI/GI_int.h"

#include"HAL/SWITCH/SWITCH_int.h"
#include"HAL/LED/LED_int.h"
#include"HAL/DC_Motor/DC_Motor_int.h"
#include"HAL/EEPROM/E2PROM_Int.h"
#include"HAL/SSD/SSD_int.h"

u8 temp=60;
u8 Setting_mode=0;
u16 current_temp=60;
u8 ON_OFF_MODE=0;

void Timer_voidSetting_mode_disable()
{
	Setting_mode=0;
}

void TIMER_ADC_Read()
{
	ADC_read(&current_temp);
	current_temp*=0.25;
}

int main()
{
	SWITCH_init();
	TWI_enuInit(5);

	LED_init();
	DC_Motor_Init();
	ADC_init();
	TIMER0_enuEnableOVF_Interrupt();
	//TIMER0_voidEnableCTC_Interrupt();

	//Timer0_enuSetCTC_Value(250);


	//if(EEPROM_u8ReadDataByte(40)==0xff)
	//{
		EEPROM_voidSendDataByte(40,60);
	//}

	temp=EEPROM_u8ReadDataByte(40);

	TIMER_voidCall_Back_OVF(Timer_voidSetting_mode_disable);
	//TIMER_voidCall_Back_CTC(TIMER_ADC_Read);

	GI_Enable();

	u8 Local_on_off_read=1;


	while(1)
	{
		ADC_read(&current_temp);
		current_temp*=0.25;
		SWITCH_read(ON_OFF_BUTTON_PORT,ON_OFF_BUTTON_PIN,&Local_on_off_read);
		if(Local_on_off_read==0)
		{
			ON_OFF_MODE++;
		}

		if(ON_OFF_MODE==1)
		{
	        u8 up_button= 1;
	        SWITCH_read(UP_BUTTON_PORT,UP_BUTTON_PIN,&up_button);
	        u8 down_button=1;
	        SWITCH_read(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN,&down_button);
	        if(down_button==0)
	        {
	        	if(temp>35)
	        	{
	        		Timer0_enuInit();
	        		Timer0_enuAsysncDelay(5);
					temp-=5;
					Setting_mode=1;
	        	}
	        }

	        if(up_button==0)
	        {
	        	if(temp<75)
	        	{
	        		Timer0_enuInit();
	        		Timer0_enuAsysncDelay(5);
					temp+=5;
					Setting_mode=1;
	        	}
	        }

	        if(Setting_mode==1)
	        {
	        	SSD_voidDispalyBlink(temp);
	        }
	        else
	        {
	        	SSD_voidDispaly((u8)current_temp);
	        }

	        if(current_temp<temp-5)
	        {
	        	LED_enuON_Blink(LED_PORT,LED_PIN);
	            DC_Motor_ON(CLOCK_WISE,MOTOR_HEATER);
	        }
	        else if(current_temp>temp+5)
	        {
	        	LED_enuOFF(LED_PORT,LED_PIN);
	        	DC_Motor_OFF(MOTOR_HEATER);
	        }

	        if(current_temp>temp+5)
	        {
	        	LED_enuON(LED_PORT,LED_PIN);
	            DC_Motor_ON(CLOCK_WISE,MOTOR_COOLER);
	        }
	        else if(current_temp<temp-5)
	        {
	        	LED_enuOFF(LED_PORT,LED_PIN);
	        	DC_Motor_OFF(MOTOR_COOLER);
	        }

	        EEPROM_voidSendDataByte(40,temp);
		}
		else if(ON_OFF_MODE==2)
		{
			Display_Off();
			LED_enuOFF(LED_PORT,LED_PIN);
			ON_OFF_MODE=0;
		}
	}
}
