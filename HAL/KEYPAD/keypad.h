/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  keypad.h
 *       Module:  keypad
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef KEYPAD_H
#define KEYPAD_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "common_macros.h"
#include <avr/io.h>

#define KEYPAD_ROW_PORT 	PORTC_ID
#define KEYPAD_ROW_DDR		DDRC


#define KEYPAD_COL_PORT     PORTD_ID
#define KEYPAD_COL_DDR      DDRD
#define KEYPAD_COL_PIN      PIND

#define KEYPAD_ROW1_PIN		PIN5_ID
#define KEYPAD_ROW2_PIN		PIN4_ID
#define KEYPAD_ROW3_PIN		PIN3_ID
#define KEYPAD_ROW4_PIN		PIN2_ID

#define KEYPAD_COL1_PIN		PIN7_ID
#define KEYPAD_COL2_PIN		PIN6_ID
#define KEYPAD_COL3_PIN		PIN5_ID
#define KEYPAD_COL4_PIN		PIN3_ID



void keypad_init();
char keyfind();


#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: FILE_NAME.h
 *********************************************************************************************************************/
