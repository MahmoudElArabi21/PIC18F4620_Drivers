/* 
 * File:   gpio.c
 * Author: Mahmoud El Arabi
 * https://www.linkedin.com/in/mahmoudarabi21/
 * Created on August 3, 2023, 3:20 AM
 */
#include "gpio.h"

volatile uint8 *tris_regs[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *port_regs[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
volatile uint8 *lat_regs[] =  {&LATA, &LATB, &LATC, &LATD, &LATE};

Std_ReturnType gpio_pin_direction_init(const pin_config_t *my_pin){
    Std_ReturnType ret = E_OK;
    if(NULL == my_pin || my_pin->pin > 7){
        ret = E_NOT_OK;
    }
    else{
        switch(my_pin->direction){
            case gpio_output :
                bit_clear(*tris_regs[my_pin->port], my_pin->pin);
                break;
            case gpio_input :
                bit_set(*tris_regs[my_pin->port], my_pin->pin);
                break;
            default : ret = E_NOT_OK; 
        }
    }
    return ret;
}
Std_ReturnType gpio_pin_direction_stat(const pin_config_t *my_pin, direction_t *retdirection){
    Std_ReturnType ret = E_OK;
    if(NULL == my_pin || my_pin->pin > 7 || NULL == retdirection){
        ret = E_NOT_OK;
    }
    else{
        *retdirection = bit_read(*tris_regs[my_pin->port], my_pin->pin);
    }
}

Std_ReturnType gpio_pin_logic_write(const pin_config_t *my_pin, uint8 logic){
    Std_ReturnType ret = E_OK;
    if ((NULL == my_pin) || (my_pin->pin) > 7){
        ret = E_NOT_OK;
    }
    else{
        switch(logic){
            case gpio_low:
                bit_clear(*lat_regs[my_pin->port], my_pin->pin);
                break;
            case gpio_high:
                bit_set(*lat_regs[my_pin->port], my_pin->pin);
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
Std_ReturnType gpio_pin_logic_read(const pin_config_t *my_pin, logic_t *retlogic){
    Std_ReturnType ret = E_OK;
    if(NULL == my_pin || my_pin->pin > 7 || NULL == retlogic){
        ret = E_NOT_OK;
    }
    else{
        *retlogic = bit_read(*port_regs[my_pin->port], my_pin->pin);
    }
    return ret;
}
Std_ReturnType gpio_pin_logic_toggle(const pin_config_t *my_pin){
    Std_ReturnType ret = E_OK;
    if ((NULL == my_pin) || (my_pin->pin) > 7){
        ret = E_NOT_OK;
    }
    else{
        bit_toggle(*lat_regs[my_pin->port], my_pin->pin);
    }
    return ret;
}
Std_ReturnType gpio_pin_initialize(const pin_config_t *my_pin){
    Std_ReturnType ret = E_OK;
    if (NULL == my_pin){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_init(my_pin);
        ret = gpio_pin_logic_write(my_pin, my_pin->logic);
    }
    return ret;
}

Std_ReturnType gpio_port_direction_init(port_index_t my_port, uint8 my_direction){
    Std_ReturnType ret = E_OK;
    if (my_port > 4){
        ret = E_NOT_OK;
    }
    else{
        *tris_regs[my_port] = my_direction;
    }
    return ret;
}
Std_ReturnType gpio_port_direction_stat(port_index_t my_port , uint8 *retdirection){
    Std_ReturnType ret = E_OK;
    if (my_port > 4 || retdirection ==NULL){
        ret = E_NOT_OK;
    }
    else{
        *retdirection = *tris_regs[my_port];
    }
    return ret;
}
Std_ReturnType gpio_port_logic_write(port_index_t my_port, uint8 my_logic){
     Std_ReturnType ret = E_OK;
    if (my_port > 4 ){
        ret = E_NOT_OK;
    }
    else{
        *port_regs[my_port] = my_logic;
    }
    return ret;
}
Std_ReturnType gpio_port_logic_read(port_index_t my_port , uint8 *retlogic){
    Std_ReturnType ret = E_OK;
    if (my_port > 4 || retlogic == NULL){
        ret = E_NOT_OK;
    }
    else{
        *retlogic = *lat_regs[my_port];
    }
    return ret;
}
Std_ReturnType gpio_port_logic_toggle(port_index_t my_port){
    Std_ReturnType ret = E_OK;
    if (my_port > 4 ){
        ret = E_NOT_OK;
    }
    else{
        *lat_regs[my_port] ^= 255;
    }
    return ret;
}