#include "gpiote.h"

int gpiote_init() {
    //Channel 0 is configured as an event that triggers on
    //falling edges. Configured for pin 17 (Button A)
    GPIOTE->CONFIG[0] = (1 << 0) |
                        (0b10001 << 8) |
                        (0b10 << 16);

    //Channel 1 is an event that toggles. Pin 13
    GPIOTE->CONFIG[1] = (0b11 << 0) |
                        (0b01101 << 8) |
                        (0b11 << 16);

    //Channel 2 is an event that toggles. Pin 14
    GPIOTE->CONFIG[2] = (0b11 << 0) |
                        (0b01110 << 8) |
                        (0b11 << 16);

    //Channel 3 is an event that toggles. Pin 15
    GPIOTE->CONFIG[3] = (0b11 << 0) |
                        (0b01111 << 8) |
                        (0b11 << 16);

    // Enable interrupts
    GPIOTE->INTEN = (1 << 0);
    
    return 0;

}