/*
 * uart.h
 *
 *  Created on: Mar 2, 2021
 *      Author: zijanw
 */

#ifndef UARTH
#define UARTH

#include <stdint.h>
#include <inc/tm4c123gh6pm.h>

// UART1 device initialization for CyBot to PuTTY
void uart_init(void);

// Send a byte over UART1 from CyBot to PuTTY
void uart_sendChar(char data);

// CyBot waits (i.e.blocks) to receive a byte from PuTTY
// returns byte that was received by UART1
char uart_receive(void);

// Send a string over UART1
// Sends each char in the string one at a time
void uart_sendStr(const char *data);


#endif / UARTH */
