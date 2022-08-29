//
// Created by admin on 8/16/2022.
//

#include "io_updator.h"

void InputUpdate() {

    DDRD = 0x00;
    PORTD = 0xFF;

    DDRE |= 0b00110000;
    DDRG |= 0b00001001;


    for (int i = 0; i < INPUT_ARRAY_SIZE; ++i)
        INPUTS[i] = false;

    uint8_t counter = 0;
    PORTE &= ~(_BV(p5));
    _delay_ms(5);
    Input_Reg_Update(PIND, &counter);
    PORTE |= _BV(p5) ;

    PORTE &= ~(_BV(p4)) ;
    _delay_ms(5);
    Input_Reg_Update(PIND, &counter);
    PORTE |= _BV(p4);

    PORTG &= ~(_BV(p3));
    _delay_ms(5);
    Input_Reg_Update(PIND, &counter);
    PORTG |= _BV(p3);

    PORTG &= ~(_BV(p0));
    _delay_ms(5);
    Input_Reg_Update(PIND, &counter);
    PORTG |= 0b00001001;

    Input_Reg_Update(PINB, &counter);

}

void OutputUpdate() {

    DDRE |= (HIGH << p7) | (HIGH << p6);  //bit 6 , 7
    DDRG |= (HIGH << p4) | (HIGH << p2)| (HIGH << p1);   // bit 1,2,4

    DDRC = OUTPUT;
    PORTC = 0x00;

    uint8_t counter = 0;

    Output_Reg_Update(&PORTC, &counter);

    PORTE |= _BV(p6) ;
    _delay_ms(20);
    PORTE &= ~(_BV(p6));

    PORTC = 0x00;
    Output_Reg_Update(&PORTC, &counter);

    PORTE |= _BV(p7);
    _delay_ms(20);
    PORTE &= ~(_BV(p7));

    PORTC = 0x00;
    Output_Reg_Update(&PORTC, &counter);

    PORTG |= _BV(p1);
    _delay_ms(20);
    PORTG  &= ~(_BV(p1));

    PORTC = 0x00;
    Output_Reg_Update(&PORTC, &counter);

    PORTG |= _BV(p2);
    _delay_ms(20);
    PORTG  &= ~(_BV(p2));

    if (OUTPUTS[32] == false)
        PORTG |= _BV(p4);
    else
        PORTG  &= ~(_BV(p4));
    PORTC = 0x00;
}


void Input_Reg_Update(uint8_t sfr, uint8_t *counter) {

    for (int i = 0; i < 8; ++i) {
        if (bit_is_clear(sfr, i))
            INPUTS[*counter] = HIGH;
        (*counter)++;
    }
}


void Output_Reg_Update(volatile uint8_t *sfr, uint8_t* counter){
    for (int i = 0; i < 8; ++i) {
        if (OUTPUTS[*counter] == LOW)
            *sfr |= _BV(i);
        else *sfr &= ~(_BV(i));
        (*counter)++;

    }
}
