#include "main.h"
#include "v5setup.h"
#include "../functions/dzCorrect.cpp"

void opcontrol() {



	while (true) {

		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);


		// sets int right and left to right and left joysticks
		//int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		//int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

		// sets right drive and left drive to ints right and left which
		// are found above my the joystick


//sets ints for right and left motor based on dead zone correction function
/* tank drive */		int left = dzCorrect(15, -1);
/* tank drive */		int right = dzCorrect(15, 1);
/* tank drive */
/* tank drive */		leftFront.move(left);
/* tank drive */		leftRear.move(left);
/* tank drive */
/* tank drive */		rightFront.move(right);
/* tank drive */		rightRear.move(right);





		pros::delay(20);


	}
}
