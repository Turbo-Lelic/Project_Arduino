int buzzPin = 5;
void setup()
{
pinMode(A1, INPUT);
pinMode(buzzPin,OUTPUT);
}
void loop()
{
int k = analogRead(A1);
Serial.println(k);
if(k<100)
{
digitalWrite(buzzPin,HIGH);
}
else
{
digitalWrite(buzzPin,LOW);
}
}
