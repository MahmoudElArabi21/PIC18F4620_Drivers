/* 
 * File:   keypad.h
 * Author: Mahmoud El Arabi
 *
 * Created on August 6, 2023, 1:06 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#include "../../MCAL/GPIO/gpio.h"

#define ECU_KEYPAD_ROWS    4
#define ECU_KEYPAD_COLUMNS 4 

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/
typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];
    pin_config_t keypad_columns_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value);

#endif	/* KEYPAD_H */

