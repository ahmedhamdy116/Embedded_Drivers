/*
 * delay_prg.c
 *
 * Created: 11/12/2024 5:59:06 PM
 *  Author: Ahmed
 */ 
#include "../Std_Types.h"

void delay_micros(u16 delay_micro)
{
	while(delay_micro--)
	{
		asm volatile ("nop");
		asm volatile ("nop"); 
	}
}

void delay_millis(u16 delay_milli)
{
	while(delay_milli--)
	{
		delay_micros(1000);
	}
}