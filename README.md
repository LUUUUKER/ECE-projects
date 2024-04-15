# ECE484 Midterm project(Accelerometer & Gyroscope)
Chip: MPU6050
## Decription
The MPU6050 is the world’s first integrated 6-axis MotionTracking device that combines a 3-axis gyroscope, 3-axis accelerometer, and a Digital Motion Processor™ (DMP) all in a small 4x4x0.9mm package. With its dedicated I2C sensor bus, it directly accepts inputs from an external 3-axis compass to provide a complete 9-axis MotionFusion™ output. The MPU6050 MotionTracking device, with its 6-axis integration, on-board MotionFusion™, and run-time calibration firmware, enables manufacturers to eliminate the costly and complex selection, qualification, and system level integration of discrete devices, guaranteeing optimal motion performance for consumers. The MPU6050 is also designed to interface with multiple non-inertial digital sensors, such as pressure sensors, on its auxiliary I2C port. The MPU6050 is footprint compatible with the MPU30X0 family.The MPU6050 features three 16-bit analog-to-digital converters (ADCs) for digitizing the gyroscope outputs and three 16-bit ADCs for digitizing the accelerometer outputs. For precision tracking of both fast and slow motions, the parts feature a user-programmable gyroscope full-scale range of ±250, ±500, ±1000, and ±2000°/sec (dps) and a user-programmable accelerometer full-scale range of ±2g, ±4g, ±8g, and ±16g.

In this project, I write 2 basic libraries to make Arduino UNO interact with MPU6050. I also combined LCD with them so user can see the reading from the MPU6050. The first line of LCD shows the acceleration in x, y, z axis. The unit is g which is the 9.8 N/kg. The second line fo the LCD shows the angular velocities along x, y, and z axis. The unit is degree per second. The hard part of this project for me is the I2C protocol. Since Arduino IDE is banned for this project, writing a low level I2C protocol is necessary. 

## Component
1. Arduino Uno
2. MPU6050
3. LCD HD44780 1602
4. Jump wires

## Installation
Download the zipFile please

## Video Demo
Youtube: https://www.youtube.com/watch?v=7QYZnegSVAo

## Reference & Resources
Slides: https://docs.google.com/presentation/d/1W7_b7yiPFOzYnwR1C36TRPJxo-sYwA21u_TXf4WfGSA/edit?usp=sharing

## Report & Reflection
Although there are a lot of libraries for MPU 6050, most of them in for C++ and very complex. I learned that adapt C++ to C in embedded system is important.

## Issue & Future update
1. change to a bigger LCD so it can show more info.


