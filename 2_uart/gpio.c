#include "gpio.h"

void gpio_init() {
    GPIO->PIN_CNF[BUTTON_A_PIN] = 0;
    GPIO->PIN_CNF[BUTTON_B_PIN] = 0;

}

uint32_t gpio_read_btn(uint32_t button_pin) {
    return ~(GPIO->IN & (1 << button_pin));
}

