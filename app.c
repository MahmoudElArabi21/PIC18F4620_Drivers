/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"

volatile uint16 timer0_counter_value = ZERO_INIT;
volatile uint16 btn_counter = 0;
volatile uint8 pwm_counter = 0;

led_t led1 = {port_D, pin_0,0};

void Timer0_DefaultInterruptHandler(void){
    if(pwm_counter < 3){
        led_turn_off(&led1);
        pwm_counter++;
    }
    else{
        led_turn_on(&led1);
        pwm_counter = 0;
    }
}

timer0_t timer0_timer_obj = {
    .TMR0_InterruptHandler = Timer0_DefaultInterruptHandler,
    .timer0_mode = TIMER0_TIMER_MODE,
    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE,
    .prescaler_enable = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_PRESCALER_DIV_BY_4,
    .timer0_preload_value = 60536
};


//timer0_t timer0_counter_obj = {
//    .TMR0_InterruptHandler = Timer0_DefaultInterruptHandler,
//    .timer0_mode = TIMER0_COUNTER_MODE,
//    .timer0_counter_edge = TIMER0_COUNTER_RISING_EDGE_CFG,
//    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE,
//    .prescaler_enable = TIMER0_PRESCALER_DISABLE_CFG,
//    .timer0_preload_value = 0
//};



int main() { 
    Std_ReturnType ret  = E_NOT_OK;
    ret = Timer0_Init(&timer0_timer_obj);
    ret = led_init(&led1);

    while(1){
    
    }
    return (EXIT_SUCCESS);
}