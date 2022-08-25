#ifndef ELDEFS_H
#define ELDEFS_H

#include <stdbool.h>
#include <avr/io.h>

#define INPUT_ARRAY_SIZE    39
#define OUTPUT_ARRAY_SIZE   33
#define ERR_MESSAGE_LEN     17


_Bool INPUTS[INPUT_ARRAY_SIZE];
_Bool OUTPUTS[OUTPUT_ARRAY_SIZE];


enum Output_Array_Indexs {
    RDO = 8,
    RDC,
    UP,
    DOWN,
    FAST,
    SLOW,
    H1,
    H2,
    H3,
    H4,
    H5,
    H6,
    H7,
    H8,
    C1,
    C2,
    C3,
    C4,
    C5,
    C6,
    C7,
    C8,


};

enum Input_Array_Indexs {

    OVL = 0,
    FTO,
    INS,
    CAN,
    CA1,
    CFS,
    FDR,
    FCP,
    DO,
    DC,
    RVD,
    RVU,
    REV,
    FIR,
    SPR_2,
    SPR_1,
    TP4 = 32,
    CFC,
    T69,
    T68,
    SLF,
    LEF,
    T66

};


enum Mode {
    Revision,
    Normal
};

#endif