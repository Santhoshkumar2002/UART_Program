/*
 * File:   main.c
 * Author: santhoshkumar R
 * Title: UART Program -->(send data from MCU to PC and receive data from PC)
 *
 * Created on December 30, 2023, 11:33 AM
 */


#include <xc.h>
#include "uart.h"

char text[] = "Finance Minister Arun Jaitley Tuesday hit out at former RBI governor Raghuram Rajan for predicting that the next banking crisis would be triggered by MSME lending, saying postmortem is easier than taking action when it was required. Rajan, who had as the chief economist at IMF warned of impending financial crisis of 2008, in a note to a parliamentary committee warned against ambitious credit targets and loan waivers, saying that they could be the sources of next banking crisis. Government should focus on sources of the next crisis, not just the last one.\n\r";

void main(void) {
    init_uart();
    
    unsigned int start_time, end_time, time_taken;
    unsigned long int total_bits_transmitted = 0;
    unsigned char data;
    for (int i = 0; i < 1000; ++i) {
        // Write data to EEPROM
        write_internal_eeprom(text[i], 0x00+i);
        
    }
    //Record start time
    //start_time = sec; //assume timer0 is using
    
    for(int i = 0; i < 1000; i++)
    {
        data = read_internal_eeprom(0x00+i);
        putch(data);
        total_bits_transmitted += 8;
    }
    
    //Record end time
    //end_time = sec; //assume timer0 is using

    // Calculate time taken for data transmission in microseconds
    time_taken = end_time - start_time;

 
    float speed_bps = (float)total_bits_transmitted / (float)time_taken * (8000000/ 1000000);
    
    while(1);
    return;
}
