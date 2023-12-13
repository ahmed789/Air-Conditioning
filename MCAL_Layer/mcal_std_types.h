/* 
 * File:   mcal_std_types.h
 * Author: ahmed
 *
 * Created on October 16, 2023, 2:07 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*Section : Includes */
#include "std_libraries.h"
#include "compiler.h"
 
/*Section :Data Types Declarations */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32 ;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32 ;
typedef signed long long sint64;

typedef float float32;
typedef double float64;

typedef uint8 std_ReturnType;
typedef uint8 Std_ReturnType;

/*Section Macro Declarations*/
#define STD_HIGH        0X01
#define STD_LOW         0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK       (std_ReturnType)    0x01
#define E_NOT_OK   (std_ReturnType)    0x00 

#define ZERO_INIT 0

#define _XTAL_FREQ 8000000

/*Section Macro Functions Declarations */

/*Section Functions Declarations  */

#endif	/* MCAL_STD_TYPES_H */

