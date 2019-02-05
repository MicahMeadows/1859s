#include "main.h"
#include "v5setup.h"

void gyro_climb(int speed, int ang, int delay, int calibrateDelay = 0)
{
    rightRear.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    leftRear.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);


    bool climbed = false;

    bool overcame = false;
    float overcomeAng = 10;
    float zeroAng = 5;

    // calibrate
    pros::delay(calibrateDelay);

    while(!climbed)
    {
        if(!overcame)
        {
            while(std::abs(rollGyro.get_value()) < ang)
            {
              leftFront.move(GYRO_CLIMB_SPEED);
              leftRear.move(GYRO_CLIMB_SPEED);
              rightFront.move(GYRO_CLIMB_SPEED);
              rightRear.move(GYRO_CLIMB_SPEED);

            }
            overcame = true;
            while(std::abs(rollGyro.get_value()) > zeroAng)
            {
              leftFront.move(GYRO_CLIMB_SPEED);
              leftRear.move(GYRO_CLIMB_SPEED);
              rightFront.move(GYRO_CLIMB_SPEED);
              rightRear.move(GYRO_CLIMB_SPEED);

            }

            pros::delay(delay);

            climbed = true;

            rightRear.move(0);
            leftRear.move(0);
            rightRear.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            leftRear.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

            rightFront.move(0);
            leftFront.move(0);
            rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            leftRear.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        }
    }
}
