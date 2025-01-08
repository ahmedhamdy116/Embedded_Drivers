/*
 * Motor_int.h
 *
 * Created: 11/10/2024 1:58:54 PM
 *  Author: Ahmed
 */ 


#ifndef MOTOR_INT_H_
#define MOTOR_INT_H_

typedef enum{
	M1,
	M2,
	M3,
	M4
}Motor_t;

void Motor_stop(Motor_t m);
void Motor_CW(Motor_t m);
void Motor_CCW(Motor_t m);



#endif /* MOTOR_INT_H_ */