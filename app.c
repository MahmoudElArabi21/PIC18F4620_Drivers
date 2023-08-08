/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"

led_t led1 = {port_C,pin_0, 0};
led_t led2 = {port_C,pin_1, 0};
led_t led3 = {port_C,pin_2, 0};

void Int0_APP_ISR(void){
    led_toggle(&led1);
}
void Int1_APP_ISR(void){
    led_toggle(&led2);
}
void Int2_APP_ISR(void){
    led_toggle(&led3);
}

interrupt_INTx_t int0_obj = {
  .EXT_InterruptHandler =  Int0_APP_ISR,
  .edge = INTERRUPT_RISING_EDGE,
  .priority = 1,
  .source = INTERRUPT_EXTERNAL_INT0,
  .mcu_pin.port = port_B,
  .mcu_pin.pin = pin_0,
  .mcu_pin.direction = 1
};

interrupt_INTx_t int1_obj = {
  .EXT_InterruptHandler =  Int1_APP_ISR,
  .edge = INTERRUPT_FALLING_EDGE,
  .priority = 1,
  .source = INTERRUPT_EXTERNAL_INT1,
  .mcu_pin.port = port_B,
  .mcu_pin.pin = pin_1,
  .mcu_pin.direction = 1
};

interrupt_INTx_t int2_obj = {
  .EXT_InterruptHandler =  Int2_APP_ISR,
  .edge = INTERRUPT_RISING_EDGE,
  .priority = 1,
  .source = INTERRUPT_EXTERNAL_INT2,
  .mcu_pin.port = port_B,
  .mcu_pin.pin = pin_2,
  .mcu_pin.direction = 1
};
int main() {
    Interrupt_INTx_Init(&int0_obj);
    Interrupt_INTx_Init(&int1_obj);
    Interrupt_INTx_Init(&int2_obj);
    led_init(&led1);
    led_init(&led2);
    led_init(&led3);
    while(1){
        
    }
}
