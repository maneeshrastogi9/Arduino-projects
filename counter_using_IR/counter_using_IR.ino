#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address, columns, rows
const int sensor1Pin = 2;  // Pin for the first IR sensor
const int sensor2Pin = 3;  // Pin for the second IR sensor
const int led1Pin = 4;     // Pin for the first LED
const int led2Pin = 5;     // Pin for the second LED

int objectCount = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();  // Initialize the LCD
  lcd.backlight();
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT );

  lcd.setCursor(0, 0);
  lcd.print("Object Counter");
}

void loop() {
  int sensor1Value = digitalRead(sensor1Pin);
  int sensor2Value = digitalRead(sensor2Pin);

  if (sensor1Value == HIGH && sensor2Value == LOW) {
    // Object entering the counting area
    objectCount++;
    displayCount();
    
  } else if (sensor1Value == LOW && sensor2Value == HIGH) {
    // Object leaving the counting area
    objectCount--;
    displayCount();
  }
}

void displayCount() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Car Count: ");
  lcd.print(objectCount);

  Serial.println("Object Count: " + String(objectCount));

  // Visual feedback using LEDs
  if (objectCount > 0) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
  } else if (objectCount < 0) {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
  } else {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
  }

  delay(1000);  // Adjust delay based on your requirements
}
