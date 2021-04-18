/**
 * @file lab8_template.c
 * @author
 * Template file for CprE 288 Lab 8
 */

#include "Timer.h"
#include "lcd.h"
#include "ping.h"
#include "resetSimulation.h"

// Uncomment or add any include directives that are needed




int main(void) {
	timer_init(); // Must be called before lcd_init(), which uses timer functions
	lcd_init();
	ping_init();

//	resetSimulationBoard();

	// YOUR CODE HERE

	while(1)
	{

      // YOUR CODE HERE
	    timer_waitMillis(1000);
	    //lcd_printf("%f", ping_getDistance());
	    float distance = ping_getDistance();

	    if(distance == -1){
	        lcd_printf("overflow");
	    }
	    else{
	        lcd_printf("%f", distance);
	    }

	}
	return  0;

}
