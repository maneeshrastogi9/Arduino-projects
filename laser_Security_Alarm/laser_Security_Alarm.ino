int sensorPin=2;
int sensorValue=0; 

int piezoPin=9; 

void setup() { 

pinMode(sensorPin,INPUT); 

pinMode(7,OUTPUT); 

pinMode(6,OUTPUT); 

pinMode(piezoPin,OUTPUT);  

} 

void loop() { 

sensorValue=digitalRead(sensorPin); 

if(sensorValue==1) 

{

digitalWrite(piezoPin,HIGH); 

digitalWrite(7,HIGH);
delay(500);

}

 else { 

digitalWrite(piezoPin,LOW); 

digitalWrite(7,LOW);
delay(500);

} 

}
