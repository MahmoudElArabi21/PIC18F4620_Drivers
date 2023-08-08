/* 
 * File:   eeprom.h
 * Author: Mahmoud El Arabi
 *
 * Created on August 8, 2023, 5:02 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H
#include "../GPIO/gpio.h"
#include "../INTERRUPT/mcal_exrternal_interrupt.h"
Std_ReturnType eeprom_write_byte(uint16 EADD, uint8 EData);
Std_ReturnType eeprom_read_byte(uint16 EADD, uint8 *EData);
#endif	/* EEPROM_H */

