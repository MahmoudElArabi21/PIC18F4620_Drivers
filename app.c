/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"

pin_config_t pin0_portd = {port_A, pin_0, gpio_output, gpio_high};
int main() {
    gpio_port_direction_init(port_D, 64);
    while(1){
    __delay_ms(200);
    gpio_port_logic_toggle(port_D);
    }
}
