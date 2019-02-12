#include <stdint.h>

#define GPIO ((NRF_GPIO_REGS*)0x50000000)
#define GPIO_INPUT_MASK ((1 << 0) | (0b111 << 17 )) 
#define BUTTON_A_MASK (1 << 17)
#define BUTTON_B_MASK (1 << 26)

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t RESERVED1[121];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;

typedef enum{
    OFF = 0,
    ON = 1
}state_t;

void set_led(uint16_t row, uint16_t col, state_t state) {
    if(state == ON) {
        GPIO->OUTSET = (1 << (row + 4)); 
        GPIO->OUTCLR = (1 << (col + 13));
    } else {
        GPIO->OUTCLR = (1 << (col + 13));
    }
}


int main() {
    // Configure LED Matrix
    // GPIO->DIRSET = (0b111111111111 << 4)
    for(int i = 4; i <= 15; i++){
	GPIO->DIRSET |= (1 << i);
	GPIO->OUTCLR = (1 << i);
    }

    // Configure buttons
    GPIO->PIN_CNF[26] = GPIO_INPUT_MASK;  //pin 26 
    GPIO->PIN_CNF[17] = GPIO_INPUT_MASK;   //pin 17 
    int sleep = 0;
    while(1){
        /* Check if button B is pressed;
            * turn on LED matrix if it is. */
        if(GPIO->IN & ~(BUTTON_B_MASK)) {
            for(int i = 0; i < 9; i++) {
                for(int j = 0; i < 3; j++) {
                    set_led(i, j, ON);
                }
            }
        }

        /* Check if button A is pressed;

	* turn off LED matrix if it is. */
        if(GPIO->IN & ~(BUTTON_A_MASK)) {
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 3; j++) {
                    set_led(i, j, OFF);
                }
            }
        }
	sleep = 10000;
	while(--sleep);
    }
    return 0;
}
