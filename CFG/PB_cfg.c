/*
 * PB_cfg.c
 *
 * Created: 11/19/2024 10:14:49 PM
 *  Author: Ahmed
 */ 

#include "../Std_Types.h"
#include "../MCAL/DIO_int.h"
#include "../HAL/PB_int.h"
#include "PB_cfg.h"


Button_Filter_st Buttons_Charcterstic[4]={
	[0]={
		.Button_pin=PB1,
		.Depounce_cfg={
			.msSamplingRate=26,
			.nThreshold=5,
			},
		.stPBproberties={
			.PressCounter=0,
			.LatchCounter=0,
			.CurrentState=HIGH,
			.Button_Activation=Inactive,
			},
		},
	[1]={
		.Button_pin=PB2,
		.Depounce_cfg={
			.msSamplingRate=26,
			.nThreshold=5,
			},
		.stPBproberties={
			.PressCounter=0,
			.LatchCounter=0,
			.CurrentState=HIGH,
			.Button_Activation=Inactive,
			},
		},
	[2]={
		.Button_pin=PB3,
		.Depounce_cfg={
				.msSamplingRate=26,
				.nThreshold=5,
			},
		.stPBproberties={
				.PressCounter=0,
				.LatchCounter=0,
				.CurrentState=HIGH,
				.Button_Activation=Inactive,
			},
		},
	[3]={
		.Button_pin=PB4,
		.Depounce_cfg={
				.msSamplingRate=16,
				.nThreshold=5,
				},
		.stPBproberties={
				.PressCounter=0,
				.LatchCounter=0,
				.CurrentState=HIGH,
				.Button_Activation=Inactive,
				},
		},
};
	