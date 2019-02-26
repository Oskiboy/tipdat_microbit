#include "gpio.h"
#include "twi.h"

int gpio_init() {
    // Sets all the GND pins as outputs PA 4..12
    GPIO->DIRSET = (1 << SDA_PIN) | (1 << SCL_PIN);

    return 0;
}