int a = 7;
int s = 8;
int d = 9;
int f = 10;
int g = 11;
void setup()
{
  pinMode(a, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  Serial.begin(6900);
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(a, HIGH);
    digitalWrite(s, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    delay(100);

    digitalWrite(s, LOW);
    digitalWrite(a, LOW);
    digitalWrite(d, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    delay(100);
  }
}
void loop()
{

}
