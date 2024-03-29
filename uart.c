#include "uart.h"

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
void uart_send_string(const char* str) {
    while(!TXIF) {
        // Wait for last transmission finish
    }
    //Put data on TXREG register to send
    while(*str)
        uart_send((unsigned char)*str++);
}
//==============================================================================
unsigned char uart_read(void) {
    /* 
     * If we have an overrun error, reset CREN register 
     * in order to clear OERR bit
     */
    if (OERR) {
        CREN = 0;
        CREN = 1;
    }
    
    while(!RCIF) {
        //Wait for reception 
    }
    // Read data from register RCREG
    unsigned char data = RCREG;
    
    return data;
}
//==============================================================================