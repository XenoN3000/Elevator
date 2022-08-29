//
// Created by admin on 8/15/2022.
//

#include <avr/io.h>
#include "lcd.h"
#include "sevenseg.h"
#include "move.h"


int main() {

    IO_Init();

    Lcd_Init();
    Disp_Clear();
    Disp_Wirte_Line1("LOADING ... !");
    _delay_ms(3000);

    Disp_Clear();




    INPUTS[CAN] = true;
    INPUTS[RVU] = true;


    Disp_Wirte_Line1("MODE : ");
    Disp_Wirte_Line2("REVISION UP");
    Rev_Up();

   // Stream_Data();

    while (1);
    return 0;

}