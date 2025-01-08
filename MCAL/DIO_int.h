/*
 * DIO_int.h
 *
 * Created: 11/8/2024 9:06:36 PM
 *  Author: Ahmed
 */ 


#ifndef DIO_INT_H_
#define DIO_INT_H_




typedef enum{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTALPINS
}DIO_PIN_Num_t;

typedef enum{
	PA,
	PB,
	PC,
	PD
}DIO_port_t;

typedef enum{
	INFREE,
	INPULL,
	OUTPUT
}DIO_PIN_Status_t;
	
typedef enum
{
	LOW=0,
	HIGH=1,
}DIO_Voltage_t;

void DIO_init_all(void);
void DIO_init(DIO_PIN_Num_t pin,DIO_PIN_Status_t status);
void DIO_write(DIO_PIN_Num_t pin,DIO_Voltage_t voltage);
DIO_Voltage_t DIO_read(DIO_PIN_Num_t pin);
void DIO_toggle(DIO_PIN_Num_t pin);
void DIO_write_port(DIO_port_t port,u8 num);
u8 DIO_read_Port(DIO_port_t port);


#endif /* DIO_INT_H_ */