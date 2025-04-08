#define MLa 4 //left motor 1st pin
#define MLb 5 //left motor 2nd pin
#define MRa 6 //right motor 1st pin
#define MRb 7 //right motor 2nd pin
int IR_Left= 2;
int IR_Right= 3;
void setup()
{
pinMode(IR_Left, INPUT); //IR1DO pin
pinMode(IR_Right, INPUT); // IR2 DO pin

pinMode(MLa, OUTPUT); // Motors pins
pinMode(MLb, OUTPUT);
pinMode(MRa, OUTPUT);
pinMode(MRb, OUTPUT);
}
void loop() 
{
if (digitalRead(IR_Left) == HIGH and
digitalRead(IR_Right) == HIGH)
{
// Stop
digitalWrite(MLa, LOW);
digitalWrite(MLb, LOW);
digitalWrite(MRa, LOW);
digitalWrite(MRb, LOW);
}
if (digitalRead(IR_Left) == LOW and
digitalRead(IR_Right) == HIGH)
{
// will move in the left dIRection
digitalWrite(MLa, LOW);
digitalWrite(MLb, LOW);
digitalWrite(MRa, HIGH);
digitalWrite(MRb, LOW);
}
if (digitalRead(IR_Left) == HIGH and
digitalRead(IR_Right) == LOW)
{
// will move in the right dIRection
digitalWrite(MLa, HIGH);
digitalWrite(MLb, LOW);
digitalWrite(MRa, LOW);
digitalWrite(MRb, LOW);
}
if (digitalRead(IR_Left) == LOW and
digitalRead(IR_Right) == LOW)
{
// move in the forward dIRection
digitalWrite(MLa, HIGH);
digitalWrite(MLb, LOW);
digitalWrite(MRa, HIGH);
digitalWrite(MRb, LOW);
}
}
