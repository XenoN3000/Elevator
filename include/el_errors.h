//
// Created by admin on 8/25/2022.
//

#ifndef EL_ERRORS_H
#define EL_ERRORS_H

#include "avr/io.h"
#include "eldefs.h"
#include "lcd.h"
#include "io_updator.h"

int Error_check(ElevatorMode);

void Show_error(int);

void Flag_check();

#endif //ELEVATOR_EL_ERRORS_H
