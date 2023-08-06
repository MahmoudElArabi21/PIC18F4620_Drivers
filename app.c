/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"
keypad_t keypad = {
    .keypad_row_pins[0].port = port_C,
    .keypad_row_pins[0].pin = pin_0,
    .keypad_row_pins[0].direction = gpio_output,
    .keypad_row_pins[0].logic = gpio_low,
    .keypad_row_pins[1].port = port_C,
    .keypad_row_pins[1].pin = pin_1,
    .keypad_row_pins[1].direction = gpio_output,
    .keypad_row_pins[1].logic = gpio_low,
    .keypad_row_pins[2].port = port_C,
    .keypad_row_pins[2].pin = pin_2,
    .keypad_row_pins[2].direction = gpio_output,
    .keypad_row_pins[2].logic = gpio_low,
    .keypad_row_pins[3].port = port_C,
    .keypad_row_pins[3].pin = pin_3,
    .keypad_row_pins[3].direction = gpio_output,
    .keypad_row_pins[3].logic = gpio_low,
    .keypad_columns_pins[0].port = port_C,
    .keypad_columns_pins[0].pin = pin_4,
    .keypad_columns_pins[0].direction = gpio_input,
    .keypad_columns_pins[0].logic = gpio_low,
    .keypad_columns_pins[1].port = port_C,
    .keypad_columns_pins[1].pin = pin_5,
    .keypad_columns_pins[1].direction = gpio_input,
    .keypad_columns_pins[1].logic = gpio_low,
    .keypad_columns_pins[2].port = port_C,
    .keypad_columns_pins[2].pin = pin_6,
    .keypad_columns_pins[2].direction = gpio_input,
    .keypad_columns_pins[2].logic = gpio_low,
    .keypad_columns_pins[3].port = port_C,
    .keypad_columns_pins[3].pin = pin_7,
    .keypad_columns_pins[3].direction = gpio_input,
    .keypad_columns_pins[3].logic = gpio_low,
};

led_t led1 = {port_A,pin_0, 0};
led_t led2 = {port_A,pin_1, 0};
int main() {
    Std_ReturnType ret = E_OK;
    ret = keypad_initialize(&keypad);
    ret = led_init(&led1);

    uint8 retval = 0;
    while(1){
        ret = keypad_get_value(&keypad, &retval);
        if(retval == '7'){
            led_turn_on(&led1);
        }
        if(retval == '8'){
            led_turn_off(&led1);
        }
        else{
            
        }
    }
}
