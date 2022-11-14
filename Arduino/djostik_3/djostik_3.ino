int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int pin8 = 8;
void setup()
{
Serial.begin(9600);
pinMode(pin5,OUTPUT);
pinMode(pin6,OUTPUT);
pinMode(pin7,OUTPUT);
pinMode(pin8,OUTPUT);
}
void loop()
{
int x = analogRead(A1);
int y = analogRead(A2);
Serial.println("Ocd x = " + (String)x);
Serial.println("Ocd y = " + (String)y);
if (x > 495 and x < 1023)
{
int x1 = map(x,495,1023,0,255);
analogWrite(5,x1);
}
if (x > 1 and x < 495)
{
int x2 = map(x,495,1,0,255);
analogWrite(6,x2);
}
if (y > 495 and y < 550)
{
int y1 = map(y,495,550,0,255);
analogWrite(7,y1);
}
if (y < 495)
{
int y2 = map(y,495,1,0,255);
analogWrite(8,y2);
}
}
