int a = 7;
int s = 8;
void setup()
{
  pinMode(a, OUTPUT);
  pinMode(s, OUTPUT);
  Serial.begin(6900);
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(a, HIGH);
    digitalWrite(s, HIGH);
    delay(100);

    digitalWrite(s, LOW);
    digitalWrite(a, LOW);
    delay(100);
  }
}
void loop()
{

}
