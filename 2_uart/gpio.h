#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>

#define GPIO ((NRF_GPIO_REG*)0x50000000)

#define BUTTON_A_PIN (26)
#define BUTTON_B_PIN (17)

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t RESERVED1[120];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REG;

void gpio_init();
uint32_t gpio_read_btn(uint32_t button_pin);

#endif
