/* 
 * File:   segments_7.h
 * Author: Mahmoud El Arabi
 *
 * Created on August 4, 2023, 11:05 PM
 */

#ifndef SEGMENTS_7_H
#define	SEGMENTS_7_H

#include "../../MCAL/GPIO/gpio.h"


typedef enum{
    seg_com_anode,
    seg_com_cathode
}segment_type_t;

typedef struct{
    pin_config_t segment_pins[4];
    segment_type_t segment_type ;
}segmest_t;

Std_ReturnType segment_initialze(const segmest_t *my_segment);
Std_ReturnType segment_write_number(const segmest_t *my_segment, int number);
#endif	/* SEGMENTS_7_H */

