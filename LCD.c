/*
 * LCD.c
 *
 * Created: 9/11/2020 8:11:03 PM
 *  Author: monad
 */ 
#include "LCD.h"
#include "DIO_INOUT.h"
#define F_CPU 16000000UL
#include <util/delay.h>
void LCD_Init(void)
{
	DIO_init(LCD_Init_REG,LCD_RW,OUTPUT);
	DIO_init(LCD_Init_REG,LCD_RS,OUTPUT);
	DIO_init(LCD_Init_REG,LCD_EN,OUTPUT);
	DIO_init_PORT(LCD_CMD_REG,OUTPUT);
	DIO_WRITE(LCD_Init_REG,LCD_RW,LOW);
	_delay_ms(25);
	LCD_CMD(0x33);
	_delay_us(200);
	LCD_CMD(0x32);
	LCD_CMD(0x28); //set function
	LCD_CMD(0x06); //entry mode
	LCD_CMD(0x0C); //display on
	LCD_CMD(0x01); //clear lcd
	_delay_ms(2);
	
}
void LCD_CMD (Uint8 cmd)
{
	//sending high nipple 3
	Uint8 sendcmd=(LCD_CMD_REG &(0x0F))|((0xF0)&(cmd));
	DIO_WRITE_DATA(LCD_CMD_REG,sendcmd);
	DIO_WRITE(LCD_Init_REG,LCD_RS,LOW);
	DIO_WRITE(LCD_Init_REG,LCD_EN,HIGH);
	_delay_ms(50);
	DIO_WRITE(LCD_Init_REG,LCD_EN,LOW);
	_delay_ms(5);
	//sending low nipple 3
	sendcmd=(LCD_CMD_REG &(0x0F))|(cmd<<4);
	DIO_WRITE_DATA(LCD_CMD_REG,sendcmd);
	DIO_WRITE(LCD_Init_REG,LCD_RS,LOW);
	DIO_WRITE(LCD_Init_REG,LCD_EN,HIGH);
	_delay_ms(50);
	DIO_WRITE(LCD_Init_REG,LCD_EN,LOW);
	_delay_ms(2);
}
void LCD_char(Uint8 data)
{
	//sending high nipple 3
	Uint8 sendcmd=(LCD_CMD_REG &(0x0F))|((0xF0)&(data));
	DIO_WRITE_DATA(LCD_CMD_REG,sendcmd);
	DIO_WRITE(LCD_Init_REG,LCD_RS,HIGH);
	DIO_WRITE(LCD_Init_REG,LCD_EN,HIGH);
	_delay_ms(50);
	DIO_WRITE(LCD_Init_REG,LCD_EN,LOW);
	_delay_ms(5);
	//sending low nipple 3
	sendcmd=(LCD_CMD_REG &(0x0F))|(data<<4);
	DIO_WRITE_DATA(LCD_CMD_REG,sendcmd);
	DIO_WRITE(LCD_Init_REG,LCD_RS,HIGH);
	DIO_WRITE(LCD_Init_REG,LCD_EN,HIGH);
	_delay_ms(50);
	DIO_WRITE(LCD_Init_REG,LCD_EN,LOW);
	_delay_ms(2);
	
}
void LCD_String(char* data)
{
	Uint8 count=0;
	while(data[count] !='\0')
	{
		LCD_char(data[count]);
		++count;
	}
	
}
void LCD_StartPOS(Uint8 line,Uint8 pos){
	Uint8 SendCmd;
	switch(line){
		case 1:
		SendCmd = 0x80 | (pos & 0x0F);//ff ---> 0f|0x80 ---> 0x8f
		LCD_CMD(SendCmd);
		break;
		case 2:
		SendCmd = 0xC0 | (pos & 0x0F);
		LCD_CMD(SendCmd);
		break;
	}
}
void LCD_Custom_Char (Uint8 loc, Uint8 *msg)
{
	Uint8 i;
	if(loc<8)
	{
		LCD_CMD (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_char(msg[i]);
	}
}

