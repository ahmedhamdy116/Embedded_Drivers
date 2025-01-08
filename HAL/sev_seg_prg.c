/*
 * _sev_seg_prg.c
 *
 * Created: 11/22/2024 9:16:41 PM
 *  Author: Ahmed
 */ 

#include "../Std_Types.h"
#include "../MCAL/DIO_int.h"
#include "sev_seg_int.h"
#include "../CFG/sev_seg_cfg.h"

#define F_CPU  8000000
#include "util/delay.h"


static u8 sev_seg[10]={0x3F,0x06,0x5B,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	

void Turn_on_sev_seg(sev_seg_num_et sev_seg_num)
{
	switch (sev_seg_num)
	{
	case SevenSegment1:
		DIO_write(PINC6,HIGH);
		break;
	case SevenSegment2:
		DIO_write(PINC7,HIGH);
		break;		
	}
		
}

void Turn_off_sev_seg(sev_seg_num_et sev_seg_num)
{
	switch (sev_seg_num)
	{
		case SevenSegment1:
		DIO_write(PINC6,LOW);
		break;
		case SevenSegment2:
		DIO_write(PINC7,LOW);
		break;
	}
	
}

void sev_seg_display(u8 num)
{
	DIO_write_port(sev_seg_port,sev_seg[num]<<1);
}

void sev_seg_display_two(u8 num)
{
	u8 d0=num%10;
	u8 d1=num/10;
	Turn_on_sev_seg(SevenSegment1);
	Turn_off_sev_seg(SevenSegment2);
	DIO_write_port(sev_seg_port,sev_seg[d0]<<1);
	_delay_ms(20);
	Turn_on_sev_seg(SevenSegment2);
	Turn_off_sev_seg(SevenSegment1);
	DIO_write_port(sev_seg_port,sev_seg[d1]<<1);
	_delay_ms(20);
}