#include "main.h"
#include<cmath>
#include<string>
#include<cstdlib>

#include "v5setup.h"
#include "../functions/dzCorrect.cpp"

void opcontrol() {

	while (true)
	{//sets ints for right and left motor based on dead zone correction function
		int left = dzCorrect(15, -1);
		int right = dzCorrect(15, 1);
		leftFront.move(left);
		leftRear.move(left);
		rightFront.move(right);
		rightRear.move(right);


		/* ----------------------------------------------------------------------------TEL FLYWHEEL------------- */
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			// flip these 2 if flywheel spins backwards
			flyWheel1.move(TOP_FLAG_SPEED);
			flyWheel2.move(-TOP_FLAG_SPEED);
			combine.move(COMBINE_INTAKE_SPEED);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			flyWheel1.move(TOP_FLAG_SPEED);
			flyWheel2.move(-TOP_FLAG_SPEED);
			combine.move(-REVERSE_FLIP_SPEED);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
				flyWheel1.move(MIDDLE_FLAG_SPEED);
				flyWheel2.move(-MIDDLE_FLAG_SPEED);
		}



		/* ---------------------------------------------------------------------TEL COMBINE----------------*/
		if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
				combine.move(0);
		}


		/* -----------------------------------------------------------------------TEL LIFT---------------------*/
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			lift.move(LIFT_UP_SPEED);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			lift.move(-LIFT_CLR_SPEED);
		}
		else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			lift.move(0);
		}

	// save brain cells
 	pros::delay(20);
	}
}
