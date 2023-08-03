/* 
 * File:   gpio.h
 * Author: Mahmoud El Arabi
 * https://www.linkedin.com/in/mahmoudarabi21/
 * Created on August 3, 2023, 3:20 AM
 */

#ifndef GPIO_H
#define	GPIO_H
#include "gpio_cfg.h"
#include "../mcal_types.h"
#include "pic18f4620.h"


/* Section: Macro Functions Declarations */
#define HWREG(_x) (*((volatile uint8 *)(_x)))
#define bit_set(reg, pos) (reg |=(1<<pos))
#define bit_clear(reg, pos) (reg &= ~(1<<pos))
#define bit_toggle(reg, pos) (reg ^=(1<<pos))
#define bit_read(reg, pos)  ((reg>>pos) & 1) 

/* Section: Data Type Declarations */
typedef enum {
            gpio_low, 
            gpio_high
}logic_t;

typedef enum{
            gpio_output,
            gpio_input
}direction_t;

typedef enum{
            pin_0,
            pin_1,
            pin_2,
            pin_3,
            pin_4,
            pin_5,
            pin_6,
            pin_7,
}pin_index_t;

typedef enum {
            port_A,
            port_B,
            port_C,
            port_D,
            port_E
}port_index_t;

typedef struct{
    uint8 port :3;
    uint8 pin :3;
    uint8 direction :1;
    uint8 logic :1;
}pin_config_t;

/* Section: Function Declarations */

Std_ReturnType gpio_pin_direction_init(const pin_config_t *my_pin);
Std_ReturnType gpio_pin_direction_stat(const pin_config_t *my_pin, direction_t *retdirection);
Std_ReturnType gpio_pin_logic_write(const pin_config_t *my_pin);
Std_ReturnType gpio_pin_logic_read(const pin_config_t *my_pin, logic_t *retlogic);
Std_ReturnType gpio_pin_logic_toggle(const pin_config_t *my_pin);
Std_ReturnType gpio_pin_initialize(const pin_config_t *my_pin);

Std_ReturnType gpio_port_direction_init(port_index_t my_port, uint8 my_direction);
Std_ReturnType gpio_port_direction_stat(port_index_t my_port , uint8 *retdirection);
Std_ReturnType gpio_port_logic_write(port_index_t my_port, uint8 my_logic);
Std_ReturnType gpio_port_logic_read(port_index_t my_port , uint8 *retlogic);
Std_ReturnType gpio_port_logic_toggle(port_index_t my_port);
#endif	/* GPIO_H */

