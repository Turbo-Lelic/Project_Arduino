int x = A0;
int q = 7;
int y;
void setup()
{
  Serial.begin(9600);
  pinMode(q, OUTPUT);
  pinMode(x, INPUT);
}
void loop()
{
  y = analogRead(x);
  Serial.println(y);
  if (y == 200)
  {
    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);

    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);

    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);

    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);

    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);
  }
}
