///**
// * lab6_template.c
// *
// * Template file for CprE 288 Lab 6
// *
// * @author Diane Rover, 2/15/2020
// *
// */
//
//#include "Timer.h"
//#include "lcd.h"
//#include "cyBot_Scan.h"  // For scan sensors
//#include "uart.h"
//
//// Uncomment or add any include directives that are needed
//#include "open_interface.h"
//#include "movement.h"
//#include "button.h"
//#include "uart.h"
//
////#warning "Possible unimplemented functions"
//#define REPLACEME 0
//
//int main(void)
//{
//    timer_init(); // Must be called before lcd_init(), which uses timer functions
//    lcd_init();
//    uart_init();
//    cyBOT_init_Scan();
//
//    // YOUR CODE HERE
//    cyBOT_Scan_t getScan;
//    char c[50];
//
//
//
//    int j = 0;
//    char data;
//
//    data = uart_receive();
//    if (data == 'g')
//    {
//        uart_sendChar('\r');
//        uart_sendStr("Angle \t PING distance \t IR raw value");
//        while (j <= 180 && data != 's'){
//        data = uart_receive_nonblocking();
//
//        cyBOT_Scan(j, &getScan);
//        sprintf(c, "\n \r %i \t %f \t %i \n \r", j, getScan.sound_dist,
//                getScan.IR_raw_val);
//        uart_sendStr(c);
//
//         j +=5;
//
//        }
//    }
//
//
//
//}
