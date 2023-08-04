/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"


segmest_t segment_anode = { .segment_pins[0].port = port_C,
                            .segment_pins[0].pin = 0,
                            .segment_pins[0].direction =0,
                            .segment_pins[0].logic=0,
                            .segment_pins[1].port = port_C,
                            .segment_pins[1].pin = 1,
                            .segment_pins[1].direction =0,
                            .segment_pins[1].logic=0,
                            .segment_pins[2].port = port_C,
                            .segment_pins[2].pin = 2,
                            .segment_pins[2].direction =0,
                            .segment_pins[2].logic=0 ,      
                            .segment_type = seg_com_anode  };

segmest_t segment_cathode = { .segment_pins[0].port = port_D,
                            .segment_pins[0].pin = 0,
                            .segment_pins[0].direction =0,
                            .segment_pins[0].logic=0,
                            .segment_pins[1].port = port_D,
                            .segment_pins[1].pin = 1,
                            .segment_pins[1].direction =0,
                            .segment_pins[1].logic=0,
                            .segment_pins[2].port = port_D,
                            .segment_pins[2].pin = 2,
                            .segment_pins[2].direction =0,
                            .segment_pins[2].logic=0 ,      
                            .segment_type = seg_com_cathode  };


int main() {
    segment_initialze(&segment_anode);
    segment_initialze(&segment_cathode);
    while(1){
        for( int j = 0; j<10; j++){
            segment_write_number(&segment_anode, j);
            segment_write_number(&segment_cathode, j);
            __delay_ms(1000);
        }
    }
}

