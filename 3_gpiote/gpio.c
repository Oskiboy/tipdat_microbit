#include "gpio.h"

int gpio_init() {
    // Sets all the GND pins as outputs PA 4..12
    GPIO->DIRSET = (0b111111111 << 4);

    return 0;
}