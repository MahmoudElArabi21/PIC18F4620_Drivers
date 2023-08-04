#include "relay.h"

Std_ReturnType relay_initialize(const relay_t *my_relay){
    Std_ReturnType ret = E_OK;
    if(NULL == my_relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t rel_pin = {my_relay->relay_port, my_relay->relay_pin, 0, my_relay->relay_status};
        ret = gpio_pin_initialize(&rel_pin);
    }
    return ret;
}
Std_ReturnType relay_turn_on(const relay_t *my_relay){
    Std_ReturnType ret = E_OK;
    if(NULL == my_relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t rel_pin = {my_relay->relay_port, my_relay->relay_pin, 0, 1};
        ret = gpio_pin_logic_write(&rel_pin, gpio_high);
    }
    return ret;
}
Std_ReturnType relay_turn_off(const relay_t *my_relay){
    Std_ReturnType ret = E_OK;
    if(NULL == my_relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t rel_pin = {my_relay->relay_port, my_relay->relay_pin, 0, 0};
        ret = gpio_pin_logic_write(&rel_pin, gpio_low);
    }
    return ret;
}
