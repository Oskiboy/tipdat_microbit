#include <uart.h>


uart_status_t   uart_send(char c){
    while (!UART->TXDRDY)
        ;
    UART->TXD = c;
    UART->TXDRDY = 0;
}