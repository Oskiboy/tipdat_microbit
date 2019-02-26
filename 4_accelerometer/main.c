
#include "gpio.h"
#include "twi.h"
#include <stdint.h>

int main() {
    gpio_init();
    twi_init();
    return 0;
}