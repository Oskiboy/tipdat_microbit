#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main() {
    //Initialize hardware
    gpio_init();
    gpiote_init();
    ppi_init();

    //All operations should be handled by hardware
    while(1)
        ;
    return 0;
}