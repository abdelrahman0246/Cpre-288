/*
 * servo.c
 *
 *  Created on: Apr 2, 2021
 *      Author: ammannan
 */

#include "lcd.h"
//#include "uart.h"
///#include "button.h"
//#include "lab5_scan_data.h"
//#include "adc.h"
#include "timer.h"
#include "ping.h"
#include "servo.h"

//unsigned int pulsePeriod = 3200;//201000*16;
//float servoSlope = -23000.0/180.0;

void servo_init(){

    // initialize GPIO
    SYSCTL_RCGCGPIO_R |= 0x2;     //enable Clock on PortB
    GPIO_PORTB_AFSEL_R |= 0x20;   //Set pin 5 to alt function
    GPIO_PORTB_PCTL_R |= 0x700000;//enable GPIO pin 5
    GPIO_PORTB_DIR_R |= 0x20;     //Enable pin 5 output
    GPIO_PORTB_DEN_R |= 0x20;     //pin 5 to digital


    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R1;

    TIMER1_CTL_R &=~0x0100;// disable timer
    TIMER1_CFG_R = 0x4; //set size of timer to 16
    TIMER1_TBILR_R = 320000 & 0xFFFF;
    TIMER1_TBMR_R |= 0x0A;
    TIMER1_TBPR_R = (320000 >> 16) & 0xFF;
    TIMER1_TBMATCHR_R = 0x92B4 & 0xFFFF; //value the timer needs to match before doing an event
    TIMER1_TBPMR_R = 0x04;
    TIMER1_CTL_R |= 0x0100; //enable the timer

}
int servo_move(float degrees){

    //calculate the number the timer needs to match

        int result = 320000 - (7300 + (138 * degrees));

        TIMER1_TBMATCHR_R = result & 0xFFFF;

        TIMER1_TBPMR_R = (result >> 16) & 0xFF;

        return result;
}
