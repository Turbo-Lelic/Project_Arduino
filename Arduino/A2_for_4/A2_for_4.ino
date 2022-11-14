int k = 7;
int l = 8;
int j = 9;
int a = 10;
int s = 11;
void setup()
{
  pinMode(k, OUTPUT);
  pinMode(l, OUTPUT);
  pinMode(j, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(s, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(k, HIGH);
    delay(100);
    digitalWrite(k, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(l, HIGH);
    delay(100);
    digitalWrite(l, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(j, HIGH);
    delay(100);
    digitalWrite(j, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(a, HIGH);
    delay(100);
    digitalWrite(a, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(s, HIGH);
    delay(100);
    digitalWrite(s, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(a, HIGH);
    delay(100);
    digitalWrite(a, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(j, HIGH);
    delay(100);
    digitalWrite(j, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(l, HIGH);
    delay(100);
    digitalWrite(l, LOW);
    delay(100);
  }
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
