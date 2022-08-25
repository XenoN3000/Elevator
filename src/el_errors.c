//
// Created by admin on 8/25/2022.
//

#include "el_errors.h"


uint8_t RUN = 0;

int Error_check(int status){

    uint8_t str_null[] = {""};

    uint8_t flag = 0;

    switch (status) {
        case Normal:

            break;
        case Revsion:

            if (INPUTS[FTO] == false)
                flag= 2;
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
            else if (INPUTS[CFC] != RUN )
                flag = 11;
            else if (INPUTS[T68] == false != RUN)
                flag = 10;

            if (!flag){
                Disp_String((char *)str_null);
                return 1;
            }
            break;
    }

    return 0;
}