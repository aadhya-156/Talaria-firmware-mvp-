# Talaria: IMU-Based Wearable for Toe-Walking Gait Correction

Embedded Arduino C++ firmware for the Talaria bench prototype MVP.

## Overview
Talaria is an independent wearable device designed to detect and correct idiopathic toe-walking (plantarflexion) in children using real-time IMU sensing and biofeedback.

## Technical Summary
- **Hardware:** Arduino Uno (Bench MVP) / MPU-6050 6-axis IMU / 5V Buzzer
- **Protocol:** Direct register I2C communication (`Wire.h`)
- **Signal Processing:** Fuses accelerometer pitch (`atan2`) and gyroscope angular velocity using a Complementary Filter (0.96 Gyro / 0.04 Accel, dt = 0.02s)
- **Threshold Condition:** Drives pin 3 HIGH when calculated ankle angle drops below -30 degrees.

## Author
Aadhya Mehta
