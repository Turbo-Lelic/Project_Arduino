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
    digitalWrite(c, HIGH);
    delay(100);
    digitalWrite(c, LOW);
    delay(100);

    digitalWrite(x, HIGH);
    delay(100);
    digitalWrite(x, LOW);
    delay(100);

    digitalWrite(v, HIGH);
    delay(100);
    digitalWrite(v, LOW);
    delay(100);

    digitalWrite(z, HIGH);
    delay(100);
    digitalWrite(z, LOW);
    delay(100);

    digitalWrite(b, HIGH);
    delay(100);
    digitalWrite(b, LOW);
    delay(100);
    i++;
  }
}
void loop()
{

}
