#include "uart.h"
#include "gpio.h"

uart_status_t uart_init(void) {
    GPIO->DIRSET = (1 << TXD_PIN);
    GPIO->DIRCLR = (1 << RXD_PIN);
    //Set the RXD and TXD pins
    UART->PSELRXD = RXD_PIN;
    UART->PSELTXD = TXD_PIN;
    //Sets the CTS and RTS to disconnectedd
    UART->PSELCTS = 0xFFFFFFFF;
    UART->PSELRTS = 0xFFFFFFFF;
    UART->CONFIG &= ~(0x1);
    //This corresponds to setting baudrate to 9600
    UART->BAUDRATE = 0x00275000;

    UART->ENABLE = 4;
    UART->STARTRX = 1;

    return 0;
}

cuart_t uart_read(void) {
    cuart_t chr = '\0';
    if(!(UART->RXDRDY)) {
        return chr;
    }
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
    return 0;
}
