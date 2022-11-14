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
  Serial.begin(9600);
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(a, HIGH);
    digitalWrite(g, HIGH);
    delay(100);
    digitalWrite(a, LOW);
    digitalWrite(g, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(s, HIGH);
    digitalWrite(f, HIGH);
    delay(100);
    digitalWrite(s, LOW);
    digitalWrite(f, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(d, HIGH);
    delay(100);
    digitalWrite(d, LOW);
    delay(100);
  }
}
void loop()
{

}
