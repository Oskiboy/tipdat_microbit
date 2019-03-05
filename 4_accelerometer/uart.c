#include "uart.h"
#include "gpio.h"

uart_status_t uart_init(void) {
    //Sets TX an RX to output and input
    GPIO->PIN_CNF[TXD_PIN] = 1;
    GPIO->PIN_CNF[RXD_PIN] = 0;
    //Set the RXD and TXD pins
    UART->PSELRXD = RXD_PIN;
    UART->PSELTXD = TXD_PIN;
    //Sets the CTS and RTS to disconnectedd
    UART->PSELCTS = 0xFFFFFFFF;
    UART->PSELRTS = 0xFFFFFFFF;
    //UART->CONFIG &= ~(0x1);
    //This corresponds to setting baudrate to 9600
    UART->BAUDRATE = 0x00275000;

    UART->ENABLE = 4;
    UART->STARTRX = 1;

    return 0;
}

cuart_t uart_read(void) {
    char chr = '\0';
    //If there is no new message in the buffer, return \0
    if(!(UART->RXDRDY)) {
        return chr;
    }
    //Reset the buffer event and read from the buffer
    UART->RXDRDY = 0;
    chr = UART->RXD;
    return chr;
}

uart_status_t uart_send(char c){
    UART->STARTTX = 1;
    UART->TXD = c;
    while(!UART->TXDRDY)
        ;
    
    UART->STARTTX = 0;
    UART->TXDRDY = 0;
    return 0;
}

uart_status_t uart_write(char* msg, int size) {
    for(int i = 0; i < size; ++i) {
        uart_send(msg[i]);
    }
    return 0;
}

