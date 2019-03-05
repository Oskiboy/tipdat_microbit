
#include "gpio.h"
#include "twi.h"
#include "uart.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    uart_init();
    iprintf("UART setup completed\n\r");
    gpio_init();
    iprintf("GPIO setup completed\n\r");
    twi_init();
    iprintf("TWI setup completed\n\r");

    int antall =  1;
    uint8_t* data_buffer = (uint8_t *)malloc(antall*sizeof(uint8_t));
    iprintf("Allocation complete\n\r");

    twi_multi_read(0x1D, 0x0D, antall, data_buffer);
    
    iprintf("Line read\n\r");
    uint8_t data = data_buffer[0];
    free(data_buffer);
    while(1) {
        iprintf("Received: %d\n\r", data);
    }

    return 0;
}

ssize_t _write(int fd, const void* buf, size_t count) {
    char* msg = (char*)(buf);
    for(size_t i = 0; i < count; ++i) {
        uart_send(msg[i]);
    }
    return count;
}