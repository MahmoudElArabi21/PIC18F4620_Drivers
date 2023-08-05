#include "segments_7.h"

Std_ReturnType seven_segement_intialize(const segment_t *seg){
    Std_ReturnType ret = E_OK;
    if(NULL == seg){
        ret = E_NOT_OK;
    }
    else{    
        ret = gpio_pin_initialize(&(seg->segment_pins[SEGEMENT_PIN0]));
        ret = gpio_pin_initialize(&(seg->segment_pins[SEGEMENT_PIN1]));
        ret = gpio_pin_initialize(&(seg->segment_pins[SEGEMENT_PIN2]));
        ret = gpio_pin_initialize(&(seg->segment_pins[SEGEMENT_PIN3]));
    }
    return ret;
}
Std_ReturnType seven_segement_write_number(const segment_t *seg, uint8 number){
    Std_ReturnType ret = E_OK;
    if((NULL == seg) && (number > 9)){
        ret = E_NOT_OK;
    }
    else{    
        ret = gpio_pin_logic_write(&(seg->segment_pins[SEGEMENT_PIN0]), (number & 0x01));
        ret = gpio_pin_logic_write(&(seg->segment_pins[SEGEMENT_PIN1]), (number>>1 & 0x01));
        ret = gpio_pin_logic_write(&(seg->segment_pins[SEGEMENT_PIN2]), (number>>2 & 0x01));
        ret = gpio_pin_logic_write(&(seg->segment_pins[SEGEMENT_PIN3]), (number>>3 & 0x01));
    }
    return ret;
}
