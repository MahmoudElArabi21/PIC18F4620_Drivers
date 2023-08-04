
#include "button.h"

Std_ReturnType button_inittialze(button_t *my_btn){
    Std_ReturnType ret = E_OK;
    if(NULL == my_btn){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_initialize(&(my_btn->button_pin));
    }
    return ret;
}
Std_ReturnType button_read_status(button_t *my_btn, btn_press_state_t *btn_state){
    Std_ReturnType ret = E_NOT_OK;
    logic_t Pin_Logic_Status = gpio_low;
    if((NULL == my_btn) || (NULL == btn_state)){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_logic_read(&(my_btn->button_pin), &Pin_Logic_Status);
        if(btn_active_high == my_btn->button_activate){
            if(gpio_high == Pin_Logic_Status){
                *btn_state = btn_pressed;
            }
            else {
                *btn_state = btn_released;
            }
        }
        else if(btn_active_low == my_btn->button_activate){
            if(gpio_high == Pin_Logic_Status){
                *btn_state = btn_released;
            }
            else {
                *btn_state = btn_pressed;
            }
        }
    }
    return ret;
}
