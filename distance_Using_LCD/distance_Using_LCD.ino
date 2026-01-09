#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address 0x27, 20 columns, 4 rows
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Ultrasonic pins
#define TRIGGER_PIN 12
#define ECHO_PIN 11

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Map the Distance");
  Serial.println("Map the Distance");

  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("By _______"); // Your name
  delay(2000);
  lcd.clear();
}

void loop() {
  // Clear LCD
  lcd.clear();

  // Trigger ultrasonic pulse
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Read echo pulse
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2; // cm

  // Serial output
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LCD output (cm)
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  // LCD output (meter)
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance / 100.0);
  lcd.print(" m");

  delay(1000);
}
