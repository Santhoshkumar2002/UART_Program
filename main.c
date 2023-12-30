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
void init_config()
{
    init_uart();
    /* Record start time
    uint32_t start_time = _CP0_GET_COUNT();*/
    
    puts(text);
    
    /* Record end time
    uint32_t end_time = _CP0_GET_COUNT();

    // Calculate time taken for data transmission in microseconds
    uint32_t time_taken_us = (end_time - start_time) / (F_CPU / 1000000);

    // Calculate transmission speed in bytes per second
    uint32_t data_size = sizeof(text) - 1;  // Exclude the null terminator
    float speed_bps = (float)data_size / (float)time_taken_us * 1000000.0;*/
    
    puts("press any key\n\r");
    getch();
}
void main(void) {
    init_config();
    
    while(1)
    {
        getche(); //Read data from PC to MCU
        puts("\n\r");
    }
    return;
}
