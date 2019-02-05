#include "main.h"
#include "motorsetup.h"





void opcontrol() {




	while (true) {

		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);


		// sets int right and left to right and left joysticks
		int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

		// sets right drive and left drive to ints right and left which
		// are found above my the joysticks
		drive_leftFront.move(left);
		drive_leftRear.move(left);

		drive_rightFront.move(right);
		drive_rightRear.move(right);
		
		pros::delay(20);


	}
}
