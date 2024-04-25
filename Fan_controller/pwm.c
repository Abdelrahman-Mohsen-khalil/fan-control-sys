/*
 * pwm.c
 *
 *  Created on: Oct 8, 2023
 *      Author: abdo
 */
#include "pwm.h"
#include <avr/io.h>
#include "gpio.h"
void PWM_Timer0_Start(uint8 duty_cycle) {
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
	TCNT0 = 0;
	OCR0 = ((float)duty_cycle / 100) * 255;

}

