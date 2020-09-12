/*
 * LCD_Driver.c
 *
 * Created: 9/11/2020 8:08:26 PM
 * Author : monad
 */ 

#include <avr/io.h>
#include "LCD.h"

int main(void)
{
	unsigned char Character1[8] ={0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00};
	LCD_Init();
	LCD_Custom_Char(0, Character1);	/*cursor at home position */
	LCD_StartPOS(1,0x08);
	LCD_char(0);
	LCD_StartPOS(2,0x04);
	LCD_String("cheb mami");
    /* Replace with your application code */
    while (1) 
    {
    }
}

