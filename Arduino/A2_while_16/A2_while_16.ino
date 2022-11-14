int a = 7;
int i;
void setup()
{
  pinMode(a, OUTPUT);
  while (i < 6)
  {
    digitalWrite(a, HIGH);
    delay(100);
    digitalWrite(a, LOW);
    delay(100);
    i++;
  }
}
void loop()
{

}
