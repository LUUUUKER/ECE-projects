#include "MPU6050.h"
#include "I2C.h"

void MPU6050_init(void) {
    I2C_start();
    I2C_write(MPU6050_ADDRESS << 1);
    I2C_write(0x6B); // PWR_MGMT_1 register
    I2C_write(0x00); // Set to zero (wakes up the MPU-6050)
    I2C_stop();
}

void MPU6050_readAccel(int16_t* ax, int16_t* ay, int16_t* az) {
    uint8_t buffer[6];
    I2C_start();
    I2C_write(MPU6050_ADDRESS << 1);
    I2C_write(MPU6050_RA_ACCEL_XOUT_H);
    I2C_start();
    I2C_write((MPU6050_ADDRESS << 1) | 1);
    for (int i = 0; i < 5; i++) {
        buffer[i] = I2C_read(true);
    }
    buffer[5] = I2C_read(false);
    I2C_stop();

    *ax = (buffer[0] << 8) | buffer[1];
    *ay = (buffer[2] << 8) | buffer[3];
    *az = (buffer[4] << 8) | buffer[5];
}

void MPU6050_readGyro(int16_t* gx, int16_t* gy, int16_t* gz) {
    uint8_t buffer[6];
    I2C_start();
    I2C_write(MPU6050_ADDRESS << 1);
    I2C_write(MPU6050_RA_GYRO_XOUT_H);
    I2C_start();
    I2C_write((MPU6050_ADDRESS << 1) | 1);
    for (int i = 0; i < 5; i++) {
        buffer[i] = I2C_read(true);
    }
    buffer[5] = I2C_read(false);
    I2C_stop();

    *gx = (buffer[0] << 8) | buffer[1];
    *gy = (buffer[2] << 8) | buffer[3];
    *gz = (buffer[4] << 8) | buffer[5];
}
