/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"


led_t led1 = {port_C, pin_0, gpio_low};
led_t led2 = {port_C, pin_1, gpio_low};

button_t btn_high = {
    .button_pin.port = port_D,
    .button_pin.pin = pin_0,
    .button_pin.direction = gpio_input,
    .button_pin.logic = gpio_low,
    .button_activate = btn_active_high,
    .button_state = btn_released
};

button_t btn_low = {
    .button_pin.port = port_C,
    .button_pin.pin = pin_2,
    .button_pin.direction = gpio_input,
    .button_pin.logic = gpio_high,
    .button_activate = btn_active_low,
    .button_state = btn_released
};
int main() {
    led_init(&led1);
    led_init(&led2);
    button_inittialze(&btn_high);
    button_inittialze(&btn_low);
    btn_press_state_t btn_high_status = btn_released;
    btn_press_state_t btn_low_status  = btn_released;
    while(1){
        button_read_status(&btn_high, &btn_high_status);
        button_read_status(&btn_low, &btn_low_status);
        
        if(btn_pressed == btn_high_status){
            led_turn_on(&led1);
        }
        else{
            led_turn_off(&led1);
        }
        
        if(btn_pressed == btn_low_status){
            led_turn_on(&led2);
        }
        else{
            led_turn_off(&led2);
        }
    }
}

