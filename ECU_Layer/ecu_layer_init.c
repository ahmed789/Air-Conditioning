/* 
 * File:   ecu_layer_init.h
 * Author: ahmed
 *
 * Created on November 18, 2023, 2:02 PM
 */
#include "ecu_layer_init.h"

/*===========================keypad configuration=========================*/


/*============================lcd configuration===========================*/
chr_lcd_4bit_t lcd_1 ={
.lcd_rs.port=PORTB_INDEX,
.lcd_rs.pin=PIN6,
.lcd_rs.direction=GPIO_DIRECTION_OUTPUT,
.lcd_rs.logic=LOW,
.lcd_en.port=PORTB_INDEX,
.lcd_en.pin=PIN7,
.lcd_en.direction=GPIO_DIRECTION_OUTPUT,
.lcd_en.logic=LOW,
.lcd_data[0].port=PORTC_INDEX,
.lcd_data[0].pin=PIN4,
.lcd_data[0].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[0].logic=LOW,
.lcd_data[1].port=PORTC_INDEX,
.lcd_data[1].pin=PIN5,
.lcd_data[1].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[1].logic=LOW,
.lcd_data[2].port=PORTC_INDEX,
.lcd_data[2].pin=PIN6,
.lcd_data[2].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[2].logic=LOW,
.lcd_data[3].port=PORTC_INDEX,
.lcd_data[3].pin=PIN7,
.lcd_data[3].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[3].logic=LOW,
};

/*============================motor configuration===========================*/
dc_motor_t dc_motor_1 = {
    .dc_motor_pin[0].port = PORTC_INDEX,
    .dc_motor_pin[0].pin = PIN0,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].port = PORTC_INDEX,
    .dc_motor_pin[1].pin = PIN1,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};

dc_motor_t dc_motor_2 = {
    .dc_motor_pin[0].port = PORTC_INDEX,
    .dc_motor_pin[0].pin = PIN2,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].port = PORTC_INDEX,
    .dc_motor_pin[1].pin = PIN3,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};
/*============================ leds configuration===========================*/
led_t led1 = {.port_name = PORTD_INDEX, .pin = PIN0, .led_status = GPIO_LOW};

/*============================ ADC configuration===========================*/
adc_conf_t adc_1 = {
    .ADC_InterruptHandler = NULL,
    .acquisition_time = ADC_12_TAD,
    .adc_channel = ADC_CHANNEL_AN0,
    .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .result_format = ADC_RESULT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};


void ecu_layer_intialize(void){
    std_ReturnType ret = E_NOT_OK;
    ret = dc_motor_initialize(&dc_motor_1);
    ret = dc_motor_initialize(&dc_motor_2);
    ret = lcd_4bit_intialize(&lcd_1);
    ret = ADC_Init(&adc_1);
    ret = led_initialize(&led1);
}
