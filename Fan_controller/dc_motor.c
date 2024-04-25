/*
 * dc_motor.c
 *
 *  Created on: Oct 8, 2023
 *      Author: abdo
 */
#include "dc_motor.h"

void DcMotor_Init(void) {
	GPIO_setupPinDirection(motor_port, IN1_motor, PIN_OUTPUT);
	GPIO_setupPinDirection(motor_port, IN2_motor, PIN_OUTPUT);
	GPIO_writePin(motor_port, IN1_motor, LOGIC_LOW);
	GPIO_writePin(motor_port, IN2_motor, LOGIC_LOW);

}
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {

	if (state == stop) {
		PWM_Timer0_Start(0);
		GPIO_writePin(motor_port, IN1_motor, LOGIC_LOW);
		GPIO_writePin(motor_port, IN2_motor, LOGIC_LOW);
	}

	else if (state == clockwise) {
		PWM_Timer0_Start(speed);
		GPIO_writePin(motor_port, IN1_motor, LOGIC_LOW);
		GPIO_writePin(motor_port, IN2_motor, LOGIC_HIGH);

	} else if (state == anti_clockwise) {
		PWM_Timer0_Start(speed);
		GPIO_writePin(motor_port, IN1_motor, LOGIC_HIGH);
		GPIO_writePin(motor_port, IN2_motor, LOGIC_LOW);
	}
}

