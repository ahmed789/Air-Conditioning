/* 
 * File:   ecu_led.h
 * Author: ahmed
 *
 * Created on October 16, 2023, 2:37 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*Section : Includes */
#include "./../../MCAL_Layer/GPIO/hal_gpio.h" 
#include "ecu_led_cfg.h"
#include"../../MCAL_Layer/CCP/hal_ccp.h"

/*Section Macro Declarations*/

/*Section Macro Functions Declarations */
 
/*Section :Data Types Declarations */
typedef enum {
    LED_OFF,
    LED_ON
}led_status_t ;

typedef struct {
    uint8 port_name :4;
    uint8 pin:3;
    uint8 led_status :1;
}led_t;
/*Section Functions Declarations  */
std_ReturnType led_initialize (const led_t *led);
std_ReturnType led_turn_on (const led_t *led);
std_ReturnType led_turn_off (const led_t *led);
std_ReturnType led_turn_toggle (const led_t *led);

#endif	/* ECU_LED_H */

