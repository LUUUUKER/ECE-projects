#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>

#define MPU6050_ADDRESS 0x68 // MPU6050 device address

// Register addresses
#define MPU6050_RA_ACCEL_XOUT_H 0x3B
#define MPU6050_RA_GYRO_XOUT_H  0x43

void MPU6050_init(void);
void MPU6050_readAccel(int16_t* ax, int16_t* ay, int16_t* az);
void MPU6050_readGyro(int16_t* gx, int16_t* gy, int16_t* gz);

#endif
