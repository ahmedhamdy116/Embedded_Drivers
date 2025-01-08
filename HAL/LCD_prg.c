/*
 * LCD_prg.c
 *
 * Created: 12/7/2024 1:47:57 PM
 *  Author: Ahmed
 */ 

#include "../Std_Types.h"
#include "../MCAL/DIO_int.h"
#include "LCD_int.h"
#include "LCD_Private.h"
#include "../CFG/LCD_cfg.h"

#define F_CPU  8000000
#include "util/delay.h"

static void write_instruction(u8 ins)
{
	DIO_write(RS_PIN,LOW);
	DIO_write(D7_PIN,GET_BIT(ins,7));
	DIO_write(D6_PIN,GET_BIT(ins,6));
	DIO_write(D5_PIN,GET_BIT(ins,5));
	DIO_write(D4_PIN,GET_BIT(ins,4));
	DIO_write(EN_PIN,HIGH);
	_delay_ms(1);
	DIO_write(EN_PIN,LOW);
	_delay_ms(1);
	DIO_write(RS_PIN,LOW);
	DIO_write(D7_PIN,GET_BIT(ins,3));
	DIO_write(D6_PIN,GET_BIT(ins,2));
	DIO_write(D5_PIN,GET_BIT(ins,1));
	DIO_write(D4_PIN,GET_BIT(ins,0));
	DIO_write(EN_PIN,HIGH);
	_delay_ms(1);
	DIO_write(EN_PIN,LOW);
	_delay_ms(1);
}

static void write_data(u8 data)
{
	DIO_write(RS_PIN,HIGH);
	DIO_write(D7_PIN,GET_BIT(data,7));
	DIO_write(D6_PIN,GET_BIT(data,6));
	DIO_write(D5_PIN,GET_BIT(data,5));
	DIO_write(D4_PIN,GET_BIT(data,4));
	DIO_write(EN_PIN,HIGH);
	_delay_ms(1);
	DIO_write(EN_PIN,LOW);
	_delay_ms(1);
	DIO_write(RS_PIN,HIGH);
	DIO_write(D7_PIN,GET_BIT(data,3));
	DIO_write(D6_PIN,GET_BIT(data,2));
	DIO_write(D5_PIN,GET_BIT(data,1));
	DIO_write(D4_PIN,GET_BIT(data,0));
	DIO_write(EN_PIN,HIGH);
	_delay_ms(1);
	DIO_write(EN_PIN,LOW);
	_delay_ms(1);
}

void LCD_init(void)
{
	_delay_ms(40);
	write_instruction(0x02);
	write_instruction(0x28);
	_delay_ms(1);
	write_instruction(0x0c);
	_delay_ms(1);
	write_instruction(0x01);
	_delay_ms(5);
	write_instruction(0x06);
}


void LCD_Clear(void)
{
	write_instruction(0x01);
}

void LCD_write_char(u8 chr)
{
	write_data(chr);
}

void LCD_write_num(s32 num)
{
	u8 str[10],i=0;
	if(num==0)
	{
		LCD_write_char('0');
	}else
	{
		if(num<0)
		{
			num=-num;
			LCD_write_char('-');
		}else{  ;}
		while (num)
		{
			str[i++]=(num%10) +'0';
			num/=10;
		}
		for(s8 j=i-1;j>=0;j--)
		{
			LCD_write_char(str[j]);
		}	
	}
}

void LCD_write_string(u8* str)
{
	for(u8 i=0;str[i];i++)
	{
		LCD_write_char(str[i]);
	}
}

void LCD_Custom_Char(u8 location)
{
	write_instruction(0x40+(location*8));
	
}