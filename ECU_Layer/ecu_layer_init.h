/* 
 * File:   ecu_layer_init.h
 * Author: ahmed
 *
 * Created on November 18, 2023, 2:02 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

#include "../MCAL_Layer/GPIO/hal_gpio.h"
#include "LED/ecu_led.h"
#include "7_Segment/ecu_seven_segment.h"
#include "Relay/ecu_relay.h"
#include "DC_Motor/ecu_dc_motor.h"
#include "button/ecu_button.h"
#include "KeyPad/ecu_keypad.h"
#include "Chr_LCD/ecu_chr_lcd.h"
#include "../MCAL_Layer/Interrupt/mcal_external_interrupt.h"
#include "../MCAL_Layer/Timer0/hal_timr0.h"
#include "../MCAL_Layer/Timer1/hal_timr1.h"
#include "../MCAL_Layer/Timer2/hal_timr2.h"
#include "../MCAL_Layer/Timer3/hal_timr3.h"
#include "../MCAL_Layer/CCP/hal_ccp.h"
#include "../MCAL_Layer/usart/hal_usart.h"
#include "../MCAL_Layer/ADC/hal_adc.h"



void ecu_layer_intialize(void);

#endif	/* ECU_LAYER_INIT_H */
