#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

Servo myservo;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};  //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2};//connect to the column pinouts of the keypad
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String password = "1234";
String mypassword;
int counter = 0; 
int attempts = 0; 
int max_attempts = 3; 
void setup(){
  Serial.begin(9600);
  myservo.attach(10);
  lcd.begin();
 // lcd.init();
  lcd.backlight();
  Serial.println("enter password");
  lcd.print("Enter Password:");
}

void loop()
{
  myservo.write(0);
 keypadfunction();
}
void keypadfunction()
{
 char key = keypad.getKey();
  if (key)
  {
    Serial.println(key);
    counter = counter + 1; 
    lcd.setCursor(counter, 1);
    lcd.print("*");
  }
  if (key == '1')
  {
    mypassword = mypassword + 1;   
  }
    if (key == '2')
  {
    mypassword = mypassword + 2;  
  }
  
  if (key == '3')
  {
    mypassword = mypassword + 3; 
  }
  
   if (key == '4')
  {
    mypassword = mypassword + 4;  
  }
  if (key == '5')
  {
    mypassword = mypassword + 5;
  }
   if (key == '6')
  {
    mypassword = mypassword + 6; 
  }
  
   if (key == '7')
  {
    mypassword = mypassword + 7; 
  }
   if (key == '8')
  {
    mypassword = mypassword + 8; 
  }
  if (key == '9')
  {
    mypassword = mypassword + 9;
  }       
  if (key == '0')
  {
    mypassword = mypassword + 0; 
  }
  if (key == '*')
  {
    Serial.println(mypassword); 
    if ( password == mypassword )

    
      {
        lcd.clear(); 
        lcd.println("Welcome Back To  ");
        lcd.setCursor(0,1);
        lcd.println("Home                ");
        myservo.write(70);
        delay(10000); 
        mypassword = ""; 
        counter = 0; 
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.println("Enter password :");
        }
      else
      {
        Serial.println("wrong");
        attempts = attempts + 1; 
        if (attempts >= max_attempts )
        {
          lcd.clear();
          lcd.setCursor(0,0); 
          lcd.print("Locked Out");
          delay(50000);
          attempts = 0; 
          }
        mypassword = ""; 
        counter = 0; 
        lcd.clear(); 
        lcd.setCursor(0,0); 
        lcd.print("Wrong Password");
        delay(1000);
        lcd.setCursor(0,1); 
        lcd.print("max attempts 3");
        delay(1000);
        lcd.clear(); 
        lcd.println("Enter password");
        lcd.setCursor(0,1); 
      }
  }  
}
