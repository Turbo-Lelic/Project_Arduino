int z = 7;
int x = 8;
int c = 9;
int v = 10;
int b = 11;
int i;
void setup()
{
  pinMode(z, OUTPUT);
  pinMode(x, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(v, OUTPUT);
  pinMode(b, OUTPUT);
  while (i < 6)
  {
    digitalWrite(z, HIGH);
    digitalWrite(x, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(v, HIGH);
    digitalWrite(b, HIGH);
    delay(100);

    digitalWrite(z, LOW);
    digitalWrite(x, LOW);
    digitalWrite(c, LOW);
    digitalWrite(v, LOW);
    digitalWrite(b, LOW);
    delay(100);
    i++;
  }
}
void loop()
{

}
