int x = A0;
int q = 7;
int w = 8;
int e = 9;
int r = 10;
int t = 11;
int y;
void setup()
{
  Serial.begin(9600);
  pinMode(q, OUTPUT);
  pinMode(w, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(t, OUTPUT);
}
void loop()
{
  y = analogRead(x);
  Serial.println(y);
  if (y == 200)
  {
    digitalWrite(t, HIGH);
    delay(y);
    digitalWrite(t, LOW);
    delay(y);
  }
  else if (y == 400)
  {
    digitalWrite(r, HIGH);
    delay(y);
    digitalWrite(r, LOW);
    delay(y);
  }
  else if (y == 600)
  {
    digitalWrite(e, HIGH);
    delay(y);
    digitalWrite(e, LOW);
    delay(y);
  }
  else if (y == 800)
  {
    digitalWrite(w, HIGH);
    delay(y);
    digitalWrite(w, LOW);
    delay(y);
  }
  else if (y == 900)
  {
    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);
  }
}
