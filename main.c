/*
 * File:   main.c
 * Author: gabriel
 *
 * Created on December 11, 2019, 12:26 PM
 */

#include "config.h"
#include <xc.h>
#include "uart.h"
#define BAUDRATE 9600

void setup() {
    uart_init(BAUDRATE);
    TRISA1 = 1;
}

void main(void) {
    setup();
    for(;;) {
        if (!RA1) {
            uart_send('O');
            uart_send('K');
            uart_send('\r');
            uart_send('\n');
            __delay_ms(300);
        }
    }
    return;
}
