/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  keypad.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "common_macros.h"
#include "keypad.h"
#include "GPIO.h"
#include <util/delay.h>
#include "std_types.h"



unsigned char keypad[4][4] = {{' ','0','=','+'},
		{'1','2','3','-'},
		{'4','5','6','*'},
		{'7','8','9','/'}};

unsigned char colloc, rowloc;

void keypad_init()
{

	/*Setting Rows pins as outputs*/
	//DDRC = 0x3C;
	//DDRD = 0x00;
	GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW2_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW3_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW4_PIN,PIN_OUTPUT);

	GPIO_setupPinDirection(KEYPAD_COL_PORT,KEYPAD_COL1_PIN,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT,KEYPAD_COL2_PIN,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT,KEYPAD_COL3_PIN,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT,KEYPAD_COL4_PIN,PIN_INPUT);


	PORTD = 0xFF;




}
char keyfind()
{


	while(1)
	{

		do
		{
			PORTD &= 0xE8;      		/* mask PORT for column read only */
			asm("NOP");
			colloc = (PIND & 0xE8); 	/* read status of column */
		}while(colloc != 0xE8);

		do
		{
			do
			{
				_delay_ms(20);             /* 20ms key debounce time */
			colloc = (PIND & 0xE8);        /* read status of column */
			}while(colloc == 0xE8);        /* check for any key press */

			_delay_ms (40);	            /* 20 ms key debounce time */
			colloc = (PIND & 0xE8);
		}while(colloc == 0xE8);

		/* now check for rows */
		PORTC = 0x38;            /* check for pressed key in 1st row .. 1st row low and the rest is high*/
		asm("NOP");
		colloc = (PIND & 0xE8);
		if(colloc != 0xE8)
		{
			rowloc = 0;
			PORTC = 0x00;
			break;

		}

		PORTC = 0x34;		/* check for pressed key in 2nd row */
		asm("NOP");
		colloc = (PIND & 0xE8);
		if(colloc != 0xE8)
		{
			rowloc = 1;
			PORTC = 0x00;
			break;

		}

		PORTC = 0x2C;		/* check for pressed key in 3rd row */
		asm("NOP");
		colloc = (PIND & 0xE8);
		if(colloc != 0xE8)
		{
			rowloc = 2;
			PORTC = 0x00;
			break;

		}

		PORTC = 0x1C;		/* check for pressed key in 4th row */
		asm("NOP");
		colloc = (PIND & 0xE8);
		if(colloc != 0xE8)
		{
			rowloc = 3;
			PORTC = 0x00;
			break;

		}
	}

	if(colloc == 0x68)
		return(keypad[rowloc][0]);
	else if(colloc == 0xA8)
		return(keypad[rowloc][1]);
	else if(colloc == 0xC8)
		return(keypad[rowloc][2]);
	else
		return(keypad[rowloc][3]);

}

