#include "keypad.h"
static const uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS] = {
                                                                        {'7', '8', '9', '/'},
                                                                        {'4', '5', '6', '*'},
                                                                        {'1', '2', '3', '-'},
                                                                        {'#', '0', '=', '+'}
                                                                     };

Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj){
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT, columns_counter = ZERO_INIT;
    if(NULL == _keypad_obj){
        ret = E_NOT_OK;
    }
    else{    
        for(rows_counter=ZERO_INIT; rows_counter<ECU_KEYPAD_ROWS; rows_counter++){
            ret = gpio_pin_initialize(&(_keypad_obj->keypad_row_pins[rows_counter]));
        }
        for(columns_counter=ZERO_INIT; columns_counter<ECU_KEYPAD_COLUMNS; columns_counter++){
            ret = gpio_pin_direction_init(&(_keypad_obj->keypad_columns_pins[columns_counter]));
        }
    }
    return ret;
}

Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value){
    Std_ReturnType ret = E_OK;
    uint8 l_rows_counter = ZERO_INIT, l_columns_counter = ZERO_INIT, l_counter = ZERO_INIT;
    logic_t column_logic = ZERO_INIT;
    if((NULL == _keypad_obj) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{    
        for(l_rows_counter=ZERO_INIT; l_rows_counter<ECU_KEYPAD_ROWS; l_rows_counter++){
            for(l_counter=ZERO_INIT; l_counter<ECU_KEYPAD_ROWS; l_counter++){
                ret = gpio_pin_logic_write(&(_keypad_obj->keypad_row_pins[l_counter]), 0);
            }
            gpio_pin_logic_write(&(_keypad_obj->keypad_row_pins[l_rows_counter]), 1);
            __delay_ms(10);
            for(l_columns_counter=ZERO_INIT; l_columns_counter<ECU_KEYPAD_COLUMNS; l_columns_counter++){
                ret = gpio_pin_logic_read(&(_keypad_obj->keypad_columns_pins[l_columns_counter]), &column_logic);
                if(1 == column_logic){
                    *value = btn_values[l_rows_counter][l_columns_counter];
                }
            }
        }
    }
    return ret;
}