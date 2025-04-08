#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the lcd address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define trigPin 12 //Sensor Echo pin connected to Arduino pin 13
#define echoPin 11 //Sensor Trip pin connected to Arduino pin 12

//Simple program just for testing the HC-SR04 Ultrasonic Sensor with lcd dispaly
//URL:

void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.backlight();
lcd.init(); //Tell Arduino to start your 16 column 2 row lcd
lcd.setCursor(0,0); //Set lcd cursor to upper left corner, column 0, row 0
lcd.print("Target Distance:")
; //Print Message on First Row
}

void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

lcd.setCursor(0,1); //Set cursor to first column of second row
lcd.print(" "); //Print blanks to clear the row
lcd.setCursor(0,1); //Set Cursor again to first column of second row
lcd.print(distance); //Print measured distance
lcd.print(" cm"); //Print your units.
delay(250); //pause to let things settle
}
