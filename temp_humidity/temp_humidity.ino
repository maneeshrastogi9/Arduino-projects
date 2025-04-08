//by Druhi Chakraborty
#include "DHT.h"
#define DHTPIN 4// you  can use 
#define DHTTYPE DHT11//#define DHTTYPE DHT21
                     //#define  DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);//you can also use pins 3, 4, 5, 12, 13  or 14
   // Pin 15 can work but DHT must be disconnected during program upload
#include  <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int data;

void setup() {
  pinMode(6,INPUT);
  pinMode(7,OUTPUT);
  dht.begin();// initialize the sensor
 lcd.backlight();// turn on lcd backlight
  lcd.init();// initialize lcd
}
void loop() {
  rain();
 lcd.clear();
   lcd.setCursor(0,0);//  set the cursor on the first row and column
   lcd.print("Humidity=");
   lcd.print((float)dht.readHumidity());//print  the humidity
   lcd.print("%");
   lcd.setCursor(0,1);//set the cursor on  the second row and first column
   lcd.print("Temp=");
   lcd.print((float)dht.readTemperature());//print  the temperature
   lcd.print("Celsius");
   delay(2000);
   lcd.clear();
}
void rain()
{
  data=digitalRead(6);
  if(data==0)
  {
    digitalWrite(7,HIGH);
    delay(100);
  }
  else
  {
    digitalWrite(7,LOW);
  }
}
