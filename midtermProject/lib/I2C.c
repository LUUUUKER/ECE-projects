#include "I2C.h"

#define F_CPU 16000000UL // Assuming a 16MHz clock, adjust as per your MCU

void I2C_init(uint32_t scl_freq) {
    TWSR = 0x00; // Prescaler set to 1
    TWBR = ((F_CPU / scl_freq) - 16) / 2;
    TWCR = (1 << TWEN); // Enable I2C
}

void I2C_start(void) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void I2C_stop(void) {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

bool I2C_write(uint8_t data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return (TWSR & 0xF8) == 0x28; // Check if ACK received
}

uint8_t I2C_read(bool ack) {
    TWCR = (1 << TWINT) | ((ack ? 1 : 0) << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}
