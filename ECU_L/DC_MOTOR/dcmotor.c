#include "dcmotor.h"

Std_ReturnType dc_motor_initialize(const dcmotor_t *my_dcmotor){
    Std_ReturnType ret = E_OK;
    if(NULL == my_dcmotor){
        ret = E_NOT_OK;
    }
    else{  
        ret = gpio_pin_initialize(&(my_dcmotor->dcmotorpins[0]));
        ret = gpio_pin_initialize(&(my_dcmotor->dcmotorpins[1]));
    }
    return ret;
}
Std_ReturnType dc_motor_move_right(const dcmotor_t *my_dcmotor){
    Std_ReturnType ret = E_OK;
    if(NULL == my_dcmotor){
        ret = E_NOT_OK;
    }
    else{  
        ret = gpio_pin_logic_write(&(my_dcmotor->dcmotorpins[0]), gpio_high);
        ret = gpio_pin_logic_write(&(my_dcmotor->dcmotorpins[1]), gpio_low);
    }
    return ret;
}
Std_ReturnType dc_motor_move_left(const dcmotor_t *my_dcmotor){
    Std_ReturnType ret = E_OK;
    if(NULL == my_dcmotor){
        ret = E_NOT_OK;
    }
    else{  
        ret = gpio_pin_logic_write(&(my_dcmotor->dcmotorpins[0]), gpio_low);
        ret = gpio_pin_logic_write(&(my_dcmotor->dcmotorpins[1]), gpio_high);
    }
    return ret;
}
Std_ReturnType dc_motor_stop(const dcmotor_t *my_dcmotor){
    Std_ReturnType ret = E_OK;
    if(NULL == my_dcmotor){
        ret = E_NOT_OK;
    }
    else{  
        ret = gpio_pin_logic_write(&(my_dcmotor->dcmotorpins[0]), gpio_low);
        ret = gpio_pin_logic_write(&(my_dcmotor->dcmotorpins[1]), gpio_low);
    }
    return ret;
}
