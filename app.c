/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"

dcmotor_t dcmotor1 = {  .dcmotorpins[0].port = port_D,
                        .dcmotorpins[0].pin = pin_0,
                        .dcmotorpins[0].direction= 0,
                        .dcmotorpins[0].logic = 0,
                        .dcmotorpins[1].port = port_D,
                        .dcmotorpins[1].pin = pin_1,
                        .dcmotorpins[1].direction= 0,
                        .dcmotorpins[1].logic = 0};
dcmotor_t dcmotor2 = {  .dcmotorpins[0].port = port_D,
                        .dcmotorpins[0].pin = pin_2,
                        .dcmotorpins[0].direction= 0,
                        .dcmotorpins[0].logic = 0,
                        .dcmotorpins[1].port = port_D,
                        .dcmotorpins[1].pin = pin_3,
                        .dcmotorpins[1].direction= 0,
                        .dcmotorpins[1].logic = 0};
button_t btn_high = {
    .button_pin.port = port_B,
    .button_pin.pin = pin_0,
    .button_pin.direction = gpio_input,
    .button_pin.logic = gpio_low,
    .button_activate = btn_active_high,
    .button_state = btn_released
};

button_t btn_low = {
    .button_pin.port = port_B,
    .button_pin.pin = pin_1,
    .button_pin.direction = gpio_input,
    .button_pin.logic = gpio_high,
    .button_activate = btn_active_low,
    .button_state = btn_released
};


int main() {
    dc_motor_initialize(&dcmotor1);
    dc_motor_initialize(&dcmotor2);
    
    while(1){
        dc_motor_move_left(&dcmotor1);
        dc_motor_move_left(&dcmotor2);
        __delay_ms(2000);
        dc_motor_move_right(&dcmotor1);
        dc_motor_stop(&dcmotor2);
        __delay_ms(2000);
        dc_motor_move_right(&dcmotor2);
        dc_motor_stop(&dcmotor1);
        __delay_ms(2000);
    }
}

