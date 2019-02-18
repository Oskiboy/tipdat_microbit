#include <stdint.h>
#include "uart.h"
#include "gpio.h"

void light_led() {
    GPIO->DIRSET = ((1 << 13) | (1 << 4));
    GPIO->OUTSET = (1 << 13);
    GPIO->OUTCLR = (1 << 4);
}


int main(void) {
   uart_init(); 
   char msg = 'X';
   while(1) {
        msg = uart_read();
        uart_send(msg);
        //uart_send('\n');
   }
}
