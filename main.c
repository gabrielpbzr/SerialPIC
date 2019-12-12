/*
 * File:   main.c
 * Author: gabriel
 *
 * Created on December 11, 2019, 12:26 PM
 */

#include <xc.h>
#include "uart.h"
#define _XTAL_FREQ 16000000L //Hz
#define BAUDRATE 9600

void setup() {
    uart_init(BAUDRATE);
}

void main(void) {
    setup();
    for(;;) {
        uart_send('O');
        uart_send('K');
        uart_send('\r');
        uart_send('\n');
    }
    return;
}
