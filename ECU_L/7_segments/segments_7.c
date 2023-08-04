#include "segments_7.h"

Std_ReturnType segment_initialze(const segmest_t *my_segment){
    Std_ReturnType ret = E_OK;
    if(NULL == my_segment){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_initialize(&(my_segment->segment_pins[0]));
        ret = gpio_pin_initialize(&(my_segment->segment_pins[1]));
        ret = gpio_pin_initialize(&(my_segment->segment_pins[2]));
        ret = gpio_pin_initialize(&(my_segment->segment_pins[3]));
    }
    return ret;
}
Std_ReturnType segment_write_number(const segmest_t *my_segment, int number){
    Std_ReturnType ret = E_OK;
    if((NULL == my_segment) && (number > 9)){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_logic_write(&(my_segment->segment_pins[0]), (number& 1));
        ret = gpio_pin_logic_write(&(my_segment->segment_pins[1]), (number>>1 & 0x01));
        ret = gpio_pin_logic_write(&(my_segment->segment_pins[2]), (number>>2 & 0x01));
        ret = gpio_pin_logic_write(&(my_segment->segment_pins[3]), (number>>3 & 0x01));
    }
    return ret;
}
