/* 
 * File:   mcal_types.h
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:29 AM
 */

#ifndef MCAL_TYPES_H
#define	MCAL_TYPES_H


/* Section : Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>

/* Section: Data Type Declarations */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;

typedef uint8 Std_ReturnType;

/* Section: Macro Declarations */
#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define E_OK         (Std_ReturnType)0x01
#define E_NOT_OK     (Std_ReturnType)0x00

#define ZERO_INIT 0

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif	/* MCAL_TYPES_H */

