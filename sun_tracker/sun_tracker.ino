#include <Servo.h>

Servo solarServo;

const int ldrPin1 = A0;  // LDR 1 connected to analog pin A0
const int ldrPin2 = A1;  // LDR 2 connected to analog pin A1
int threshold = 100;    // Adjust this threshold based on ambient light conditions

void setup() {
  solarServo.attach(9);  // Attach servo to digital pin 9
}

void loop() {
  int ldrValue1 = analogRead(ldrPin1);
  int ldrValue2 = analogRead(ldrPin2);

  // If one LDR has significantly more light, move the solar panel towards that direction
  if (ldrValue1 > threshold && ldrValue2 < threshold) {
    moveSolarPanel(10);  // Angle to move towards LDR 1
  } else if (ldrValue2 > threshold && ldrValue1 < threshold) {
    moveSolarPanel(170);  // Angle to move towards LDR 2
  }

  delay(1000);  // Adjust delay based on your preferences
}

void moveSolarPanel(int angle) {
  solarServo.write(angle);
  delay(500);  // Adjust delay based on the speed of your servomotor
}
