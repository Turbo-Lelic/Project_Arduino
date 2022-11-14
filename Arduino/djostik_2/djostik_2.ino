int btn = 10;
int x = A1;
int y = A2;
int led = 5;
void setup()
{
delay(100);
Serial.begin(9600);
digitalWrite(led,LOW);
pinMode(led,OUTPUT);
pinMode(x,INPUT);
digitalWrite(x,HIGH);
pinMode(y,INPUT);
digitalWrite(y,HIGH);
pinMode(btn,INPUT);
digitalWrite(btn,HIGH);
}
void loop()
{
int led_state = analogRead(btn);
delay(100);
if (led_state == 0)
{
digitalWrite(led,HIGH);
}
else
{
digitalWrite(led,LOW);
}
int dx = analogRead(x);
int dy = analogRead(y);
delay(100);
Serial.print(dx);
Serial.print("/t");
Serial.println(dy);
}
