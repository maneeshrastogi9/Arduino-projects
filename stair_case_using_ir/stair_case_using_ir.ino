
int ir1 = 2;
int ir2 = 3;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(ir1, INPUT);
  pinMode(ir2,INPUT);
  pinMode(5,OUTPUT);
}
void loop() {
  // read the input pin:
  
  int irdata1 = digitalRead(ir1);
  int irdata2 = digitalRead(ir2);

  if(irdata1 == 0 or irdata2 == 0)
  {
    digitalWrite(5,HIGH);
    delay(3000);
  }
  else
  {
    digitalWrite(5,LOW);
    delay(1000);
  }
  
}
