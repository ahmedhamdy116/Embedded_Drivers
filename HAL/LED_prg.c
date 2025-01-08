/*
 * LED_prg.c
 *
 * Created: 11/12/2024 6:13:08 PM
 *  Author: Ahmed
 */ 

#include "../Std_Types.h"
#include "../MCAL/DIO_int.h"
#include "LED_int.h"
#include "../CFG/LED_cfg.h"

void LED_On(LED_t led)
{
	switch(led)
	{
		case LED_RED:
		DIO_write(RED_LED,HIGH);
		break;
		case LED_GREEN:
		DIO_write(GREEN_LED,HIGH);
		break;
		case LED_BLUE:
		DIO_write(BLUE_LED,HIGH);
		break;
	}
}

void LED_Off(LED_t led)
{
	switch(led)
	{
		case LED_RED:
		DIO_write(RED_LED,LOW);
		break;
		case LED_GREEN:
		DIO_write(GREEN_LED,LOW);
		break;
		case LED_BLUE:
		DIO_write(BLUE_LED,LOW);
		break;
	}
}

void LED_toggle(LED_t led)
{
	switch(led)
	{
		case LED_RED:
		DIO_toggle(RED_LED);
		break;
		case LED_GREEN:
		DIO_toggle(GREEN_LED);
		break;
		case LED_BLUE:
		DIO_toggle(BLUE_LED);
		break;
	}
}
