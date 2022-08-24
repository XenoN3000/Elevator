//
// Created by admin on 8/15/2022.
//

#include <avr/io.h>
#include "lcd.h"
#include "sevenseg.h"
#include "move.h"


int main() {

    Lcd_Init();

    Disp_Wirte_Line1("hello");
    Disp_Wirte_Line2("Wazzup!!!");


    Stream_Data();

    while (1);
    return 0;

}