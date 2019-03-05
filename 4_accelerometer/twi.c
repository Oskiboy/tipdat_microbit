#include "twi.h"
#include <stdio.h>

void twi_init() {
    TWIO->PSELSCL = SCL_PIN;
    TWIO->PSELSDA = SDA_PIN;
    TWIO->FREQUENCY = 0x01980000;
    TWIO->ENABLE = 5;
}

void twi_multi_read(uint8_t slave_address,
                    uint8_t start_register, 
                    int registers_to_read, 
                    uint8_t* data_buffer) {
    iprintf("Transmission started\n\r");
    TWIO->ADDRESS = slave_address;
    TWIO->STARTTX = 1;
    TWIO->TXDSENT = 0;
    TWIO->TXD = start_register;
    while(!TWIO->TXDSENT);
    
    TWIO->RXDREADY = 0;
    TWIO->STARTRX = 1;
    for (int i = 0; i < registers_to_read; i++){
        while(!TWIO->RXDREADY)
            iprintf("RXD NOT READY!\n\r");
        
        if(i == (registers_to_read - 1)){
            TWIO->STOP = 1;
        }
        data_buffer[i] = TWIO->RXD;
        TWIO->RXDREADY = 0;
    } 
    iprintf("Transmission finished\n\r");
}