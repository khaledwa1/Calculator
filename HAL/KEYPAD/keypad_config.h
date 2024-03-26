/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  keypad_cfg.h
 *       Module:  keypad
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "std_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*	Rows Configurations	*/

#define KEYPAD_ROW1_PORT				PORTC_ID
#define KEYPAD_ROW1_CHANNEL				PIN5_ID

#define KEYPAD_ROW2_PORT				PORTC_ID
#define KEYPAD_ROW2_CHANNEL				PIN4_ID

#define KEYPAD_ROW3_PORT				PORTC_ID
#define KEYPAD_ROW3_CHANNEL				PIN3_ID

#define KEYPAD_ROW4_PORT				PORTC_ID
#define KEYPAD_ROW4_CHANNEL				PIN2_ID

/*	Columns Configurations	*/

#define KEYPAD_COL1_PORT				PORTD_ID
#define KEYPAD_COL1_CHANNEL				PIN7_ID

#define KEYPAD_COL2_PORT				PORTD_ID
#define KEYPAD_COL2_CHANNEL				PIN6_ID

#define KEYPAD_COL3_PORT				PORTD_ID
#define KEYPAD_COL3_CHANNEL				PIN5_ID

#define KEYPAD_COL4_PORT				PORTD_ID
#define KEYPAD_COL4_CHANNEL				PIN3_ID
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* KEYPAD_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: keypad_cfg.h
 *********************************************************************************************************************/
