/**
 * lab6-interrupt_template.c
 *
 * Template file for CprE 288 Lab 6
 *
 * @author Diane Rover, 2/15/2020
 *
 */

#include "Timer.h"
#include "lcd.h"
#include "cyBot_Scan.h"  // For scan sensors
#include "uart-interrupt.h"

// Uncomment or add any include directives that you want to use
#include "open_interface.h"
#include "movement.h"
#include "button.h"

// Your code can use the global variables defined in uart-interrupt.c
// They are declared with the extern qualifier in uart-interrupt.h, which makes the variables visible to this file.

//#warning "Possible unimplemented functions"
#define REPLACEME 0




int main(void)
{
    timer_init(); // Must be called before lcd_init(), which uses timer functions
    lcd_init();
    uart_interrupt_init();
    cyBOT_init_Scan();

    // YOUR CODE HERE
    //assign a value to command_byte if you want to know whether that ASCII code is received
    //note that command_byte is global shared variable read by the ISR
    //for example, try using a tab character as a command from PuTTY

//    cyBOT_Scan_t getScan;
//    char c[50];
//    int j = 0;
//    char data;
//
//   command_byte = 's';
//   //command_flag = 0;
//    data = uart_receive();
//
//    if (data == 'g')
//    {
//        uart_sendChar('\r');
//        uart_sendStr("Angle \t PING distance \t IR raw value");
//        while (j <= 180 && command_flag == 0)
//        {
//
//            cyBOT_Scan(j, &getScan);
//            sprintf(c, "\n \r %i \t %f \t %i \n \r", j, getScan.sound_dist,
//                     getScan.IR_raw_val);
//                   uart_sendStr(c);
//
//                    j +=5;
//
//
//
//                   }
//                      command_flag = 0;
//
//        }
//    }

    while (1)
    {

        // YOUR CODE HERE
        //first, try leaving this loop empty and see what happens
        //then add code for your application
        // OPTIONAL
        //test and reset command_flag if your ISR is updating it
        //for example, if the flag is 1, do something, like send a message to PuTTY or LCD, or stop a sensor scan, etc.
        //be sure to reset command_flag so you don't keep responding to an old flag

//        char string[75];
//        int i = 0;
//        char data;





    }
}


