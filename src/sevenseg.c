#include "sevenseg.h"


SV_Data SVData;

SEV_SEG_MUX a[] ={sv_zero, sv_one, sv_two, sv_three,
                  sv_four, sv_five, sv_six, sv_seven,
                  sv_eight, sv_nine, sv_G, sv_r,
                  sv_R, sv_P};

void SVG_Init() {

    Default_SVGArray =  a ;

    SVData = (SV_Data) {Default_SVGArray, Zero};

    DDRA |= _BV(p1);       // turn on mumerator 7seg
    PORTA &= ~(_BV(p1));
    DDRC = OUTPUT;
    DDRE |= (HIGH << p7) | (HIGH << p6);  //bit 6 , 7
    DDRG |= (HIGH << p4) | (HIGH << p2)| (HIGH << p1);   // bit 1,2,4


}


void SVG_Increment() {

    SEV_SEG_NUM *number = &SVData.Number;

    if (*number >= SVG_SIZE) {
        return;
    }

    *number += 1;

}


void SVG_Decrement() {

    SEV_SEG_NUM *number = &SVData.Number;

    if (*number <= 0) {
        return;
    }

    *number -= 1;

}


void SVG_Out(SEV_SEG_MUX c) {

    SVS_PORT = c;
    _delay_ms(20);
    PORTE |= _BV(p6);
    _delay_ms(10);
    PORTE &= ~(_BV(p6));
}


void SVGIncrementOut(){

    SVG_Increment();
    SVG_Out(SVG_CURRENT(SVData));

}


void SVGDecrementOut(){

    SVG_Decrement();
    SVG_Out(SVG_CURRENT(SVData));

}



void Stream_Data() {

    SVG_Init();

    while (1) {

        SVData.Number = Zero;

        for (uint8_t i = 0; i < SVG_SIZE; i++) {
            SVG_Out(SVG_CURRENT(SVData));
            SVG_Increment();
            _delay_ms(1000);
        }

    }
}

