/*
 * DIO_INOUT.h
 *
 * Created: 9/6/2020 5:36:47 PM
 *  Author: monad
 */ 


#ifndef DIO_INOUT_H_
#define DIO_INOUT_H_
typedef unsigned char Uint8;
typedef enum {
	DIO_PORTA=0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
	}PORT_NUMBER;
typedef enum{
	PIN_ZERO=0,
	PIN_ONE,
	PIN_TWO,
	PIN_THREE,
	PIN_FOUR,
	PIN_FIVE,
	PIN_SIX,
	PIN_SEVEN
	}PIN_NUMBER;
typedef enum{
	LOW=0,
	HIGH
	}PIN_STATUS;
typedef enum{
		INPUT=0,
		OUTPUT
	}PIN_CFG;
void DIO_WRITE (PORT_NUMBER,PIN_NUMBER,PIN_STATUS);
void DIO_init(PORT_NUMBER ,PIN_NUMBER ,PIN_CFG );
void DIO_WRITE_DATA(PORT_NUMBER , Uint8 data_port);
void DIO_init_PORT(PORT_NUMBER ,PIN_CFG );
//PIN_STATUS DIO_READ  (PORT_NUMBER,PIN_NUMBER);
#define PORTA_REG (*((volatile Uint8*)0x3B))
#define PORTB_REG (*((volatile Uint8*)0x38))
#define PORTC_REG (*((volatile Uint8*)0x35))
#define PORTD_REG (*((volatile Uint8*)0x32))
#define PINA_IO   (*((volatile Uint8*)0x39))
#define PINB_IO   (*((volatile Uint8*)0x36))
#define PINC_IO   (*((volatile Uint8*)0x33))
#define PIND_IO   (*((volatile Uint8*)0x30))
#define PORTA_IO  (*((volatile Uint8*)0x3A))
#define PORTB_IO  (*((volatile Uint8*)0x37))
#define PORTC_IO  (*((volatile Uint8*)0x34))
#define PORTD_IO  (*((volatile Uint8*)0x31))
#define SetBIT(REG,BIT)     REG |=(1<<BIT)
#define ClearBIT(REG,BIT)   REG &=~(1<<BIT)
#endif /* DIO_INOUT_H_ */