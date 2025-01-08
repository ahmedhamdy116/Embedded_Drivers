/*
 * DIO_prg.c
 *
 * Created: 11/8/2024 9:06:16 PM
 *  Author: Ahmed
 */ 

#include "../Std_Types.h"
#include "../Memory_Map.h"

#include "DIO_int.h"
#include "DIO_private.h"


 

/* Another way to decrease the size of flash by not using switch*/

/*
volatile u8* DIO_reg[4][3]={{&DDRA,&PORTA,&PINA}
	                       ,{&DDRB,&PORTB,&PINB}
						   ,{&DDRC,&PORTC,&PINC}
						   ,{&DDRD,&PORTD,&PIND}};
	
void DIO_init(DIO_PIN_Num_t pin,DIO_PIN_Status_t status)
{
	DIO_port_t port=pin/8;
	u8 pin_num=pin%8;
	switch (status)
	{
		case INFREE:
		CLR_BIT(*DIO_reg[port][DDR],pin_num);
		CLR_BIT(*DIO_reg[port][Port],pin_num);
		break;
		case INPULL:
		CLR_BIT(*DIO_reg[port][DDR],pin_num);
		SET_BIT(*DIO_reg[port][Port],pin_num);
		break;
		case OUTPUT:
		SET_BIT(*DIO_reg[port][DDR],pin_num);
		SET_BIT(*DIO_reg[port][Port],pin_num);
		break;
	}
}
*/


void DIO_init_all(void)
{
	DIO_PIN_Num_t i=0;
	for(i=PINA0;i<TOTALPINS;i++)
	{
		DIO_init(i,Pins_status[i]);
	}
}


void DIO_init(DIO_PIN_Num_t pin,DIO_PIN_Status_t status)
{
	DIO_port_t port=pin/8;
	u8 pin_num=pin%8;
	switch (status)
	{
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}

void DIO_write(DIO_PIN_Num_t pin,DIO_Voltage_t voltage)
{
	DIO_port_t port=pin/8;
	u8 pin_num=pin%8;
	switch (voltage)
	{
		case LOW:
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case HIGH:
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}

DIO_Voltage_t DIO_read(DIO_PIN_Num_t pin)
{
	DIO_Voltage_t volt=LOW;
	DIO_port_t port =pin/8;
	u8 pin_num=pin%8;
	switch(port)
	{
		case PA:
		volt=GET_BIT(PORTA,pin_num);
		break;
		case PB:
		volt=GET_BIT(PORTB,pin_num);
		break;
		case PC:
		volt=GET_BIT(PORTC,pin_num);
		break;
		case PD:
		volt=GET_BIT(PORTD,pin_num);
		break;
	}
	return volt;
}

void DIO_toggle(DIO_PIN_Num_t pin)
{
	DIO_port_t port =pin/8;
	u8 pin_num=pin%8;
	switch(port)
	{
		case PA:
		TOG_BIT(PORTA,pin_num);
		break;
		case PB:
		TOG_BIT(PORTB,pin_num);
		break;
		case PC:
		TOG_BIT(PORTC,pin_num);
		break;
		case PD:
		TOG_BIT(PORTD,pin_num);
		break;
	}
}

void DIO_write_port(DIO_port_t port,u8 num)
{
	switch (port)
	{
		case PA:
		PORTA=num;
		break;
		case PB:
		PORTB=num;
		break;
		case PC:
		PORTC=num;
		break;
		case PD:
		PORTD=num;
		break;
	}
}

u8 DIO_read_Port(DIO_port_t port)
{
	u8 num=0;
	u8 i=0,value=0;
	switch (port)
	{
		case PA:
		for(i=0;i<8;i++)
		{
			value=GET_BIT(PORTA,i);
			if(value==0)
			{
				CLR_BIT(num,i);
			}else{
				SET_BIT(num,i);
			}
		}
		break;
		case PB:
		for(i=0;i<8;i++)
		{
			value=GET_BIT(PORTB,i);
			if(value==0)
			{
				CLR_BIT(num,i);
			}else{
				SET_BIT(num,i);
			}
		}
		break;
		case PC:
		for(i=0;i<8;i++)
		{
			value=GET_BIT(PORTC,i);
			if(value==0)
			{
				CLR_BIT(num,i);
			}else{
				SET_BIT(num,i);
			}
		}
		break;
		case PD:
		for(i=0;i<8;i++)
		{
			value=GET_BIT(PORTD,i);
			if(value==0)
			{
				CLR_BIT(num,i);
			}else{
				SET_BIT(num,i);
			}
		}
		break;
	}
	return num;
}