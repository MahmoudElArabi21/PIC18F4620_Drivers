/* 
 * File:   dcmotor.h
 * Author: Mahmoud El Arabi
 *
 * Created on August 4, 2023, 7:20 PM
 */

#ifndef DCMOTOR_H
#define	DCMOTOR_H

#include "../../MCAL/GPIO/gpio.h"

#define dc_on  0x01u
#define dc_off 0x00u


typedef struct {
    pin_config_t dcmotorpins[2];
}dcmotor_t;

Std_ReturnType dc_motor_initialize(const dcmotor_t *my_dcmotor);
Std_ReturnType dc_motor_move_right(const dcmotor_t *my_dcmotor);
Std_ReturnType dc_motor_move_left(const dcmotor_t *my_dcmotor);
Std_ReturnType dc_motor_stop(const dcmotor_t *my_dcmotor);
#endif	/* DCMOTOR_H */

