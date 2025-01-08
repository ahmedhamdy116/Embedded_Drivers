/*
 * LED_int.h
 *
 * Created: 11/12/2024 6:13:29 PM
 *  Author: Ahmed
 */ 


#ifndef LED_INT_H_
#define LED_INT_H_

typedef enum
{
	LED_RED,
	LED_GREEN,
	LED_BLUE	
}LED_t;

void LED_On(LED_t led);
void LED_Off(LED_t led);
void LED_toggle(LED_t led);

#endif /* LED_INT_H_ */