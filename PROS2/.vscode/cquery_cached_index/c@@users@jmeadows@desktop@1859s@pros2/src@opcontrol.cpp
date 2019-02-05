#include "main.h"
#include "motorsetup.h"





void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	pros::Motor drive_left(PORT_DRIVE_LEFT_FRONT);
	pros::Motor drive_right(PORT_DRIVE_RIGHT_FRONT);



	while (true) {

		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);


		// sets int right and left to right and left joysticks
		int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

		// sets right drive and left drive to ints right and left which
		// are found above my the joysticks
		drive_left.move(left);
		drive_right.move(right);
		pros::delay(20);


	}
}
