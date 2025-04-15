#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#include "LCD.h"

/*
 *
 */
#define BOUNDARY_X 8
#define BOUNDARY_Y 7
#define BOUNDARY_WIDTH 10
#define CELLSIZE 30
#define ErrorPOS 100
#define START 0
#define END_COL 1
#define END_ROW 1
#define BOXSIZE 2

#define FILLCORLOR 0xFFFF
#define BOUNDARYCOLOR 0x0000
#define ENDCOLOR 0xABCD
#define PLAYERCOLOR 0x1234
#define SYS_COL 1
#define SYS_ROW 1
void __attribute__((__interrupt__, __auto_psv__)) _SPI1Interrupt(void);

void lcd_screen_fill()
{
    for (int i = 0; i < BOUNDARY_X; i++)
    {
        for (int j = 0; j < BOUNDARY_Y; j++)
        {
            set_cursor(i, j);
            lcd_cmd(FILLCORLOR); // floor
            if ((i > 0 && i <= BOUNDARY_WIDTH) || (i >= (240 - BOUNDARY_WIDTH)) || (i > 0 && i <= BOUNDARY_WIDTH) || (i >= (210 - BOUNDARY_WIDTH)))
            {
                set_cursor(i, j);
                lcd_cmd(BOUNDARYCOLOR);
            }
        }
    }
}
void lcd_cmd();
void set_cursor(int column, int row);
void lcd_print();
int valid_move(int column, int row)
{
    if (column <= BOUNDARY_WIDTH || column >= 210 - BOUNDARY_WIDTH || row <= BOUNDARY_WIDTH || row >= 240 - BOUNDARY_WIDTH)
    {
        return 0;
    }
    if (column) // if the player step into the position that the box has
        return 1;
}
void win(int column, int row)
{
    if (column > END_COL && column < END_COL + CELLSIZE && row > END_ROW && row < END_ROW + CELLSIZE)
    {
        set_cursor(SYS_COL, SYS_ROW)
            print_str("CONGRADULATION!");
    }
}
void print_str(char str[]);

void lcd_cmd(char command)
{
    LATBbits.LATB5 = 1;
    _MI2C1IF = 0;
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN && !_MI2C1IF)
        ;

    _MI2C1IF = 0;
    I2C1TRN = 0b01111000;
    while (_TRSTAT && !_MI2C1IF)
        ;

    _MI2C1IF = 0;
    I2C1TRN = 0x00;
    while (_TRSTAT && !_MI2C1IF)
        ;

    _MI2C1IF = 0;
    I2C1TRN = command;
    while (_TRSTAT && !_MI2C1IF)
        ;

    _MI2C1IF = 0;
    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN && !_MI2C1IF)
        ;

    LATAbits.LATA4 = 0;
}
void lcd_init(void)
{
    // the /RST is conencted to RB6
    TRISBbits.TRISB6 = 0;
    LATBbits.LATB6 = 0;
    delay();
    LATBbits.LATB6 = 1;
    delay();
}

void lcd_printChar(char myChar)
{
    LATBbits.LATB5 = 1;
    _MI2C1IF = 0;
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN && !_MI2C1IF)
        ;

    _MI2C1IF = 0;
    I2C1TRN = 0b01111000;
    while (_TRSTAT && !_MI2C1IF)
        ;

    _MI2C1IF = 0;
    I2C1TRN = 0x40;
    while (_TRSTAT && !_MI2C1IF)
        ;

    _MI2C1IF = 0;
    I2C1TRN = myChar;
    while (_TRSTAT && !_MI2C1IF)
        ;

    _MI2C1IF = 0;
    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN && !_MI2C1IF)
        ;

    LATBbits.LATB5 = 0;
}