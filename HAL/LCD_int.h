/*
 * LCD_int.h
 *
 * Created: 12/7/2024 1:47:31 PM
 *  Author: Ahmed
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_



void LCD_init(void);

void LCD_Clear(void);

void LCD_write_char(u8 chr);

void LCD_write_num(s32 num);

void LCD_write_string(u8* str);


#endif /* LCD_INT_H_ */