/*
 * DIOINOUT.c
 *
 * Created: 9/6/2020 5:37:03 PM
 *  Author: monad
 */ 
#include "DIO_INOUT.h"
void DIO_init(PORT_NUMBER PORTN,PIN_NUMBER PINN,PIN_CFG PIN_CFG_TYPE)
{
	if (PIN_CFG_TYPE==OUTPUT)
	{
		switch (PORTN)
		{
			case DIO_PORTA:
			SetBIT(PORTA_IO,PINN);
			break;
			case DIO_PORTB:
			SetBIT(PORTB_IO,PINN);
			break;
			case DIO_PORTC:
			SetBIT(PORTC_IO,PINN);
			break;
			case DIO_PORTD:
			SetBIT(PORTD_IO,PINN);
			break;
			default:
			break;
			
		}
	}
	else if (PIN_CFG_TYPE==INPUT)
	{
		switch (PORTN)
		{
			case DIO_PORTA:
			ClearBIT(PORTA_IO,PINN);
			break;
			case DIO_PORTB:
			ClearBIT(PORTB_IO,PINN);
			break;
			case DIO_PORTC:
			ClearBIT(PORTC_IO,PINN);
			break;
			case DIO_PORTD:
			ClearBIT(PORTD_IO,PINN);
			break;
			default:
			break;
			
		}
	}
}
void DIO_init_PORT(PORT_NUMBER PORTNUMMER,PIN_CFG PIN_CFG_NUMBER_DUPP)
{
	if (PIN_CFG_NUMBER_DUPP==OUTPUT)
	{
		switch (PORTNUMMER)
		{
			case DIO_PORTA:
			PORTA_IO=0XFF;
			break;
			case DIO_PORTB:
			PORTB_IO=0XFF;
			break;
			case DIO_PORTC:
			PORTC_IO=0XFF;
			break;
			case DIO_PORTD:
			PORTD_IO=0XFF;
			break;
			default:
			break;
			
		}
	}
	else if (PIN_CFG_NUMBER_DUPP==INPUT)
	{
		switch (PORTNUMMER)
		{
			case DIO_PORTA:
			PORTA_IO=0X00;
			break;
			case DIO_PORTB:
			PORTB_IO=0X00;
			break;
			case DIO_PORTC:
			PORTC_IO=0X00;
			break;
			case DIO_PORTD:
			PORTD_IO=0X00;
			break;
			default:
			break;
			
		}
	}
}
void DIO_WRITE (PORT_NUMBER PORTNUM,PIN_NUMBER PINNUM,PIN_STATUS PINSTAT)
{
	switch(PORTNUM){
		case DIO_PORTA:
		if (PINSTAT==HIGH)
		{
			SetBIT(PORTA_REG,PINNUM);
		} 
		else if(PINSTAT==LOW)
		{
			ClearBIT(PORTA_REG,PINNUM);
		}
		break;
		case DIO_PORTB:
		if (PINSTAT==HIGH)
		{
			SetBIT(PORTB_REG,PINNUM);
		}
		else if(PINSTAT==LOW)
		{
		    ClearBIT(PORTB_REG,PINNUM);
		}
		break;
		case DIO_PORTC:
		if (PINSTAT==HIGH)
		{
			SetBIT(PORTC_REG,PINNUM);
		}
		else if(PINSTAT==LOW)
		{
			ClearBIT(PORTC_REG,PINNUM);
		}
		break;
		case DIO_PORTD:
		if (PINSTAT==HIGH)
		{
			SetBIT(PORTD_REG,PINNUM);
		}
		else if(PINSTAT==LOW)
		{
			ClearBIT(PORTD_REG,PINNUM);
		}
		break;
		default:
		break;
	}	
}
void DIO_WRITE_DATA(PORT_NUMBER PORTNUMERO,Uint8 data_port)
{
	switch(PORTNUMERO)
	{
		case DIO_PORTA:
		PORTA_REG=data_port;
		break;
		case DIO_PORTB:
		PORTB_REG=data_port;
		break;
		case DIO_PORTC:
		PORTC_REG=data_port;
		break;
		case DIO_PORTD:
		PORTD_REG=data_port;
		break;
		default:
		break;
	}
}

