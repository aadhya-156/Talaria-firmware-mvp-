#include <Wire.h>
const int MPU_ADDR = 0x68;
const int BUZZER = 3;
float ankle_angle = 0.0;

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.println("--- Talaria System Bypassed and Online ---");
}

void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);
  int16_t ax = (Wire.read() << 8) | Wire.read();
  int16_t ay = (Wire.read() << 8) | Wire.read();
  int16_t az = (Wire.read() << 8) | Wire.read();
  Wire.read(); Wire.read();
  int16_t gx = (Wire.read() << 8) | Wire.read();
  int16_t gy = (Wire.read() << 8) | Wire.read();
  int16_t gz = (Wire.read() << 8) | Wire.read();
  float gyro_speed = gy / 131.0;
  float accel_angle = atan2(ay, az) * 57.3;
  ankle_angle = 0.96 * (ankle_angle + (gyro_speed * 0.02)) + 0.04 * (accel_angle);
  Serial.println(ankle_angle);
  if (ankle_angle < -30) {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  delay(20);
}
