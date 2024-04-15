#include <stdint.h>
#include <stdio.h>
#include "lib/HD44780.h"
#include "lib/I2C.h"
#include "lib/MPU6050.h"
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

void my_delay_ms( unsigned int delay);

// Constants for unit conversions
#define ACCEL_SENSITIVITY 16384.0  // Sensitivity factor for +/- 2g setting
#define GYRO_SENSITIVITY 131.0     // Sensitivity factor for +/- 250 deg/s setting


int main(void)
{
	LCD_Setup();
	int counter = 0;
	
    // Variables to hold raw sensor data
    char strAx[6], strAy[6], strAz[6];
    char strGx[6], strGy[6], strGz[6];
    int16_t ax, ay, az, gx, gy, gz;
    double ax_g, ay_g, az_g, gx_dps, gy_dps, gz_dps;

	I2C_init(100000); // Initialize I2C at 100kHz
    MPU6050_init(); // Initialize MPU6050

	while(1)
	{
		LCD_Clear();
		uint8_t line;

		// Read acceleration and gyroscope data
        MPU6050_readAccel(&ax, &ay, &az);
        MPU6050_readGyro(&gx, &gy, &gz);

        // Convert raw accelerometer data to g's
        ax_g = ax / ACCEL_SENSITIVITY;
        ay_g = ay / ACCEL_SENSITIVITY;
        az_g = az / ACCEL_SENSITIVITY;

        // Convert raw gyroscope data to degrees per second
        gx_dps = gx / GYRO_SENSITIVITY;
        gy_dps = gy / GYRO_SENSITIVITY;
        gz_dps = gz / GYRO_SENSITIVITY;

        // Format the data to strings with two decimal places and maximum 5 characters
        sprintf(strAx, "%.2f", ax_g);
        sprintf(strAy, "%.2f", ay_g);
        sprintf(strAz, "%.2f", az_g);
        sprintf(strGx, "%.2f", gx_dps);
        sprintf(strGy, "%.2f", gy_dps);
        sprintf(strGz, "%.2f", gz_dps);

		if (counter == 0)
		{
			for (line = 0; line < 2; line++)
			{
				LCD_GotoXY(0, line);
				if (line == 0)
				{
					LCD_PrintString("ECE");
				}
				else 
				{
					LCD_PrintString("484");
				}
			}
			counter = 1;
		}
		else
		{
			for (line = 0; line < 2; line++)
			{
				LCD_GotoXY(0, line);
				if (line == 0)
				{
					LCD_PrintDouble(ax_g, 100);
					LCD_GotoXY(6, line);
					LCD_PrintDouble(ay_g, 100);
					LCD_GotoXY(12, line);
					LCD_PrintDouble(az_g, 100);
				}
				else 
				{
					LCD_PrintDouble(gx_dps, 100);
					LCD_GotoXY(6, line);
					LCD_PrintDouble(gy_dps, 100);
					LCD_GotoXY(12, line);
					LCD_PrintDouble(gz_dps, 100);
				}
			}
			//counter = 0;
		}
		

		my_delay_ms(1000);
	}
	return 0;
}




/* 
 * Handles larger delays the _delay_ms can't do by itself (not sure how accurate)  
 * Note no DBC as this function is used in the DBC !!! 
 *
 * borrowed from : https://www.avrfreaks.net/forum/delayms-problem 
 * */
void my_delay_ms(unsigned int delay) 
{
	int i;

	for (i=0; i<(delay/10); i++) 
	{
		_delay_ms(10);
	}
	if (delay % 10) {
		_delay_ms(1);
	}
}