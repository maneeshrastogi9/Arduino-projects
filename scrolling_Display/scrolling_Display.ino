#include <LiquidCrystal_I2C.h>

int totalColumns = 16;
int totalRows = 2;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
lcd.begin(); 
lcd.backlight(); // use to turn on and turn off LCD back light
}

void loop()
{
lcd.setCursor(0, 0);
lcd.print("Scholars Public");
lcd.setCursor(0,1);
lcd.print("School, Jadla");
delay(2000);
lcd.clear(); 
lcd.setCursor(0, 0);
lcd.print("Welcome To The");
lcd.setCursor(0,1);
lcd.print("Robofest");
delay(2000);
lcd.clear(); 
}
