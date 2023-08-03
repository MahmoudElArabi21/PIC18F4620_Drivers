/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"



led_t led0portd = {port_A, 0, 1};


int main() {
    led_init(&led0portd);
    __delay_ms(200);
    led_turn_off(&led0portd);
    __delay_ms(200);
    led_init(&led0portd);
    __delay_ms(200);
    led_turn_off(&led0portd);
    __delay_ms(200);
    led_init(&led0portd);
    __delay_ms(200);
    led_turn_off(&led0portd);
    __delay_ms(200);
        led_turn_on(&led0portd);
    while(1){
        __delay_ms(500);
        led_toggle(&led0portd);
    }
}
