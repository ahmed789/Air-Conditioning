/* 
 * File:   gpio.c
 * Author: ahmed
 *
 * Created on October 16, 2023, 1:56 AM
 */
#include "hal_gpio.h"

/* Reference to the Data Direction Control Registers */
volatile uint8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/* Reference to the Data Latch Register (Read and Write to Data Latch) */
volatile uint8 *lat_registers[] = {&LATA,&LATB,&LATC,&LATD,&LATE};
/* Reference to the Port Status Register  */
volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};



/**
 * 
 * @param _pin_config
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_ReturnType gpio_pin_direction_initialize (const pin_config_t *_pin_config){
    std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config->pin >PORT_PIN_MAX_NUMBER-1 ){
        ret = E_NOT_OK ;
    }
    else {
        switch (_pin_config ->direction){
            case GPIO_DIRECTION_OUTPUT :
                CLEAR_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT :
                SET_BIT (*tris_registers[_pin_config->port], _pin_config->pin);
                break;
            default : ret = E_NOT_OK ;
        }
    }
    return ret ;
}
#endif


/**
 * 
 * @param _pin_config
 * @param dic_status
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_ReturnType gpio_pin_get_direction_status (const pin_config_t *_pin_config, direction_t *direction_status){
    std_ReturnType ret = E_OK;
        if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
           ret = E_NOT_OK;
    }
        else{
        
         *direction_status = READ_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
    }
#endif

 /**
  * 
  * @param _pin_config
  * @param logic
  * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
  */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic){
    std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        switch(logic){
            case LOW :
                CLEAR_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;
            case HIGH :
                SET_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config
 * @param logic
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic){
    Std_ReturnType ret = E_OK;
    if((NULL == _pin_config) ||( NULL == logic) ||( _pin_config->pin > PORT_PIN_MAX_NUMBER-1)){
        ret = E_NOT_OK;
    }
    else{
        *logic = READ_BIT(*port_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config 
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_ReturnType gpio_pin_toggle_logic (const pin_config_t *_pin_config){
std_ReturnType ret = E_OK ;
    if (NULL == _pin_config || _pin_config->pin > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else {
        //TOGGLE_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
        TOGGLE_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
    }
return ret;
}
#endif

/**
 * 
 * @param _pin_config
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_ReturnType gpio_pin_initialize (const pin_config_t *_pin_config){
    std_ReturnType ret = E_OK ;
        if (NULL == _pin_config || _pin_config->pin > PORT_MAX_NUMBER-1){
         ret = E_NOT_OK;
    }
        else {
                 gpio_pin_direction_initialize(_pin_config);
                 gpio_pin_write_logic (_pin_config, _pin_config->logic);
        }
    return ret ;
}
#endif


/**
 * 
 * @param port
 * @param direction
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
    std_ReturnType gpio_port_direction_initialize (port_index_t port, uint8 direction ){
        std_ReturnType ret = E_OK ;
        if (port> PORT_MAX_NUMBER-1 ){
            std_ReturnType ret = E_NOT_OK;
        }
        else {
            *tris_registers[port] = direction; 
        }
        return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction_status
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
std_ReturnType gpio_get_port_direction_status (port_index_t port, uint8 *direction_status){
    std_ReturnType ret = E_OK ;
        if ((port> PORT_MAX_NUMBER-1)  && (NULL == direction_status)){
            std_ReturnType ret = E_NOT_OK;
        }
        else {
             //*direction_status = *tris_registers[port];
             *direction_status = *tris_registers[port];
        }
        return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
std_ReturnType gpio_port_write_logic (port_index_t port, uint8 logic){
    std_ReturnType ret = E_OK ;
        if (port> PORT_MAX_NUMBER-1 ){
            std_ReturnType ret = E_NOT_OK;
        }
        else {
            //*lat_registers[port] = logic;
            *lat_registers[port] = logic;
            
        }
        return ret;
}

#endif

/**
 * 
 * @param port
 * @param logic
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
std_ReturnType gpio_port_read_logic (port_index_t port, uint8 *logic){
    std_ReturnType ret = E_OK ;
        if ((port> PORT_MAX_NUMBER-1) && (NULL == logic) ){
            std_ReturnType ret = E_NOT_OK;
        }
        else {
             //*logic = *lat_registers[port];
             *logic = *lat_registers[port];
        }
        return ret;
}

#endif

/**
 * 
 * @param port
 * @return status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
std_ReturnType gpio_port_toggle_logic (port_index_t port){
    std_ReturnType ret = E_OK ;
        if (port> PORT_MAX_NUMBER-1 ){
            std_ReturnType ret = E_NOT_OK;
        }
        else {
             *lat_registers[port] ^= PORTC_MASK;
        }
        return ret;
}

#endif
