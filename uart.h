/* 
 * File:   uart.h
 * Author: gabriel
 *
 * Created on December 11, 2019, 12:42 PM
 */

#ifndef UART_H
#define	UART_H

#include <xc.h>
#include "definitions.h"

/**
 * Initialize serial communication
 * @param baudRate
 */
void uart_init(unsigned short baudRate);

/**
 * Send a byte through UART
 * @param byte to send
 */
void uart_send(unsigned char byte);

/**
 * Receive a byte through UART
 * @return byte read
 */
unsigned char uart_read(void);

#endif	/* UART_H */

