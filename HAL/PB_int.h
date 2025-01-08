/*
 * PB_int.h
 *
 * Created: 11/18/2024 10:06:17 PM
 *  Author: Ahmed
 */ 


#ifndef PB_INT_H_
#define PB_INT_H_



typedef enum
{
	Inactive=0,
	Active=1,
}Activation_et;


typedef struct  
{
	u8 msSamplingRate;
	u8 nThreshold;	
}Depouncing_Cfg_st;


typedef struct
{
	u8 PressCounter;
	u8 LatchCounter;
	DIO_Voltage_t  CurrentState;
	Activation_et  Button_Activation;
}Button_Proberties_st;

typedef struct  
{
	DIO_PIN_Num_t Button_pin;
	Depouncing_Cfg_st Depounce_cfg;
	Button_Proberties_st  stPBproberties;
}Button_Filter_st;

typedef enum
{
	Button_latched=0,
	Button_pressed=1,
	Button_undefined=2,	
}Button_State_et;

typedef enum
{
	Button_1,
	Button_2,
	Button_3,
	Button_4,
}Button_num_et;




Button_State_et ReadPushButton(Button_Filter_st* pButton);
Button_State_et ReadPushButton2(Button_num_et button_num);

#endif /* PB_INT_H_ */