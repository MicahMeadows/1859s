#include "main.h"

//preset speeds
#define TOP_FLAG_SPEED 127
#define MIDDLE_FLAG_SPEED 80

#define COMBINE_INTAKE_SPEED 80
#define REVERSE_FLIP_SPEED 60

#define LIFT_UP_SPEED 127
#define LIFT_CLR_SPEED 70



/* brake defintions */
#define COAST pros::E_MOTOR_BRAKE_COAST
#define HOLD pros::E_MOTOR_BRAKE_HOLD
#define BRAKE pros::E_MOTOR_BRAKE_BRAKE


/* setup drive */
#define PORT_DRIVE_LEFT_FRONT 11
#define PORT_DRIVE_LEFT_REAR 1
#define PORT_DRIVE_RIGHT_FRONT 20
#define PORT_DRIVE_RIGHT_REAR 14


/* setup flywheel */
#define PORT_FLYWHEEL1 15
#define PORT_FLYWHEEL2 4



/* setup intake */
#define PORT_COMBINE_FRONT 10
#define PORT_COMBINE_REAR 6


// setup motors
pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::Motor leftFront(PORT_DRIVE_LEFT_FRONT);
pros::Motor leftRear(PORT_DRIVE_LEFT_REAR);

pros::Motor rightFront(PORT_DRIVE_RIGHT_FRONT);
pros::Motor rightRear(PORT_DRIVE_RIGHT_REAR);

pros::Motor flyWheel1(PORT_FLYWHEEL1);
pros::Motor flyWheel2(PORT_FLYWHEEL2);

pros::Motor combine(PORT_COMBINE_FRONT);
pros::Motor lift(PORT_COMBINE_REAR);
