int l1 = 2;
int l2 = 3;
int l3 = 4;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
}
void loop()
{
  int df = analogRead(A0);
  if (df >= 5 and df <= 10)
  {
    digitalWrite(l1, HIGH);
    delay(300);
    digitalWrite(l1, LOW);
    delay(300);
  }
  if (df >= 11 and df <= 15)
  {
    digitalWrite(l2, HIGH);
    delay(300);
    digitalWrite(l2, LOW);
    delay(300);
  }
  if (df >= 16 and df <= 20)
  {
    digitalWrite(l3, HIGH);
    delay(300);
    digitalWrite(l3, LOW);
    delay(300);
  }
  if (df >= 21 and df <= 25)
  {
    digitalWrite(l1, HIGH);
    delay(300);
    digitalWrite(l1, LOW);
    delay(300);
    digitalWrite(l2, HIGH);
    delay(300);
    digitalWrite(l2, LOW);
    delay(300);
    digitalWrite(l3, HIGH);
    delay(300);
    digitalWrite(l3, LOW);
    delay(300);
  }
}
