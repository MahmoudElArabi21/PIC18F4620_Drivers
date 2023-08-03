/* 
 * File:   led.h
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 11:47 PM
 */

#ifndef LED_H
#define	LED_H
#include "../../MCAL/GPIO/gpio.h"

typedef enum{
    led_off,
    led_on,
}led_status_t;

typedef struct{
    uint8 led_port :3;
    uint8 led_pin :3;
    uint8 led_status :1;
}led_t;

Std_ReturnType led_init(const led_t* my_led);
Std_ReturnType led_turn_on(const led_t* my_led);
Std_ReturnType led_turn_off(const led_t* my_led);
Std_ReturnType led_toggle(const led_t* my_led);

#endif	/* LED_H */

