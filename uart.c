/*
 * File:   uart.c
 * Author: santhoshkumar R
 *
 * Created on December 30, 2023, 11:40 AM
 */


#include <xc.h>
#include "uart.h"

void init_uart()
{
    TRISC6 = 0;
    TRISC7 = 1;
    
    //TXSTA
    TX9 = 0;
    TXEN = 1;
    SENDB = 1;
    SYNC = 0;
    BRGH = 1;
    
    //RCSTA
    SPEN = 1;
    RX9 = 0;
    CREN = 1;
    
    //BUADCON
    BRG16 = 0;
    //SPBRG = 64; //(19.23K)
    SPBRG = 129; //(9.6k)
    
    //GIE = 1;
    //PEIE = 1;
    TXIE = 1;
    RCIE = 1;
    TXIF = 0;
    RCIF = 0;   
}

void putch(unsigned char data)
{
    while(!TXIF);
    TXREG = data;
    TXIF = 0;
}

void puts(char *data)
{
    while(*data)
    {
        putch(*data++);
    }
}

unsigned char getch()
{
    while(!RCIF);
    RCIF = 0;
    return RCREG;
}

unsigned char getche()
{
    char ch;
    while(!RCIF);
    RCIF = 0;
    putch(ch = RCREG);
    return ch;
}
