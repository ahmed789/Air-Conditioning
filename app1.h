/* 
 * File:   app1.h
 * Author: ahmed
 *
 * Created on October 16, 2023, 2:45 PM
 */

#ifndef APP1_H
#define	APP1_H
/*Section : Includes */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ECU_Layer/ecu_layer_init.h"
#include "builtins.h"

/*Section Macro Declarations*/

/*Section Macro Functions Declarations */
 
/*Section :Data Types Declarations */

extern chr_lcd_4bit_t lcd_1;
extern led_t led1;
extern dc_motor_t dc_motor_1;
extern dc_motor_t dc_motor_2;
extern adc_conf_t adc_1;
extern led_t led1;
/*Section Functions Declarations  */
void application_intialize (void);


#endif	/* APP1_H */

