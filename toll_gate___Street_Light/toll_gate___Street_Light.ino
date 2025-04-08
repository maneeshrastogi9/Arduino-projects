#include <Servo.h>
int pushButton = 2;
volatile long A;

Servo servo_3;

Servo servo_6;

Servo servo_9;

const int trigPin = 11;

const int echoPin = 10;

long duration;

int distanceCm, distanceInch;

void setup()
  
{

Serial.begin(9600);
pinMode(pushButton, INPUT);
pinMode(3,OUTPUT);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);
servo_3.attach(3); 

servo_6.attach(6);

servo_9.attach(9);



}

void loop() {

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distanceCm= duration*0.034/2;

distanceInch = duration*0.0133/2;

Serial.println("Distance: ");

Serial.println(distanceCm);

int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);

if (distanceCm < 20) {

A = random(0, 4);
Serial.println(A);

switch (A) {

case 1:

servo_3.write(179);

delay(100);

servo_3.write(90);

delay(500);

break;


case 2:



servo_6.write(179);

delay(100);

servo_6.write(90);

delay(500);

break;

case 3:


servo_9.write(179);

delay(100);

servo_9.write(90);

delay(500);

break;

}

}

}
