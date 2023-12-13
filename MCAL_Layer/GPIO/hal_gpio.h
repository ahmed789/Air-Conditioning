/* 
 * File:   hal_gpio.h
 * Author: ahmed
 *
 * Created on October 16, 2023, 2:42 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*Section : Includes */
#include <xc.h>
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "hal_gpio_cfg.h"


/*Section Macro Declarations*/
#define BIT_MASK   (uint8)1
#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER      5 

#define PORTC_MASK           0xFF



/*Section Macro Functions Declarations */
#define HWREG8(_X)      (*((volatile uint8 *)(_X)))
#define SET_BIT(REG,BIT_POSN)       (REG |= (BIT_MASK<<BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)   (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)  (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)    ((REG >> BIT_POSN) & BIT_MASK)

/*#define SET_BIT(REG, BIT_POSN)     (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)   (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)  (REG ^= (BIT_MASK << BIT_POSN))
*/

/*Section :Data Types Declarations */
#define GPIO_LOW      0x00
#define GPIO_HIGH     0x01
typedef enum{
    LOW,
    HIGH
}logic_t;
typedef enum{
    GPIO_DIRECTION_OUTPUT = 0 ,
    GPIO_DIRECTION_INPUT
}direction_t;

 typedef enum{
    PIN0 =0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5=5,
    PIN6,
    PIN7
 }pin_index_t;
 
 typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX ,
    PORTD_INDEX,
    PORTE_INDEX        
}port_index_t;

typedef struct {
    uint8 port :3 ;    /* @ref port_index_t  */
    uint8 pin : 3;
    uint8 direction : 1;
    uint8 logic : 1;
}pin_config_t ;
 
/*Section Functions Declarations  */
std_ReturnType gpio_pin_direction_initialize (const pin_config_t *_pin_config);
std_ReturnType gpio_pin_get_direction_status (const pin_config_t *_pin_config, direction_t *direction_status);
std_ReturnType gpio_pin_write_logic (const pin_config_t *_pin_config, logic_t logic);
std_ReturnType gpio_pin_read_logic (const pin_config_t *_pin_config, logic_t *logic);
std_ReturnType gpio_pin_toggle_logic (const pin_config_t *_pin_config);
std_ReturnType gpio_pin_initialize (const pin_config_t *_pin_config);
               
std_ReturnType gpio_port_direction_initialize (port_index_t port, uint8 direction);
std_ReturnType gpio_get_port_direction_status (port_index_t port, uint8 *direction_status);
std_ReturnType gpio_port_write_logic (port_index_t port, uint8 logic);
std_ReturnType gpio_port_read_logic (port_index_t port, uint8 *logic);
std_ReturnType gpio_port_toggle_logic (port_index_t port);

#endif	/* HAL_GPIO_H */

