#include "ppi.h"
#include "gpiote.h"
#include "gpio.h"

int ppi_init() {
    //Sets PPI channel 0 event input, button A to PA13
    PPI->PPI_CH[0].EEP = (uint32_t)&GPIOTE->IN[0];
    PPI->PPI_CH[0].TEP = (uint32_t)&GPIOTE->OUT[1];
    //Sets PPI channel 1 to connect the button to PA14
    PPI->PPI_CH[1].EEP = (uint32_t)&GPIOTE->IN[0];
    PPI->PPI_CH[1].TEP = (uint32_t)&GPIOTE->OUT[2];
    //Sets ppi channel 2 so it connects button A to PA15
    PPI->PPI_CH[2].EEP = (uint32_t)&GPIOTE->IN[0];
    PPI->PPI_CH[2].TEP = (uint32_t)&GPIOTE->OUT[3];

    //Enable the channels we are using 
    PPI->CHEN = (0b111 << 0);
    return 0;
}