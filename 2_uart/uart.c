#include "uart.h"
#include "gpio.h"

uart_status_t uart_init(void) {
    //Set the RXD and TXD pins
    UART->PSELRXD = RXD_PIN;
    UART->PSELTXD = TXD_PIN;
    //Sets the CTS and RTS to disconnectedd
    UART->PSELCTS = 0xFFFFFFFF;
    UART->PSELRTS = 0xFFFFFFFF;
    //This corresponds to setting baudrate to 9600
    UART->BAUDRATE = 0x00275000;

    UART->ENABLE = 4;
    UART->STARTRX = 1;

    return 0;
}

uart_status_t uart_send(char c) {
     
}

cuart_t uart_read(void) {
    cuart_t chr = '\0';
    UART->RXDRDY = 0;
    chr = UART->RXD;
    return UART_READ_ERROR;
}


uart_status_t   uart_send(char c){
    while (!UART->TXDRDY)
        ;
    UART->TXD = c;
    UART->TXDRDY = 0;
}