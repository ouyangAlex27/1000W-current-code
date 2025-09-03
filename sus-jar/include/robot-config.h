#pragma once
using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor dt_lf;
extern motor dt_lm;
extern motor dt_lt;
extern motor dt_rf;
extern motor dt_rm;
extern motor dt_rt;


extern motor main_intake;
extern motor basket_gate;
extern motor back_intake;
extern motor top_intake;
extern controller Controller1;
extern smartdrive Drivetrain;

extern digital_out lilwill_mech;
extern digital_out basket_redirect;
extern digital_out Wing_L;
extern digital_out Wing_R;

extern limit auto_selector;



void  vexcodeInit( void );