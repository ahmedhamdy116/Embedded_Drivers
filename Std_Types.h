/*
 * Std_Types.h
 *
 * Created: 10/25/2024 2:47:03 PM
 *  Author: Ahmed 
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char    u8;
typedef signed char    s8;

typedef unsigned short    u16;
typedef signed short    s16;

typedef unsigned long    u32;
typedef signed long     s32;


#define  MAX_u16     ((u16)65535)
#define  MIN_u16     ((u16)0)
#define  MAX_s16     ((s16)32767)
#define  MIN_s16     ((s16)-32768)

#define NULLPTR   ((void*)0)


typedef enum{
	FALSE=0x55,
	TRUE=0xAA
}bool_t;


typedef enum{
	OK=0,
	NOK,
	NULL_PTR,
	OUT_OF_RANGE,
	BUSY,

}error_t;



#define  GET_BIT(reg,bit)     (((reg)>>(bit))& 1)
#define  SET_BIT(reg,bit)     ((reg)=((reg)|(1<<(bit))))
#define  CLR_BIT(reg,bit)     ((reg)=((reg)&~(1<<(bit))))
#define  TOG_BIT(reg,bit)     ((reg)=((reg)^(1<<(bit))))



#endif /* STD_TYPES_H_ */