#include "lcd.h"

void execute_command(unsigned char);

void Disp_data(unsigned char);

void Lcd_Init() {

    _delay_ms(100);
    LCD_DDR = OUTPUT;
    LCD_PORT = SET_BIT(LIGHT);
    Disp_Command(0x02);
    _delay_ms(10);
    Disp_Command(0x28);                                            // 0x28 -> 4 bit Lcd Initializer command  (for 8 bit set it to 0x038)
    _delay_ms(10);
    Disp_Command(0x0C);
    _delay_ms(10);
    Disp_Command(0x06);
    _delay_ms(10);
    Disp_Command(0x83);
    _delay_ms(10);

    LCD_PORT = SET_BITS(0b11, 6);

    _delay_ms(300);

    LCD_PORT = SET_BIT(LIGHT);

}


void Disp_Command(unsigned char cmd) {

    char cmd_temp = cmd & 0xF0;
    execute_command(cmd_temp);
    cmd_temp = ((cmd << 4) & 0xF0);
    execute_command(cmd_temp);


}


void Disp_Char(char data) {

    char data_temp = data & 0xF0;
    Disp_data(data_temp);
    data_temp = ((data << 4) & 0xF0);
    Disp_data(data_temp);

}

void Disp_Clear() {

    Disp_Cmd(0x01);
    _delay_ms(5);
    Disp_Cmd(0x80);
}


void Disp_Locate(int line, int row) {


    Disp_Command((unsigned char) (((8 + (4 * (line - 1))) * 16) + (row - 1)));

//	switch (line)
//	{
//		case 1:
//			Disp_Command(0x80 + (row - 1));
//			
//			break;
//		case 2:
//			Disp_Command(0xC0 + (row - 1));
//			
//			break;
//		default:
//	}

}


void Disp_Cursor(int condition) {

    switch (condition) {
        case 0:
            Disp_Command(0x0C);
            break;
        case 1:
            Disp_Command(0x0F);
            break;
    }

}

void Disp_String(char *str) {

    int i = 0;
    for (i; str[i] != '\0'; i++) {
        Disp_Char(str[i]);
    }
    for (i; i < 16; i++)
        Disp_Char(' ');

}

void Disp_Wirte_Line1(char *str) {
    Disp_Locate(1, 1);
    //Disp_Command(0x80);
    Disp_String(str);
}

void Disp_Wirte_Line2(char *str) {
    Disp_Locate(2, 1);
    //Disp_Command(0xC0);
    Disp_String(str);
}


void execute_command(unsigned char cmd) {

    LCD_PORT = SET_BIT(LIGHT);
    LCD_PORT |= (cmd >> 2);
    LCD_PORT &= CLEAR_BIT(rs);
    LCD_PORT |= SET_BIT(en);
    _delay_ms(1);
    LCD_PORT &= CLEAR_BIT(en);

}

void Disp_data(unsigned char data) {

    LCD_PORT = SET_BIT(LIGHT);
    LCD_PORT |= (data >> 2);
    LCD_PORT |= SET_BIT(rs);
    LCD_PORT |= SET_BIT(en);
    _delay_ms(1);
    LCD_PORT &= CLEAR_BIT(en);

}





