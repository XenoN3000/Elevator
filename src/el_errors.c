//
// Created by admin on 8/25/2022.
//

#include "el_errors.h"


extern bool slf;
extern bool lef;
extern char door_check;
extern char RUN;
extern char slf_conter;
extern char lef_conter;
extern char ListOfErrors[][ERR_MESSAGE_LEN];


int Error_check(ElevatorMode status) {

    uint8_t str_null[] = {""};

    uint8_t flag = 0;

    switch (status) {
        case Normal:

            break;
        case Revision:

            if (INPUTS[FTO] == false)
                flag = 2;
            else if (INPUTS[FCP] == false)
                flag = 24;
            else if (INPUTS[CA1] == INPUTS[CAN] == false)
                flag = 3;
            else if (INPUTS[FDR] == false)
                flag = 23;
            else if (INPUTS[TP4] == false)
                flag = 6;
            else if (INPUTS[SLF] == INPUTS[LEF] == false)
                flag = 12;
            else if (INPUTS[CFC] != RUN)
                flag = 11;
            else if (INPUTS[T68] == false != RUN)
                flag = 10;

            if (!flag) {
                Disp_String((char *) str_null);
                return 1;
            } else Show_error(flag);

            break;

        default:
            break;
    }

    return 0;
}


void Slf_Lef_Status_Checker(char *SL) {
    if (OUTPUTS[UP])
        (*SL)++;
    else if (OUTPUTS[DOWN] && (*SL) > 1)
        (*SL)--;
}

void Flag_check() {

    Input_Reg_Update(PINB, (uint8_t *) 32);

    if (INPUTS[LEF] == false && lef == true) Slf_Lef_Status_Checker(&lef_conter);
    if (INPUTS[SLF] == false && slf == true) Slf_Lef_Status_Checker(&slf_conter);

    if (INPUTS[CA1] == false) {
        lef_conter = 1;
        slf_conter = 0;
    }

    if (INPUTS[CAN] == false) {
        lef_conter = 4;  // lef_conter = seting[1];
        slf_conter = 8;  // lef_conter = seting[1]* 2;
    }

    slf = INPUTS[SLF];
    lef = INPUTS[LEF];
}

void Show_error(int error_code) {
    Disp_Wirte_Line2(ListOfErrors[error_code]);
    _delay_ms(500);
}


