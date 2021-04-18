///*
// *
// *   uart.c
// *
// *
// *
// *   @author
// *   @date
// */
//
//#include <inc/tm4c123gh6pm.h>
//#include <stdint.h>
//#include "uart.h"
//
//#define BIT0        0x01
//#define BIT1        0x02
//#define BIT2        0x04
//#define BIT3        0x08
//#define BIT4        0x10
//#define BIT5        0x20
//#define BIT6        0x40
//#define BIT7        0x80
//
//void uart_init(void)
//{
//    //TODO
//    //enable clock to GPIO port B
//    SYSCTL_RCGCGPIO_R |= BIT1;
//    SYSCTL_RCGCUART_R |= BIT1;  // enable clock for UART1
//    while ((SYSCTL_PRGPIO_R & 0b0010) == 0)
//    {
//    };
//    while ((SYSCTL_PRUART_R & 0b0010) == 0)
//    {
//    };  // oooo 0000 0001 0000
//
//    GPIO_PORTB_DIR_R |= 0b00000010;     // Enable PORTB PIN1 as output
//    GPIO_PORTB_DIR_R &= ~0b00000001;    // enable PORTB PIN0 as input
//
//    GPIO_PORTB_DEN_R |= 0b00000011;     // enable PORTB PIN0 and PIN1
//    GPIO_PORTB_AFSEL_R |= 0b00000011; // select alternate function for PORTB PIN0 and PIN1
//
//    GPIO_PORTB_PCTL_R &= ~0x00000011;     // Force 0's in the desired locations
//    GPIO_PORTB_PCTL_R |= 0x00000011;     // Force 1's in the desired locations
//
//    // uart config
//    UART1_CTL_R |= 0x0301;      // turn on UART1 receive, transmit and enable
//
//    // calculate baud rate
//    uint16_t iBRD = 8;      // use equations
//    uint16_t fBRD = 44;     // use equations
//
//    // set baud rate
//    // note: to take effect, there must be a write to LCRH after these assignments
//    UART1_IBRD_R = iBRD;
//    UART1_FBRD_R = fBRD;
//
//    // set frame, 8 data bits, 1 stop bit, no parity, no FIFO
//    // note: this write to LCRH must be after the BRD assignments
//    UART1_LCRH_R = 0x60;    // 0x61;
//
//    // use system clock as source
//    // note from the datasheet UARTCCC register description:
//    // field is 0 (system clock) by default on reset
//    // Good to be explicit in your code
//    UART1_CC_R = 0x0;
//
//    // re-enable UART1 and also enable RX, TX (three bits)
//    // note from the datasheet UARTCTL register description:
//    // RX and TX are enabled by default on reset
//    // Good to be explicit in your code
//    UART1_CTL_R |= 0b0100000000000000;
//}
//void uart_sendChar(char data)
//{
//    //TODO
//    while (UART1_FR_R & 0x20)
//    {
//    }
//    UART1_DR_R = data;
//}
//
//char uart_receive(void)
//{
//    char data = 0;
//    //TODO
//    while (UART1_FR_R & 0x10)
//    {
//    }
//    data = (UART1_DR_R & 0x0FF);
//
//    return data;
//
//}
//
//void uart_sendStr(const char *data)
//{
//    //TODO for reference see lcd_puts from lcd.c file
//    while (*data != '\0')
//    {
//        uart_sendChar(*data);
//        data++;
//    }
//}
//char uart_receive_nonblocking(void){
//    char data = 0;
//
//    if (!(UART1_FR_R & 0x10)){}
//        data = (UART1_DR_R & 0x0FF);
//
//        return data;
//}
