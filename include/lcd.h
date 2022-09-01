#ifndef LCD_H
#define LCD_H

#include <avr/io.h>
#include <util/delay.h>
#include "bitutility.h"


//change this Pins to your micro
#define LCD_PORT        PORTF
#define LCD_PIN         PINF
#define LCD_DDR         DDRF


#define rs              p0
#define en              p1
#define LIGHT           p6


void Lcd_Init(void);

void Disp_Command(unsigned char);

#define  Disp_Cmd(a)    Disp_Command(a)


void Disp_Char(char);

void Disp_Clear();

void Disp_String(char *);

void Disp_Wirte_Line1(char *);

void Disp_Wirte_Line2(char *);

void Disp_Locate(int, int);

void Disp_Cursor(int);

#endif