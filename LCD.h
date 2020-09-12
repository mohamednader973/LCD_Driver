/*
 * LCD.h
 *
 * Created: 9/11/2020 8:10:50 PM
 *  Author: monad
 */ 

#include "DIO_INOUT.h"
#ifndef LCD_H_
#define LCD_H_
#define LCD_CMD_REG     DIO_PORTA //0
#define LCD_Init_REG    DIO_PORTB //1
#define LCD_RS          PIN_ONE
#define LCD_RW          PIN_TWO
#define LCD_EN          PIN_THREE
void LCD_Init(void);
void LCD_CMD (Uint8 cmd);
void LCD_char(Uint8 data);
void LCD_String(char* data);
void LCD_StartPOS(Uint8 line,Uint8 pos);
void LCD_Custom_Char (Uint8 loc, Uint8 *msg);
#endif /* LCD_H_ */