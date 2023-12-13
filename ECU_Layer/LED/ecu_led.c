/* 
 * File:   ecu_led.c
 * Author: ahmed
 *
 * Created on October 16, 2023, 2:37 PM
 */
#include"ecu_led.h"
/**
 * @brief Initialize the assigned pin to be OUTPUT and turn the led OFF or ON.
 * @param led : pointer to the led module configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
std_ReturnType led_initialize (const led_t *led){
    std_ReturnType ret = E_OK;
    
    if (NULL == led ){
          ret = E_NOT_OK ;
    }
    else {
        pin_config_t pin_obj = {.port= led->port_name, .pin =led->pin,
                                .direction=GPIO_DIRECTION_OUTPUT, .logic = led->led_status} ;
        gpio_pin_direction_initialize(&pin_obj);
    }
    
 return ret ;
}
/**
 * @brief Turn the led on
 * @param led : pointer to the led module configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
std_ReturnType led_turn_on (const led_t *led){
std_ReturnType ret = E_OK;
 if (NULL == led ){
        ret = E_NOT_OK ;
    }
    else {
          pin_config_t pin_obj = {.port= led->port_name, .pin =led->pin,
                                .direction=GPIO_DIRECTION_OUTPUT, .logic = led->led_status};
          gpio_pin_write_logic(&pin_obj,HIGH);
    }
    
 return ret ;
}

/**
 * @brief Turn the led off
 * @param led : pointer to the led module configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
std_ReturnType led_turn_off (const led_t *led){
std_ReturnType ret = E_OK;
 if (NULL == led ){
        ret = E_NOT_OK ;
    }
    else {
            pin_config_t pin_obj = {.port= led->port_name, .pin =led->pin,
                                    .direction=GPIO_DIRECTION_OUTPUT, .logic = led->led_status};
          gpio_pin_write_logic(&pin_obj,LOW);
    }
    
 return ret ;
}

/**
 * @brief Toggle the led
 * @param led : pointer to the led module configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
std_ReturnType led_turn_toggle (const led_t *led){
std_ReturnType ret = E_OK;
 if (NULL == led ){
        ret = E_NOT_OK ;
    }
    else {
            pin_config_t pin_obj = {.port= led->port_name, .pin =led->pin,
                                    .direction=GPIO_DIRECTION_OUTPUT, .logic = led->led_status};
          gpio_pin_toggle_logic(&pin_obj);
    }
    
 return ret ;
}