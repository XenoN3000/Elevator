#include "move.h"


extern char slf;
extern char lef;
extern char door_check;
extern char RUN;
extern char slf_conter;
extern char lef_conter;


void Stop() {
    OUTPUTS[UP] = false;
    OUTPUTS[DOWN] = false;
    OUTPUTS[FAST] = false;
    OUTPUTS[SLOW] = false;
    if (!INPUTS[LEF]) OUTPUTS[RDC] = false;
}


void Fast() {
    OUTPUTS[FAST] = true;
    OUTPUTS[SLOW] = false;
}

void Slow() {
    OUTPUTS[SLOW] = true;
    OUTPUTS[FAST] = false;
}

void Medium() {

    OUTPUTS[SLOW] = true;
    OUTPUTS[FAST] = true;
}

void Up() {
    OUTPUTS[DOWN] = false;
    OUTPUTS[UP] = true;
}

void Down() {
    OUTPUTS[UP] = false;
    OUTPUTS[DOWN] = true;
}


void Rev_Up() {

    if (INPUTS[CAN] == false)
        return;

    OUTPUTS[RDC] = true;

    if (INPUTS[RVU] && Error_check(Revision) == 1 && INPUTS[CAN] == true) {
        Slow();
        Up();
    }

    OutputUpdate();
}


void Rev_Down() {

    if (INPUTS[CA1] == false)
        return;

    OUTPUTS[RDC] = true;

    if (INPUTS[RVU] && INPUTS[CAN] == true) {
        Slow();
        Down();
    }

}


void Start_Move() {

    InputUpdate();
    OutputUpdate();
}

void Speed_Conf() {

}