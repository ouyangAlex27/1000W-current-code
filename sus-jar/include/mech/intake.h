#pragma once
#include "vex.h"
#include "robot-config.h"

class Intake {

public:
    Intake(vex::motor* intake_m, vex::digital_out* color_sort, vex::optical* color_s);

    ~Intake();

    enum States {
        OFF,
        FORWARD,
        REVERSE,
        LOAD,
        LOAD_LB
    };

    void setState(States state);

    void setColorSort(bool state);

    static int intakeControlWrapper();


private:
    int intakeControl();
    
    int isCorrectColor();

    vex::motor* _intake;
    vex::digital_out* _color_sorter;
    vex::optical* _color_s;
        
    States _state = OFF;

    bool _color_sort;

    bool _loading;
    bool _loaded;
    bool _lb_loaded;
    int _lb_loaded_tick;

    //Color Sort 

    double _startRotation = 0;
    bool _sorted = false;

    static Intake* instance;
    static Intake* colorSortInstance;

};

extern Intake intake;

