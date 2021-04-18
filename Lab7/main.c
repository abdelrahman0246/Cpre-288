/*
 * main.c
 *
 *  Created on: Mar 23, 2021
 *      Author: bjheinen
 */

#include "adc.h"
#include "timer.h"
#include "lcd.h"
#include "math.h"
#include "uart.h"
#include <stdint.h>
#include <stdbool.h>
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"

int main(void) {
    adc_init();
    timer_init();
    lcd_init();
    uart_init();

    while(1){

        char data[]="";
        int dist;
        int val = 0;


        val = adc_read();

        dist = (155080 * pow(val, -1.215));

        sprintf(data, "Qval = %d \t Dist = %d cm \n\r", val, dist);
        lcd_printf("QVal = %d\nDist = %d cm", val, dist);
        uart_sendStr(data);
        timer_waitMillis(1000);


    }
}
