#include "vex.h"

#include "mech/arm.h"
#include "mech/intake.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors

controller Controller1 = controller(primary);

motor main_intake = motor(PORT20, ratio18_1, true);
motor basket_gate = motor(PORT11, ratio18_1, true);
motor back_intake = motor(PORT19, ratio18_1, true);
motor top_intake = motor(PORT12, ratio18_1, true);

motor dt_lf = motor(PORT9, ratio6_1, true);
motor dt_lm = motor(PORT8, ratio6_1, true);
motor dt_lt = motor(PORT18, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(dt_lf, dt_lm, dt_lt);
motor dt_rf = motor(PORT4, ratio6_1, false);
motor dt_rm = motor(PORT3, ratio6_1, false);
motor dt_rt = motor(PORT1, ratio6_1, true);
motor_group RightDriveSmart = motor_group(dt_rf, dt_rm, dt_rt);

inertial DrivetrainInertial = inertial(PORT2);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 219.44, 320, 40, mm, 1);


rotation arm_rot = rotation(PORT5, true);

limit auto_selector = limit(Brain.ThreeWirePort.A);
optical color_s = optical(PORT16);

bool is_red_alliance = true;



// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}