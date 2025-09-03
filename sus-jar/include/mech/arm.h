#pragma once
#include "vex.h"


class Arm {

public:

  Arm(vex::motor* arm1, vex::motor* arm2, vex::rotation* rot, float kP, float kD);

  ~Arm();

  void resetAngle();
  
  void setAngle(float desiredAngle);

  float getSetAngle();

  static int armControlWrapper();

private:
  int armControl();

  vex::motor* _arm1;
  vex::motor* _arm2;
  vex::rotation* _rot;

  float _desiredAngle;

  float _kP;
  float _kD;

  static Arm* instance;

};
extern Arm arm;