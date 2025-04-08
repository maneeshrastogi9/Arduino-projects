#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Maximum distance we want to measure (in centimeters).
#define MAX_DISTANCE 200
#define LCD_WIDTH 16 // Width of the LCD display

const int trigPin = 9;
const int echoPin = 10;
const int speakerPin = 8;
long duration;
int distance;
int distance1;

void setup() 
{
  lcd.init(); // Initializes the interface to the LCD screen
  lcd.backlight();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() 
{
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  distance = duration * 0.034 / 2;
  distance1 = 180 - distance;
  
  // Activate buzzer if height is greater than 100 cm
  if (distance1 > 100) {
    tone(speakerPin, 1000);
  } else {
    noTone(speakerPin);
  }
  
  // Display height on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HEIGHT: ");
  lcd.print(distance1);
  lcd.print(" cm  ");
  
  // Draws bar graph on the second line of the LCD
  lcd.setCursor(0, 1);
  int barLength = map(distance1, 0, MAX_DISTANCE, 0, LCD_WIDTH);
  for (int i = 0; i < barLength; i++) {
    lcd.print("|");
  }
  
  delay(500);
}
