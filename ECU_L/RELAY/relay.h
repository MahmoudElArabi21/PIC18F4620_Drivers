/* 
 * File:   relay.h
 * Author: Mahmoud El Arabi
 *
 * Created on August 4, 2023, 5:06 PM
 */

#ifndef RELAY_H
#define	RELAY_H

#include "../../MCAL/GPIO/gpio.h"


#define relay_status_on  0x01u
#define relay_status_off 0x00u

typedef struct {
    uint8 relay_port :3;
    uint8 relay_pin :3;
    uint8 relay_status :1;
}relay_t;

Std_ReturnType relay_initialize(const relay_t *my_relay);
Std_ReturnType relay_turn_on(const relay_t *my_relay);
Std_ReturnType relay_turn_off(const relay_t *my_relay);

#endif	/* RELAY_H */

