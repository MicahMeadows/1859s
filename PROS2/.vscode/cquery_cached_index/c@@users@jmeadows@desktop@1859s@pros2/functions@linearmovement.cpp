#include "main.h"
#include "v5setup.h"
#include<cmath>
#include<string>
#include<cstdlib>

void line(int target, float factor)
{
  //
  // set all motors to coast here
  //

  float kP = .25;
  float kI = .0005;
  float kD = 1;

  float errorZone = target * 1;

  float error, errorTot, errorLast;
  float pTerm, iTerm, dTerm;
  float power;

  //
  // set rotation of hein encoders to zero
  //

  while(abs(LENCO) < target) // left encoder  < target
  {
    error = target - std::abs(LENCO);
   // errorTot += error;

    if (error < errorZone) {
     errorTot += error;
    } else {
     errorTot = 0;
    }


    pTerm = error * kP;


    iTerm = kI * errorTot;
    dTerm = kD * (error - errorLast);
    errorLast = error;

    power = (pTerm + iTerm + dTerm) * factor;

    leftFront.move(power);
    leftRear.move(power);
    rightFront.move(power);
    leftRear.move(power);

  //  leftFront.spin(dir, power, PCT);
  //  RightMotor.spin(dir, power , PCT);
  //  LeftMotorR.spin(dir, power, PCT);
  //  RightMotorR.spin(dir, power , PCT);
    pros::Task::delay(20);

   // Brain.Screen.clearScreen();
   // Brain.Screen.printAt(1, 40, "ERROR: %f", error);
   // Brain.Screen.printAt(1, 100, "power %f", power);
    }
    RightMotor.stop();
        RightMotor.setStopping(vex::brakeType::brake);


    LeftMotor.stop();
        LeftMotor.setStopping(vex::brakeType::brake);


    RightMotorR.stop();
        RightMotorR.setStopping(vex::brakeType::brake);


    LeftMotorR.stop();
        LeftMotorR.setStopping(vex::brakeType::brake);



    REST(100);
    RightMotor.setStopping(vex::brakeType::coast);
    LeftMotorR.setStopping(vex::brakeType::coast);
    RightMotorR.setStopping(vex::brakeType::coast);
    LeftMotor.setStopping(vex::brakeType::coast);
    LeftMotor.setRotation(0, vex::rotationUnits::deg);
    RightMotor.setRotation(0, vex::rotationUnits::deg);
    LeftMotorR.setRotation(0, vex::rotationUnits::deg);
    RightMotorR.setRotation(0, vex::rotationUnits::deg);
  }
}
