/* 
 * File:   hal_eeprom.h
 * Author: ahmed
 *
 * Created on November 28, 2023, 6:06 PM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/* ----------------- Includes -----------------*/
#include"pic18f4620.h"
#include"../mcal_std_types.h"
/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd, uint8 bData);
Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd, uint8 *bData);
#endif	/* HAL_EEPROM_H */

