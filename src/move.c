#include "move.h"



void Stop(){
    OUTPUTS[UP] = false;
    OUTPUTS[DOWN] = false;
    OUTPUTS[FAST] = false;
    OUTPUTS[SLOW] = false;
    if (!INPUTS[LEF]) OUTPUTS[RDC] = false;
}

void Rev_Up() {

    if (INPUTS[CAN] == false)
        return;

    OUTPUTS[RDC] = true;

    if (INPUTS[RVU] && INPUTS[CAN] == true) {
        OUTPUTS[SLOW] = true;
        OUTPUTS[UP] = true;
    }

}


