int k = 7;
void setup()
{
  pinMode(k, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(k, HIGH);
    delay(100);
    digitalWrite(k, LOW);
    delay(100);
  }
}
void loop()
{

}
