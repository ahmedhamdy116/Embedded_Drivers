/*
 * PB_prg.c
 *
 * Created: 11/18/2024 10:06:46 PM
 *  Author: Ahmed
 */ 

#include "../Std_Types.h"
#include "../MCAL/DIO_int.h"
#include "PB_int.h"
#include "../SERVICE/delay_int.h"
#include "../CFG/PB_cfg.h"

#define F_CPU  8000000
#include "util/delay.h"

Button_State_et ReadPushButton(Button_Filter_st* pButton)
{
	Button_State_et Button_state=Button_undefined;
	pButton->stPBproberties.PressCounter=0;
	pButton->stPBproberties.LatchCounter=0;
	u8 i=0;
	for(i=0;i<=pButton->Depounce_cfg.nThreshold;i++)
	{
		pButton->stPBproberties.CurrentState=DIO_read(PIND2);
		if (pButton->stPBproberties.Button_Activation==Inactive)
		{
			if (pButton->stPBproberties.CurrentState==LOW)
			{
				pButton->stPBproberties.PressCounter++;
				if (pButton->stPBproberties.PressCounter==pButton->Depounce_cfg.nThreshold)
				{
					Button_state=Button_pressed;
					pButton->stPBproberties.Button_Activation=Active;
				}else{  ;}
			}else{ break;}
		}
		else if (pButton->stPBproberties.Button_Activation==Active)
		{
			Button_state=Button_pressed;
			if (pButton->stPBproberties.CurrentState==HIGH)
			{
				pButton->stPBproberties.LatchCounter++;
				if(pButton->stPBproberties.LatchCounter==pButton->Depounce_cfg.nThreshold)
				{
					Button_state=Button_latched;
					pButton->stPBproberties.Button_Activation=Inactive;
				}else{  ;}
			}else{break;}
		}else{  ;}
		delay_millis(pButton->Depounce_cfg.msSamplingRate);
	}
	return Button_state;
}

Button_State_et ReadPushButton2(Button_num_et button_num)
{
	Button_State_et button_state;
	button_state=Button_undefined;
	switch (button_num)
	{
	case Button_1:
	if(DIO_read(PB1)==LOW)
	{
		button_state=Button_pressed;
		_delay_ms(30);
		while (DIO_read(PB1)==LOW);
		_delay_ms(30);
		
	}else{ button_state=Button_latched;}
	break;
	case Button_2:
	if(DIO_read(PB2)==LOW)
	{
		_delay_ms(30);
		while (DIO_read(PB2)==LOW);
		_delay_ms(30);
		button_state=Button_pressed;
		
	}else{button_state=Button_latched;}
	break;
	case Button_3:
	if(DIO_read(PB3)==LOW)
	{
		_delay_ms(30);
		while (DIO_read(PB3)==LOW);
		_delay_ms(30);
		button_state=Button_pressed;
		
	}else{button_state=Button_latched;}
	break;
	case Button_4:
	if(DIO_read(PB4)==LOW)
	{
		_delay_ms(30);
		while (DIO_read(PB4)==LOW);
		_delay_ms(30);
		button_state=Button_pressed;
		
	}else{button_state=Button_latched;}
	break;			
	}
	return button_state;
}