#include "twi.h"

void twi_init() {
    TWIO->PSELSCL = SCL_PIN;
    TWIO->PSELSDA = SDA_PIN;
    TWIO->FREQUENCY = 0x01980000;
    TWIO->ENABLE = 5;
}