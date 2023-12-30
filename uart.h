/* 
 * File:   uart.h
 * Author: santhoshkumar R
 *
 * Created on December 30, 2023, 11:40 AM
 */

#ifndef UART_H
#define	UART_H

void init_uart();
void putch(unsigned char data);
void puts(char *data);
unsigned char getch();
unsigned char getche();
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

