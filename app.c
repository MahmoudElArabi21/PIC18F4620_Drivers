/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"

chr_lcd_4bit_t LCD1 = {.lcd_rs.port=port_C ,
                       .lcd_rs.pin=pin_0,
                       .lcd_rs.direction=gpio_output,
                       .lcd_rs.logic=gpio_low,
                       .lcd_en.port=port_C ,
                       .lcd_en.pin=pin_1,
                       .lcd_en.direction=gpio_output,
                       .lcd_en.logic=gpio_low,
                       .lcd_data[0].port=port_C ,
                       .lcd_data[0].pin=pin_2,
                       .lcd_data[0].direction=gpio_output,
                       .lcd_data[0].logic=gpio_low,
                       .lcd_data[1].port=port_C ,
                       .lcd_data[1].pin=pin_3,
                       .lcd_data[1].direction=gpio_output,
                       .lcd_data[1].logic=gpio_low,
                       .lcd_data[2].port=port_C ,
                       .lcd_data[2].pin=pin_4,
                       .lcd_data[2].direction=gpio_output,
                       .lcd_data[2].logic=gpio_low,
                       .lcd_data[3].port=port_C ,
                       .lcd_data[3].pin=pin_5,
                       .lcd_data[3].direction=gpio_output,
                       .lcd_data[3].logic=gpio_low,};

chr_lcd_8bit_t LCD2 = {   .lcd_rs.port=port_C ,
                       .lcd_rs.pin=pin_6,
                       .lcd_rs.direction=gpio_output,
                       .lcd_rs.logic=gpio_low,
                       .lcd_en.port=port_C ,
                       .lcd_en.pin=pin_7,
                       .lcd_en.direction=gpio_output,
                       .lcd_en.logic=gpio_low,
                       .lcd_data[0].port=port_D ,
                       .lcd_data[0].pin=pin_0,
                       .lcd_data[0].direction=gpio_output,
                       .lcd_data[0].logic=gpio_low,
                       .lcd_data[1].port=port_D ,
                       .lcd_data[1].pin=pin_1,
                       .lcd_data[1].direction=gpio_output,
                       .lcd_data[1].logic=gpio_low,
                       .lcd_data[2].port=port_D ,
                       .lcd_data[2].pin=pin_2,
                       .lcd_data[2].direction=gpio_output,
                       .lcd_data[2].logic=gpio_low,
                       .lcd_data[3].port=port_D ,
                       .lcd_data[3].pin=pin_3,
                       .lcd_data[3].direction=gpio_output,
                       .lcd_data[3].logic=gpio_low,
                       .lcd_data[4].port=port_D ,
                       .lcd_data[4].pin=pin_4,
                       .lcd_data[4].direction=gpio_output,
                       .lcd_data[4].logic=gpio_low,
                       .lcd_data[5].port=port_D ,
                       .lcd_data[5].pin=pin_5,
                       .lcd_data[5].direction=gpio_output,
                       .lcd_data[5].logic=gpio_low,
                       .lcd_data[6].port=port_D ,
                       .lcd_data[6].pin=pin_6,
                       .lcd_data[6].direction=gpio_output,
                       .lcd_data[6].logic=gpio_low,
                       .lcd_data[7].port=port_D ,
                       .lcd_data[7].pin=pin_7,
                       .lcd_data[7].direction=gpio_output,
                       .lcd_data[7].logic=gpio_low,};

const uint8 customchar[]={  
  0x01,
  0x03,
  0x07,
  0x1F,
  0x1F,
  0x07,
  0x03,
  0x01
};

int main() {
    lcd_4bit_intialize(&LCD1);
    lcd_8bit_intialize(&LCD2);
    
    while(1){
         lcd_8bit_send_custom_char (&LCD2 , 1 , 20 , customchar , 0);
    }
}

