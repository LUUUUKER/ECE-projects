#ifndef I2C_H
#define I2C_H

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

void I2C_init(uint32_t scl_freq);
void I2C_start(void);
void I2C_stop(void);
bool I2C_write(uint8_t data);
uint8_t I2C_read(bool ack);

#endif
