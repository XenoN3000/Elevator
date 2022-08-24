#ifndef  BITUTILITY_H
#define BITUTILITY_H

#include <avr/sfr_defs.h>

#ifndef MAX_REG_CAP
#define MAX_REG_CAP 7
#endif

#define HIGH                        1
#define LOW                         0

#define SetAllBit(sfr)              sfr = ~(_BV(MAX_REG_CAP + 1))
#define ClearAllBit(sfr)            sfr = 0x00


#define SetBit(sfr, index)          sfr |= (1 << index)
#define CearBit(sfr, index)         sfr &= ~(1 << index)


#define Set_OutPut(sfr_dir)         SetAllBit(sfr_dir)
#define Set_InPut(sfr_dir)          ClearAllBit(sfr_dir)


#define OUTPUT                      ~(0 <<    MAX_REG_CAP)
#define INPUT                       (0    <<    MAX_REG_CAP)


#define SET_BIT(index)              (1 << index)
#define CLEAR_BIT(index)            ~(1 << index)


#define SET_BITS(sfr, index)        (sfr << index)
#define CLEAR_BITS(sfr, index)      ~(sfr << index)



enum Pin_Number {
    p0 = 0,
    p1,
    p2,
    p3,
    p4,
    p5,
    p6,
    p7
};


#endif