int g = 7;
int h = 8;
int i;
void setup()
{
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  while (i < 6)
  {
    digitalWrite(g, HIGH);
    digitalWrite(h, HIGH);
    delay(100);

    digitalWrite(h, LOW);
    digitalWrite(g, LOW);
    delay(100);
    i++;
  }
}
void loop()
{

}
