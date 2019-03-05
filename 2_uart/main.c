#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "gpio.h"

void light_led() {
    GPIO->DIRSET = ((1 << 13) | (1 << 4));
    GPIO->OUTSET = (1 << 13);
    GPIO->OUTCLR = (1 << 4);
}


int main(void) {
   uart_init();
   gpio_init();
   iprintf("Norway has %d counties\n\r", 18);
   //uart_send('A');
   //light_led();
   
   char msg = 'X';
   while(1) {
        uart_send(msg);
        msg = uart_read();
        //If the button is low, send an A
        if(gpio_read_btn(BUTTON_A_PIN)) {
            uart_send('A');
        }
        if(gpio_read_btn(BUTTON_B_PIN)) {
            uart_send('B');
        }
        if(msg != '\0') {
            light_led();
        }
        //uart_send('\n');
   }
}

ssize_t _write(int fd, const void* buf, size_t count) {
    char* msg = (char*)(buf);
    for(size_t i = 0; i < count; ++i) {
        uart_send(msg[i]);
    }
    return count;
}