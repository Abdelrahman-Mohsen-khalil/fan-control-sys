#include "lcd.h"
#include "adc.h"
#include "lm35_sensor.h"
#include "dc_motor.h"

int main() {
	ADC_ConfigType ADCX = { internal_2_65VOlt, prescal_8 };
	ADC_init(&ADCX);
	LCD_init();
	DcMotor_Init();
	LCD_moveCursor(1, 4);
	LCD_displayString("Temp =    C");
	uint8 temp=0;
	while (1) {
		temp = LM35_getTemperature();

		if (temp < 30) {
			DcMotor_Rotate(stop, 0);
			LCD_moveCursor(0, 4);
			LCD_displayString("FAN IS OFF");
			LCD_moveCursor(1, 11);
//			LCD_intgerToString(temp);
			if (temp >9) {
						LCD_intgerToString(temp);
					} else {
						LCD_intgerToString(temp);

						LCD_displayCharacter(' ');
					}
		}
		else if (temp >= 30 && temp < 60) {
			DcMotor_Rotate(clockwise, 25);
			LCD_moveCursor(0, 4);

			LCD_displayString("FAN IS ON");

			LCD_displayCharacter(' ');

			LCD_moveCursor(1, 11);

			LCD_intgerToString(temp);

		}

		else if (temp >= 60 && temp < 90) {

			DcMotor_Rotate(clockwise, 50);
			LCD_moveCursor(0, 4);
			LCD_displayString("FAN IS ON");

			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
		}


		else if (temp >= 90 && temp < 120) {
			DcMotor_Rotate(clockwise, 75);
			LCD_moveCursor(0, 4);

			LCD_displayString("FAN IS ON");

			LCD_displayCharacter(' ');

			LCD_moveCursor(1, 11);

			if (temp >= 100) {
				LCD_intgerToString(temp);
			} else {
				LCD_intgerToString(temp);

				LCD_displayCharacter(' ');
			}
		}



		else if (temp >= 120) {
			DcMotor_Rotate(clockwise, 100);
			LCD_moveCursor(0, 4);
			LCD_displayString("FAN IS ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);

		}

	}
}

