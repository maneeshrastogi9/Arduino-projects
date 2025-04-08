#include <Wire.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <MotorDriver.h>

MPU6050 mpu6050(Wire);
MotorDriver motorDriver;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  motorDriver.begin();
}

void loop() {
  mpu6050.update();

  // Read accelerometer values
  float accX = mpu6050.getAccX();
  float accY = mpu6050.getAccY();

  // Adjust sensitivity based on your sensor
  int sensitivity = 30;

  // Check for gestures
  if (accY > sensitivity) {
    // Move forward
    motorDriver.forward();
  } else if (accY < -sensitivity) {
    // Move backward
    motorDriver.backward();
  } else if (accX > sensitivity) {
    // Turn right
    motorDriver.right();
  } else if (accX < -sensitivity) {
    // Turn left
    motorDriver.left();
  } else {
    // Stop
    motorDriver.stop();
  }
}
