#include "gpio.h"
#include "twi.h"

int gpio_init() {
    // Sets all the GND pins as outputs PA 4..12
    GPIO->DIRCLR = (1 << SDA_PIN) | (1 << SCL_PIN);
    GPIO->PIN_CNF[SDA_PIN] |= (0b110 << 8);
    GPIO->PIN_CNF[SCL_PIN] |= (0b110 << 8);
    return 0;
}