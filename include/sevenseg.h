#ifndef SEVENSEG_H
#define SEVENSEG_H

#include <avr/io.h>
#include <util/delay.h>
#include "bitutility.h"


#define SVS_PORT    PORTC
#define SVS_PIN        PINC
#define SVS_DDR        DDRC

#define SVG_SIZE        14

typedef enum SEV_SEG_MUX_ {

    sv_zero = 0b00000011,
    sv_one = 0b10011111,
    sv_two = 0b00100101,
    sv_three = 0b00001101,
    sv_four = 0b10011001,
    sv_five = 0b01001001,
    sv_six = 0b01000001,
    sv_seven = 0b00011111,
    sv_eight = 0b00000001,
    sv_nine = 0b00001001,
    sv_G = 0b01000011,
    sv_r = 0b11110101,
    sv_R = 0b01110011,
    sv_P = 0b00110001,

} SEV_SEG_MUX;

typedef enum SEV_SEG_NUM_ {

    Zero = 0,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    G,
    r,
    R,
    P,

} SEV_SEG_NUM;


SEV_SEG_MUX *Default_SVGArray;


typedef struct SevenSegData {
    SEV_SEG_MUX *SEVENSEG_ARRAY;
    SEV_SEG_NUM Number;

} SV_Data;

#ifndef SVG_CURRENT
#define SVG_CURRENT(SV_DATA) (SV_DATA).SEVENSEG_ARRAY[(SV_DATA).Number]
#endif

void SVG_Init();

void SVG_Increment();

void SVG_Decrement();

void SVG_Out(SEV_SEG_MUX);

void Stream_Data();

void SVGIncrementOut();

void SVGDecrementOut();

#endif


