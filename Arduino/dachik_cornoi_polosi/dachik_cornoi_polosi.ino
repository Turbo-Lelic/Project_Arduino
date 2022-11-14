int buzzPin = 10;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(buzzPin, OUTPUT);
}
void loop()
{
  int k = analogRead(A0);
  Serial.println(k);
  if (k > 600)
  {
    digitalWrite(buzzPin, HIGH);
  }
  else
  {
    digitalWrite(buzzPin, LOW);
  }
}
