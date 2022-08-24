//
// Created by admin on 8/16/2022.
//

#ifndef IO_UPDATOR_H
#define IO_UPDATOR_H

#include <avr/io.h>
#include <util/delay.h>
#include "eldefs.h"
#include "bitutility.h"


void InputUpdate();

void OutputUpdate();

void Input_Reg_Update(uint8_t sfr, uint8_t *counter);

void Output_Reg_Update(volatile uint8_t *sfr, uint8_t *counter);

#endif //IO_UPDATOR_H
