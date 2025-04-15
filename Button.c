#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "Button.h"

#include "PIC_init.h"
#include "LCD.h"
#include "LCD.c"
#include "Button.c"
/*
 *
 */

void mapToCOmmand()
{
    if (PORTBbits.RB15 == 0)
    {
        move_player_forward();
        move_box_forward();
    }
    else if (PORTBbits.RB14 == 0)
    {
        move_player_backward();
        move_box_backward();
    }
    else if (PORTBbits.RB13 == 0)
    {
        move_player_leftward();
        move_box_leftward();
    }
    else if (PORTBbits.RB12 == 0)
    {
        move_player_rightward();
        move_box_rightward();
    }
}
#define
void move_player_forward()
{
    SPI1BUF =
}
void move_player_backward();
void move_player_leftward();
void move_player_rightward();

void move_box_forward();
void move_box_backward();
void move_box_rightward();
void move_box_leftward();