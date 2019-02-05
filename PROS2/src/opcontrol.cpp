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


if(Controller.ButtonL1.pressing() && !Controller.ButtonR2.pressing())
    {
				// flip these 2 if flywheel spins backwards
				flyWheel1.move(-127);
				flyWheel2.move(127);
				combine.move(70);


			// vcs ref
      //  flyWheel.spin(FORWARD, 100, vex::velocityUnits::pct);
      //  flyWheel2.spin(FORWARD, 100, vex::velocityUnits::pct);
      //  combineFront.spin(FORWARD, 70, vex::velocityUnits::pct);
    }
    else if(Controller.ButtonL2.pressing())
    {
        flyWheel.spin(FORWARD, 100, vex::velocityUnits::pct);
        flyWheel2.spin(FORWARD, 100, vex::velocityUnits::pct);
        combineFront.spin(REVERSE, 50, vex::velocityUnits::pct);
    }
    else if(Controller.ButtonR2.pressing())
    {

        flyWheel.spin(FORWARD, 85, vex::velocityUnits::pct);
        flyWheel2.spin(FORWARD, 85, vex::velocityUnits::pct);
        combineFront.spin(FORWARD, 70, vex::velocityUnits::pct);
    }
    else if(!Controller.ButtonR2.pressing() && !Controller.ButtonL2.pressing() && !Controller.ButtonL1.pressing())
    {
        flyWheel.stop();
        flyWheel2.stop();
    }



    // stop the front combine if none of the buttons are held
    if(!Controller.ButtonLeft.pressing() && !Controller.ButtonL1.pressing() && !Controller.ButtonL2.pressing() && !Controller.ButtonR2.pressing())
    {
        combineFront.stop();
    }

    // lift lift
    if(Controller.ButtonR1.pressing())
    {
        combineBack.spin(FORWARD, 100, vex::velocityUnits::pct);
    }
    else if(Controller.ButtonA.pressing())
    {
        combineBack.spin(REVERSE, 70, vex::velocityUnits::pct);
    }
    // stop back combine
    else if(!Controller.ButtonR1.pressing() && !Controller.ButtonA.pressing())
    {
        combineBack.stop();
    }



		pros::delay(20);


	}
}
