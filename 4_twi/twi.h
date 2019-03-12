#ifndef TWI_H
#define TWI_H
#include <stdint.h>

#define SDA_PIN	30
#define SCL_PIN 0

void twi_init();

void twi_multi_read(
		uint8_t slave_address,
		uint8_t start_register,
		int registers_to_read,
		uint8_t * data_buffer
		);

void twi_multi_write(
		uint8_t slave_address,
		uint8_t start_register,
		int registers_to_write,
		uint8_t * data_buffer
		);

#endif
