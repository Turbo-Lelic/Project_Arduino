int z = 7;
int x = 8;
int c = 9;
int v = 10;
int b = 11;
int i;
int p;
int l;
int m;
int n;
void setup()
{
  pinMode(z, OUTPUT);
  pinMode(x, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(v, OUTPUT);
  pinMode(b, OUTPUT);
  while (n < 6)
  {
    digitalWrite(b, HIGH);
    delay(100);
    digitalWrite(b, LOW);
    delay(100);
    n++;
  }
  while (l < 6)
  {
    digitalWrite(c, HIGH);
    delay(100);
    digitalWrite(c, LOW);
    delay(100);
    l++;
  }
  while (i < 6)
  {
    digitalWrite(z, HIGH);
    delay(100);
    digitalWrite(z, LOW);
    delay(100);
    i++;
  }
  while (p < 6)
  {
    digitalWrite(x, HIGH);
    delay(100);
    digitalWrite(x, LOW);
    delay(100);
    p++;
  }
  while (m < 6)
  {
    digitalWrite(v, HIGH);
    delay(100);
    digitalWrite(v, LOW);
    delay(100);
    m++;
  }
}
void loop()
{

}
