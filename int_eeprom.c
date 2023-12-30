/*
 * File:   int_eeprom.c
 * Author: santh
 *
 * Created on December 30, 2023, 12:17 PM
 */


#include <xc.h>

unsigned char read_internal_eeprom(unsigned char addr)
{
    EEADR = addr;
    EEPGD = 0;
    CFGS = 0;
    WREN = 0;
    RD = 1;
    return EEDATA;
}

void write_internal_eeprom(unsigned char data, unsigned char addr)
{
    EEADR = addr; 
    EEDATA = data;
    EEPGD = 0;
    CFGS = 0;
    WREN = 1;
    
    GIE = 0; 
    EECON2 = 0X55;
    EECON2 = 0XAA;
    WR = 1;
    GIE = 1;
    
    while(!EEIF);
    EEIF = 0;
}

