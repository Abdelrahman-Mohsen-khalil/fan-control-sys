/*
 * dc_motor.h
 *
 *  Created on: Oct 8, 2023
 *      Author: abdo
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "gpio.h"
#include "pwm.h"
#include "std_types.h"
#define motor_port   PORTB_ID
#define IN1_motor  PIN0_ID
#define IN2_motor  PIN1_ID
typedef enum {
	stop, clockwise, anti_clockwise
} DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
