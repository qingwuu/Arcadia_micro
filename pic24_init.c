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

void __attribute__((__interrupt__, __auto_psv__)) _SPI1Interrupt(void)
{
    int temp;
    _SPI1IF = 0;
    temp = SPI1BUF;
}

void SPI_init(void)
{
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
    RPOR2bits.RP5R = 7;                     // RB5->SPI1:SDO1; See Table 10-3 on P109 of the datasheet
    RPOR2bits.RP4R = 8;                     // RB4->SPI1:SCK1OUT;
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS

    SPI1CON1 = 0;
    SPI1CON1bits.MSTEN = 1;  // master mode
    SPI1CON1bits.MODE16 = 1; // sixteen bits
    SPI1CON1bits.CKE = 1;
    SPI1CON1bits.CKP = 0;
    SPI1CON1bits.SPRE = 0b110; // secondary prescaler = 2
    SPI1CON1bits.PPRE = 0b11;  // primary prescaler = 1;
    // SPI1CON1bits.PPRE = 0b01;  // primary prescaler = 16;
    SPI1CON2 = 0;
    SPI1STAT = 0;
    SPI1STATbits.SISEL = 0b101; // IF set when last bit is shifted out
                                // That means the SPI xfer is complete.
    SPI1STATbits.SPIEN = 1;

    IPC1bits.T2IP = 5;
    IEC0bits.T2IE = 1;
    _SPI1IF = 0;
    _SPI1IE = 1;
}
void timer3_init()
{ // for ADC
    TMR3 = 0;
    T3CON = 0;
    T3CONbits.TCKPS = 0b10;
    PR3 = (1 / K) * 1000000 / (62.5 * 64) T3CONbits.TON = 1;
}

void GPIO_init()
{
    CLKDIVbits.RCDIV = 0;
    // buttons
    TRISBbits.TRISB15 = 0; // push up
    TRISBbits.TRISB14 = 0; // push down
    TRISBbits.TRISB13 = 0; // push left
    TRISBbits.TRISB12 = 0; // push right

    // for lcd, data and command choosing
    TRISBbits.TRISB11 = 1;
    TRISBbits.TRISB10 = 1;
}