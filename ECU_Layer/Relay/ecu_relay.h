/* 
 * File:   ecu_relay.h
 * Author: ahmed
 *
 * Created on November 9, 2023, 4:12 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/*Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include"ecu_relay_cfg.h"

/*Section Macro Declarations*/
#define REALY_ON_STATUS  0x01U
#define REALY_OFF_STATUS 0x00U
/*Section Macro Functions Declarations */
 
/*Section :Data Types Declarations */
 typedef struct{
    uint8 relay_port : 4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}relay_t;
/*Section Functions Declarations  */
std_ReturnType relay_initialize(const relay_t *_relay);
std_ReturnType relay_turn_on(const relay_t *_relay);
std_ReturnType relay_turn_off(const relay_t *_relay);

#endif	/* ECU_RELAY_H */

