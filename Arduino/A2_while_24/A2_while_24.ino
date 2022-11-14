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
  while (i < 6)
  {
  digitalWrite(z,HIGH);
  digitalWrite(b,HIGH);
  delay(100);
  digitalWrite(z,LOW);
  digitalWrite(b,LOW);
  i++;
  }
}
void loop()
{
  
}
