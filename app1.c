/* 
 * File:   app1.c
 * Author: ahmed
 *
 * Created on October 16, 2023, 1:07 AM
 */


#include "app1.h"
void Air_Conditioning_On(void);

uint16 lm35_res_1, lm35_res_1_Celsius_mv  ;
uint8 lm35_res_1_txt[7];

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();

        Air_Conditioning_On();
    while(1){
        
        ret = ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN0, &lm35_res_1);
        lm35_res_1_Celsius_mv = lm35_res_1 * 4.88f; /* 5000(mv) / 1024(10-Bit) => 4.88 */
        lm35_res_1_Celsius_mv /= 10; /* The sensitivity of LM35 is 10 mV/degree Celsius */
        ret = convert_uint16_to_string(lm35_res_1_Celsius_mv, lm35_res_1_txt);
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Temp: ");
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 7, lm35_res_1_txt);
        if(lm35_res_1_Celsius_mv > 20){
            //ret = lcd_4bit_send_command(&lcd_1,_LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1,2,2,"It's hot now");
            ret = dc_motor_move_right(&dc_motor_1);
            //ret = lcd_4bit_send_string_pos(&lcd_1,2,2,"                ");
            
        }
        else if(lm35_res_1_Celsius_mv < 20){
            ret = lcd_4bit_send_string_pos(&lcd_1,2,2,"Getting cooler");
            ret = dc_motor_stop(&dc_motor_1);
            ret = lcd_4bit_send_string_pos(&lcd_1,3,2,"                ");
        }
        if(lm35_res_1_Celsius_mv > 25){
            ret = lcd_4bit_send_string_pos(&lcd_1,2,2,"Getting hotter ");
            ret = lcd_4bit_send_string_pos(&lcd_1,3,2,"Cooler boost on");
            __delay_ms(500);
            ret = dc_motor_move_right(&dc_motor_2);
            ret = led_turn_on(&led1);
        }
        else{
            ret = dc_motor_stop(&dc_motor_2);
            ret = led_turn_off(&led1);
        }
           }
          return (EXIT_SUCCESS);
}

void application_intialize(void){
    std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
    

}
void Air_Conditioning_On(void){
    std_ReturnType ret = E_NOT_OK;
    ret = lcd_4bit_send_command(&lcd_1,_LCD_CLEAR);
    ret = lcd_4bit_send_string_pos(&lcd_1,1,5,"Air Conditioning On");
    __delay_ms(3000);
    ret = lcd_4bit_send_command(&lcd_1,_LCD_CLEAR);
    
}