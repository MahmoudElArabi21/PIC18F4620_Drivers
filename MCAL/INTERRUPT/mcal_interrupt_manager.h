/* 
 * File:   mcal_interrupt_manager.h
 * Author: Mahmoud El Arabi
 *
 * Created on March 8, 2023, 4:29 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H


/*Section : includes*/
#include "mcal_interrupt_config.h"
/*Section : macros declaration*/

/*Section : macros function declaration*/

/*Section : data type declaration*/

/*Section : SW interfaces declaration*/
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void RB4_ISR(uint8 RB4_Source);
void RB5_ISR(uint8 RB5_Source);
void RB6_ISR(uint8 RB6_Source);
void RB7_ISR(uint8 RB7_Source);

void ADC_ISR(void);
void TMR0_ISR(void);
#endif	/* MCAL_INTERRUPT_MANAGER_H */

