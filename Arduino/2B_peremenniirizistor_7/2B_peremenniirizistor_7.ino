int z = A0;
int x = A1;
int q = 7;
int w = 8;
int y;
int g;
void setup()
{
  Serial.begin(6900);
  pinMode(z, INPUT);
  pinMode(x, INPUT);
  pinMode(q, OUTPUT);
  pinMode(w, OUTPUT);
}
void loop()
{
  y = analogRead(z);
  Serial.println(y);
  g = analogRead(x);
  Serial.println(g);
  if (g == 100)
  {
    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);
  }
  if (g == 200)
  {
    digitalWrite(w, HIGH);
    delay(y);
    digitalWrite(w, LOW);
    delay(y);
  }
  if (y == 100)
  {
    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    delay(y);
  }
  if (y == 200)
  {
    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    delay(y);

    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    delay(y);
  }
  if (y == 300)
  {
    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    delay(y);

    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    delay(y);

    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    delay(y);
  }
}
