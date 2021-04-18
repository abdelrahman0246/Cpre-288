/*
 * 9main.c
 *
 *  Created on: Apr 6, 2021
 *      Author: ammannan
 */

#include "Timer.h"
#include "lcd.h"
#include "servo.h"
#include "resetSimulation.h"

int main(void) {

   // resetSimulationBoard();
    timer_init(); // Must be called before lcd_init(), which uses timer functions
    lcd_init();
    servo_init();

    float degrees = 90;
    servo_move(degrees);
//
return 0;
}



