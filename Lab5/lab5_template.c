/**
 * lab5_template.c
 *
 * Template file for CprE 288 Lab 5
 *
 * @author Zhao Zhang, Chad Nelson, Zachary Glanz
 * @date 08/14/2016
 *
 * @author Phillip Jones, updated 6/4/2019
 * @author Diane Rover, updated 2/25/2021
 */

#include "button.h"
#include "timer.h"
#include "lcd.h"

#include "cyBot_uart.h"  // Functions for communicating between CyBot and Putty (via UART1)
                         // PuTTy: Baud=115200, 8 data bits, No Flow Control, No Parity, COM1

#include "cyBot_FindObjects.h"  // Scan the CyBot sensors to find objects

#include "uart.h"

#define REPLACEME 0

#define BIT0        0x01
#define BIT1        0x02
#define BIT2        0x04
#define BIT3        0x08
#define BIT4        0x10
#define BIT5        0x20
#define BIT6        0x40
#define BIT7        0x80


int main(void) {
    button_init();
    timer_init(); // Must be called before lcd_init(), which uses timer functions
    lcd_init();

    uart_init();
   // cyBot_uart_init();  // initialize the cyBot UART1 before trying to use it

    cyBot_uart_init_clean();  // Clean UART initialization, before running your UART GPIO init code

    // Complete this code for configuring the GPIO PORTB part of UART1 initialization (your UART GPIO init code)
    SYSCTL_RCGCGPIO_R |= BIT1;
    while ((SYSCTL_PRGPIO_R & BIT1) == 0) {};

    GPIO_PORTB_DEN_R |= 0b00000011;
    GPIO_PORTB_AFSEL_R |= 0b00000011;
    GPIO_PORTB_PCTL_R &= ~0x00000011;     // Force 0's in the desired locations      - page 688
    GPIO_PORTB_PCTL_R |= 0x00000011;     // Force 1's in the desired locations       - page 1351
         // Or see the notes for a coding alternative to assign a value to the PCTL field

   // cyBot_uart_init_last_half();  // Complete the UART device configuration

    while(1)
    {
        char string[75];
        int i = 0;
        char data;

        while(i <= 20){
            data = (char)uart_receive();
            if(i == 20){
                string[20] = '\0';
                lcd_printf("%s", string);

                uart_sendChar('\n');
                uart_sendChar('\r');
                uart_sendChar(string);
                uart_sendChar('\n');
                uart_sendChar('\r');

                i = 0;
            }

            else if(data == '\r'){
                string[i] = '\0';
                lcd_printf("%s", string);

                uart_sendChar(string);
                uart_sendChar('\n');
                uart_sendChar('\r');

                i = 0;
            }

            else if(data != '\r'){
                string[i] = data;

                uart_sendChar(data);
                lcd_printf("%c", data);

                i++;
            }
        }
    }
}
