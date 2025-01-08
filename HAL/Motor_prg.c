/*
 * Motor_prg.c
 *
 * Created: 11/10/2024 1:58:33 PM
 *  Author: Ahmed
 */ 
#include "../Std_Types.h"
#include "Motor_int.h"
#include "../CFG/Motor_cfg.h"
#include "../MCAL/DIO_int.h"

void Motor_stop(Motor_t motor)
{
	switch(motor)
	{
		case M1:
		DIO_write(M1_IN1,LOW);
		DIO_write(M1_IN2,LOW);
		break;
		case M2:
		DIO_write(M2_IN1,LOW);
		DIO_write(M2_IN2,LOW);
		break;
		case M3:
		DIO_write(M3_IN1,LOW);
		DIO_write(M3_IN2,LOW);
		break;
		case M4:
		DIO_write(M4_IN1,LOW);
		DIO_write(M4_IN2,LOW);
		break;
	}
}

void Motor_CW(Motor_t motor)
{
	switch(motor)
	{
		case M1:
		DIO_write(M1_IN1,HIGH);
		DIO_write(M1_IN2,LOW);
		break;
		case M2:
		DIO_write(M2_IN1,HIGH);
		DIO_write(M2_IN2,LOW);
		break;
		case M3:
		DIO_write(M3_IN1,HIGH);
		DIO_write(M3_IN2,LOW);
		break;
		case M4:
		DIO_write(M4_IN1,HIGH);
		DIO_write(M4_IN2,LOW);
		break;
	}
}


void Motor_CCW(Motor_t motor)
{
	switch(motor)
	{
		case M1:
		DIO_write(M1_IN1,LOW);
		DIO_write(M1_IN2,HIGH);
		break;
		case M2:
		DIO_write(M2_IN1,LOW);
		DIO_write(M2_IN2,HIGH);
		break;
		case M3:
		DIO_write(M3_IN1,LOW);
		DIO_write(M3_IN2,HIGH);
		break;
		case M4:
		DIO_write(M4_IN1,LOW);
		DIO_write(M4_IN2,HIGH);
		break;
	}
}