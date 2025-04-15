#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "PIC_init.h"
#include "LCD.h"
#include "LCD.c"
#include "Button.h"
#include "Button.c"
/*
 *
 */
void ADC_init()
{
    AD1PCFGbits.PCFG0 = 0;      // set up I/O
    AD1CON2bits.VCFG = 0b000;   // use AVDD (3.3V) and AVSS (0V) as max/min
    AD1CON3bits.ADCS = 2;       // TAD>=75ns (Tcy=62.5ns))
    AD1CON1bits.SSRC = 0b010;   // sample on timer3 events
    AD1CON3bits.SAMC = 0b00001; // at leat 1 auto sample time bit
    AD1CON1bits.FORM = 00;      // data output form---recommanded unsigned int
                           // unsigned:0V=0b0000000000, 3.3V=0b1111111111
                           // signed:  0V=0b1000000000, 3.3v=0b0111111111
    AD1CON1bits.ASAM = 1;
    AD1CON2bits.SMPI = 0b0;
    AD1CON1bits.ADON = 1; // turn on the ADC
    _AD1IF = 0;           // clear Interrupt flag
    _AD1IE = 1;           // enable interrupts

    AD1PCFGbits.PCFG0 = 0;      // set up I/O
    AD1CON2bits.VCFG = 0b000;   // use AVDD (3.3V) and AVSS (0V) as max/min
    AD1CON3bits.ADCS = 2;       // TAD>=75ns (Tcy=62.5ns))
    AD1CON1bits.SSRC = 0b010;   // sample on timer3 events
    AD1CON3bits.SAMC = 0b00001; // at leat 1 auto sample time bit
    AD1CON1bits.FORM = 00;      // data output form---recommanded unsigned int
                           // unsigned:0V=0b0000000000, 3.3V=0b1111111111
                           // signed:  0V=0b1000000000, 3.3v=0b0111111111
    AD1CON1bits.ASAM = 1;
    AD1CON2bits.SMPI = 0b0;
    AD1CON1bits.ADON = 1; // turn on the ADC
    _AD1IF = 0;           // clear Interrupt flag
    _AD1IE = 1;           // enable interrupts
}
#define VALIDZONE 200
void __attribute__((__interrupt__, auto_psv)) _ADC1Interrupt(void)
{
    _AD1IF = 0;
    setX(ADC1BUF0);
}
void __attribute__((__interrupt__, auto_psv)) _ADC2Interrupt(void)
{
    _AD1IF = 0;
    setY(ADC1BUF0);
}
void setX(unsigned long int X)
{
    if (X > (1023 - VALIDZONE))
    {
        move_player_rightward();
    }
    else if (X < VALIDZONE)
    {
        move_player_leftward();
    }
}
void setY(unsigned long int Y)
{
    if (Y > (1023 - VALIDZONE))
    {
        move_player_forward();
    }
    else if (Y < VALIDZONE)
    {
        move_player_backward();
    }
}
