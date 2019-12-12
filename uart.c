#include "uart.h"
#define _XTAL_FREQ 16000000L
//==============================================================================
void uart_init(unsigned short baudrate) {
    TRISB1 = 0x01; // RX Pin
    TRISB2 = 0x01; // TX Pin
    BRGH = 1; //Asyncronous mode
    CMCON = 0x07; // Turn off comparators
    SPBRG = ((_XTAL_FREQ / 16) / baudrate) - 1;
    
    //1 - Enable USART (TXSTA Register)
    TXEN = 1; // Transmission enabled
    SPEN = 1; // Enable Serial Port
    
    //2 - Enable 8 bit, asynchronous continuous mode (TXSTA Register)
    TX9 = 0;  // 8-bit transmission
    RX9 = 0;  // 8-bit reception
    SYNC = 0; // Asynchronous mode
    CREN = 1; // Enable continuous receive mode (RCSTA Register)
    
    GIE = 1; // Enable Global Interrupts
    PEIE = 1; //Enable Peripheral Interrupts
}
//==============================================================================
void uart_send(unsigned char byte) {
    while(!TXIF) {
        // Wait for last transmission finish
    }
    //Put data on TXREG register to send
    TXREG = byte;

}
//==============================================================================
unsigned char uart_read(void) {
    //TODO Implement
    return 0;
}
//==============================================================================