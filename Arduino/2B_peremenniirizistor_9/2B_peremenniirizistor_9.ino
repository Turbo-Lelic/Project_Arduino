int x = A0;
int z = A1;
int q = 7;
int w = 8;
int y;
int g;
void setup()
{
  Serial.begin(9600);
  pinMode(q, OUTPUT);
  pinMode(w, OUTPUT);
  pinMode(x,INPUT);
  pinMode(z,INPUT);
}
void loop()
{
  y = analogRead(x);
  Serial.println(y);
  g = analogRead(z);
  Serial.println(g);
  if (y == 200)
  {
    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);
  }
  else if (y == 400)
  {
    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);

    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);
  }
  else if (y == 600)
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
  }
    if (g == 200)
  {
    digitalWrite(w, HIGH);
    delay(g);
    digitalWrite(w, LOW);
    delay(g);
  }
  else if (g == 400)
  {
    digitalWrite(w, HIGH);
    delay(g);
    digitalWrite(w, LOW);
    delay(g);

    digitalWrite(w, HIGH);
    delay(g);
    digitalWrite(w, LOW);
    delay(g);
  }
  else if (g == 600)
  {
    digitalWrite(w, HIGH);
    delay(g);
    digitalWrite(w, LOW);
    delay(g);

    digitalWrite(w, HIGH);
    delay(g);
    digitalWrite(w, LOW);
    delay(g);

    digitalWrite(w, HIGH);
    delay(g);
    digitalWrite(w, LOW);
    delay(g);    
  }
}
