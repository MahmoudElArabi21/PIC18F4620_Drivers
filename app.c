/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"

uint8 eeprom_val = 0, eeprom_read_val;

led_t led1 = {port_D, pin_0, 0};

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    ret = led_init(&led1);
    ret = eeprom_write_byte(0x3ff, 0);
    
    while(1){
        ret = eeprom_write_byte(0x3ff, eeprom_val++);
        __delay_ms(1000);
        ret = eeprom_read_byte(0x3ff, &eeprom_read_val);
        
        if(5 == eeprom_read_val){
            led_turn_on(&led1);
        }
        else{
            led_turn_off(&led1);
        }
        
    }
    return (EXIT_SUCCESS);
}