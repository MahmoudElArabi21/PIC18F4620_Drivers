
#include "led.h"

Std_ReturnType led_init(const led_t* my_led){
    Std_ReturnType ret = E_OK;
    pin_config_t my_pin = {my_led->led_port, my_led->led_pin, gpio_output, my_led->led_status};
    if(my_led == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_initialize(&my_pin);
    }
    return ret;
}
Std_ReturnType led_turn_on(const led_t* my_led){
    Std_ReturnType ret = E_OK;
    pin_config_t my_pin = {my_led->led_port, my_led->led_pin, gpio_output, gpio_high};
    if(my_led == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_logic_write(&my_pin, gpio_high);
    }
    return ret;
}
Std_ReturnType led_turn_off(const led_t* my_led){
    Std_ReturnType ret = E_OK;
    pin_config_t my_pin = {my_led->led_port, my_led->led_pin, gpio_output, gpio_low};
    if(my_led == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_logic_write(&my_pin, gpio_low);
    }
    return ret;
}
Std_ReturnType led_toggle(const led_t* my_led){
    Std_ReturnType ret = E_OK;
    pin_config_t my_pin = {my_led->led_port, my_led->led_pin, gpio_output, my_led->led_status};
    if(my_led == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_logic_toggle(&my_pin);
    }
    return ret;
}
