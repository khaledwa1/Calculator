
#define F_CPU 16000000UL
#include "lcd.h"
#include "GPIO.h"
#include <avr/io.h>
#include <util/delay.h>
#include "common_macros.h"
#include "keypad.h"
#include <stdio.h>
#include <stdlib.h>



int power(int base, int exponent) {
  int result = 1.0;

  if (exponent < 0) {
    base = 1.0 / base;
    exponent = -exponent;
  }

  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result *= base;
    }
    base *= base;
    exponent /= 2;
  }

  return result;
}

int main(void)
{
	int operand1 = 0;
	int operand2 = 0;
	char operator ='\0';
	int result=0;
	LCD_init();
	keypad_init();

	/*
	DDRC = 0x3C;
	DDRD =0x00;
	 */
	int index=0;
	int index2=0;

	//LCD_displayStringRowColumn(0,1,"kw");
	LCD_moveCursor(0,1);
	_delay_ms(5);
	//uint8 key= keypad_u8GetKey();

	unsigned char key;



	while(1)
	{
		key = keyfind();
		if (key == ' ')
		{
			LCD_sendCommand(LCD_CLEAR_COMMAND);
		}

		if(key == '+' || key == '-' || key == '*' || key == '/')
		{
			operator = key;
			LCD_displayCharacter(key);
		}
		/*
		LCD_moveCursor(0,index);
		LCD_displayCharacter(key);
		index++;
		 */
		if(operator == '\0')
		{
			if (key >= '0' && key <= '9')
			{
				// If the key is a digit, add it to the total
				if(index !=0)
				{
					int p =power(10,1);
					operand1 *= p;

				}

				operand1 += key - '0';
				index++;


				// Display the updated total on the LCD

				
				LCD_displayCharacter(key);
			}
		}
		else
		{
			if (key >= '0' && key <= '9')
			{
				if(index2 !=0)
				{
					if(index !=0)
					{
						int p =power(10,1);
						operand2 *= p;

					}
				}


				operand2 += key - '0';
				index2++;
				// If the key is a digit, add it to the total

				// Display the updated total on the LCD

				
				LCD_displayCharacter(key);

			}

		}
		if(key == '=')
		{
			LCD_displayCharacter(key);
			index=0;
			index2=0;

			switch (operator)
			{
			case '+':
				result =operand1+operand2;
				LCD_intgerToString(result);
				break;
			case '-':
				result =operand1-operand2;
				LCD_intgerToString(result);
				break;
			case '/':
				result =operand1/operand2;
				if(operand2 == 0)
				{
					LCD_displayString("Invalid Operation");
				}
				else
				{
					LCD_intgerToString(result);
				}

				break;
			case '*':
				result =operand1*operand2;
				LCD_intgerToString(result);
				/*LCD_displayCharacter('-');
				LCD_intgerToString(operand1);
				LCD_displayCharacter('-');
				LCD_intgerToString(operand2);*/
				
				
				break;
			default:
				break;
			}
			result =0;
			operand1=0;
			operand2=0;
			operator='\0';

		}


	}

	return 0;
}


