/* 
 * File:   segments_7.h
 * Author: Mahmoud El Arabi
 *
 * Created on August 4, 2023, 11:05 PM
 */

#ifndef SEGMENTS_7_H
#define	SEGMENTS_7_H

#include "../../MCAL/GPIO/gpio.h"

#define SEGEMENT_PIN0 0
#define SEGEMENT_PIN1 1
#define SEGEMENT_PIN2 2
#define SEGEMENT_PIN3 3

typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct{
    pin_config_t segment_pins[4];
    segment_type_t segment_type;
}segment_t;

Std_ReturnType seven_segement_intialize(const segment_t *seg);
Std_ReturnType seven_segement_write_number(const segment_t *seg, uint8 number);

#endif	/* SEGMENTS_7_H */

