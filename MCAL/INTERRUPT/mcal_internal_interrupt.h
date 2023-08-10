/* 
 * File:   mcal_internal_interrupt.h
 * Author: Mahmoud El Arabi
 *
 * Created on March 8, 2023, 4:27 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H


/*Section : includes*/
#include "mcal_interrupt_config.h"


/*_____________________________ADC______________________________*/
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

#define ADC_InterruptDisable()         (PIE1bits.ADIE = 0)  
#define ADC_InterruptEnable()          (PIE1bits.ADIE = 1)   
#define ADC_InterruptFlagClear()       (PIR1bits.ADIF = 0)  

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
#define ADC_HighPrioritySet()           (IPR1bits.ADIP = 1)   
#define ADC_LowPrioritySet()            (IPR1bits.ADIP = 0)   

#endif
#endif

/*_____________________________TMR0______________________________*/
#if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE

#define TIMER0_InterruptDisable()         (INTCONbits.TMR0IE = 0)
#define TIMER0_InterruptEnable()          (INTCONbits.TMR0IE = 1)
#define TIMER0_InterruptFlagClear()       (INTCONbits.TMR0IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
#define TIMER0_HighPrioritySet()          (INTCON2bits.TMR0IP = 1)
#define TIMER0_LowPrioritySet()           (INTCON2bits.TMR0IP = 0)

#endif
#endif


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

