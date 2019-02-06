#include "main.h"


//preset speeds
#define GYRO_CLIMB_SPEED -127

#define TOP_FLAG_SPEED 127
#define MIDDLE_FLAG_SPEED 80

#define COMBINE_INTAKE_SPEED 80
#define REVERSE_FLIP_SPEED -60

#define LIFT_UP_SPEED 127
#define LIFT_CLR_SPEED -70

#define LEFT -1
#define RIGHT 1
#define FORWARD 1
#define REVERSE -1


/* brake defintions */
#define COAST pros::E_MOTOR_BRAKE_COAST
#define HOLD pros::E_MOTOR_BRAKE_HOLD
#define BRAKE pros::E_MOTOR_BRAKE_BRAKE

/* encoders macros */
#define LENCO leftRear.get_position()
#define RENCO rightRear.get_position()

/* misc macros */


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

/* setup gyros  |- 1 through 8 -| */
#define PORT_GYRO_YAW 1 // A
#define PORT_GYRO_PITCH 8 // H

pros::Controller master(pros::E_CONTROLLER_MASTER);

//gyro
pros::ADIGyro yawGyro (PORT_GYRO_YAW, 0); /* tune variable for accurate 360 turn */ // for turning
pros::ADIGyro rollGyro (PORT_GYRO_PITCH); // for climbing

//double check gear cartriges
//double check gear cartriges
//double check gear cartriges
//double check gear cartriges
pros::Motor leftFront (PORT_DRIVE_LEFT_FRONT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftRear (PORT_DRIVE_LEFT_REAR, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightFront (PORT_DRIVE_RIGHT_FRONT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // reverse
pros::Motor rightRear (PORT_DRIVE_RIGHT_REAR, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // reverse

pros::Motor flyWheel1(PORT_FLYWHEEL1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // reverse
pros::Motor flyWheel2(PORT_FLYWHEEL2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor combine(PORT_COMBINE_FRONT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lift(PORT_COMBINE_FRONT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
