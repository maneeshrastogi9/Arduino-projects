#include <Wire.h>           
 #include <LiquidCrystal_I2C.h>    
 LiquidCrystal_I2C lcd(0x27,16,2);
int Time ;
int distance;
#define max_distance 50

void setup()
{
 pinMode(2,OUTPUT); // trigger 
 pinMode(3,INPUT); // echo 
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 Serial.begin(9600);
  lcd.begin ();
  lcd.backlight();
  lcd.clear();

}

void loop() 
{
 digitalWrite(2,HIGH);
 delayMicroseconds(10);
 digitalWrite(2,LOW);
 delayMicroseconds(5);
 digitalWrite(2,HIGH);
 delayMicroseconds(10);

Time = pulseIn(3,HIGH);

    distance= 0.0343*Time/2;
    Serial.print("distane from sensor to object is =");
    lcd.setCursor(0,0);
    lcd.print("Ocen Depth - ");
    Serial.println(distance);
    lcd.setCursor(1,1);
    lcd.println(distance);
    delay(10);
   

   
   if(distance>5 && distance <= 10 )
   {
   
    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    
    }

   if(distance>15 && distance <= 20 )
   {
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);  
   }


   if(distance>25 && distance <=30)
   {

    digitalWrite(4,LOW);
    digitalWrite(5,LOW); 
    digitalWrite(5,HIGH);   
 
   }

   if(distance>35 && distance <=40)
   {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);    
    
   
   }
 if(distance>45 && distance <=50)
   {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);   
   }
 
    if(distance>300)
   {
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);           
    digitalWrite(8,HIGH);
    
   }
}
