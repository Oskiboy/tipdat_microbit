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
   while(1) {
        uart_send('X');
        if (uart_read() != '\0') {
            light_led(); 
        }

        light_led();
   }
}
