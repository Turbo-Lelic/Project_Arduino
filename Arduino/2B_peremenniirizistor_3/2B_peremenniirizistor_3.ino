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
    digitalWrite(q, HIGH);
    digitalWrite(t, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(t, LOW);
    delay(y);
  }
  else if (y == 400)
  {
    digitalWrite(w, HIGH);
    digitalWrite(r, HIGH);
    delay(y);
    digitalWrite(w, LOW);
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
}
