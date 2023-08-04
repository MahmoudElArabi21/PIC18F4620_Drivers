/* 
 * File:   button.h
 * Author: Mahmoud El Arabi
 *
 * Created on August 4, 2023, 2:54 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "../../MCAL/GPIO/gpio.h"

typedef enum{
    btn_pressed,
    btn_released,
}btn_press_state_t;

typedef enum{
    btn_active_high,
    btn_active_low,
}btn_active_state_t;

typedef struct {
    pin_config_t button_pin;
    btn_press_state_t button_state;
    btn_active_state_t button_activate;
}button_t;

Std_ReturnType button_inittialze(button_t *my_btn);
Std_ReturnType button_read_status(button_t *my_btn, btn_press_state_t *btn_state);

#endif	/* BUTTON_H */

