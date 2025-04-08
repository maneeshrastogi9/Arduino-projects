int d_red =10;
int d_yellow =9;
int d_green =8;
int r_red =4;
int r_yellow =3;
int r_green =2;
int l_red =13;
int l_yellow =12;
int l_green =11;
int u_red =7;
int u_yellow =6;
int u_green =5;
void setup()
{
pinMode(d_red, OUTPUT);
pinMode(d_yellow, OUTPUT);
pinMode(d_green, OUTPUT);
pinMode(r_red, OUTPUT);
pinMode(r_yellow, OUTPUT);
pinMode(r_green, OUTPUT);
pinMode(l_red, OUTPUT);
pinMode(l_yellow, OUTPUT);
pinMode(l_green, OUTPUT);
pinMode(u_red, OUTPUT);
pinMode(u_yellow, OUTPUT);
pinMode(u_green, OUTPUT);
}
void loop()
{
changeLights();
}
void changeLights()
{
//Start (all yellow)
digitalWrite(u_red,LOW);
digitalWrite(d_red,LOW);
digitalWrite(r_red,LOW);
digitalWrite(l_green,LOW);
digitalWrite(u_yellow,HIGH);
digitalWrite(d_yellow,HIGH);
digitalWrite(r_yellow,HIGH);
digitalWrite(l_yellow,HIGH);
delay(5000);

//upper lane go
digitalWrite(u_yellow,LOW);
digitalWrite(d_yellow,LOW);
digitalWrite(r_yellow,LOW);
digitalWrite(l_yellow,LOW);
digitalWrite(u_green,HIGH);
digitalWrite(r_red,HIGH);
digitalWrite(l_red,HIGH);
digitalWrite(d_red,HIGH);
delay(10000);

//ALL YELLOW
digitalWrite(u_yellow,HIGH);
digitalWrite(d_yellow,HIGH);
digitalWrite(r_yellow,HIGH);
digitalWrite(l_yellow,HIGH);
digitalWrite(u_green,LOW);
digitalWrite(r_red,LOW);
digitalWrite(l_red,LOW);
digitalWrite(d_red,LOW);
delay(5000);

//RIGHT LANE GO
digitalWrite(u_yellow,LOW);
digitalWrite(d_yellow,LOW);
digitalWrite(r_yellow,LOW);
digitalWrite(l_yellow,LOW);
digitalWrite(u_red,HIGH);
digitalWrite(l_red,HIGH);
digitalWrite(d_red,HIGH);
digitalWrite(r_green,HIGH);
delay(10000);

//ALL YELLOW ON
digitalWrite(u_yellow,HIGH);
digitalWrite(d_yellow,HIGH);
digitalWrite(r_yellow,HIGH);
digitalWrite(l_yellow,HIGH);
digitalWrite(u_red,LOW);
digitalWrite(l_red,LOW);
digitalWrite(d_red,LOW);
digitalWrite(r_green,LOW);
delay(5000);

//DOWN LANE GO
digitalWrite(u_yellow,LOW);
digitalWrite(d_yellow,LOW);
digitalWrite(r_yellow,LOW);
digitalWrite(l_yellow,LOW);
digitalWrite(u_red,HIGH);
digitalWrite(l_red,HIGH);
digitalWrite(r_red,HIGH);
digitalWrite(d_green,HIGH);
delay(10000);

//ALL YELLOW
digitalWrite(u_yellow,HIGH);
digitalWrite(d_yellow,HIGH);
digitalWrite(r_yellow,HIGH);
digitalWrite(l_yellow,HIGH);
digitalWrite(u_red,LOW);
digitalWrite(l_red,LOW);
digitalWrite(r_red,LOW);
digitalWrite(d_green,LOW);
delay(5000);

//LEFT LANE GO
digitalWrite(u_yellow,LOW);
digitalWrite(d_yellow,LOW);
digitalWrite(r_yellow,LOW);
digitalWrite(l_yellow,LOW);
digitalWrite(u_red,HIGH);
digitalWrite(d_red,HIGH);
digitalWrite(r_red,HIGH);
digitalWrite(l_green,HIGH);
delay(10000);

}
