#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();
void odom_constants();

void red_sig_awp();
void blue_sig_awp();
void blue_neg_quals();
void red_pos();

void blue_rush();

void red_neg();
void blue_neg();

void odom_test();
void tank_odom_test();

void sus_solo_regional_awp_blue();
void sus_solo_regional_awp_red();