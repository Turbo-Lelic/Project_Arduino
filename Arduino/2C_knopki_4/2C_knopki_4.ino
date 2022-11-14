int btn = 12;
int btn_1 = 13;
int z = 7;
int x = 8;
int c = 9;
int v = 10;
int b = 11;
void setup()
{
  pinMode(btn, INPUT);
  pinMode(btn_1, INPUT);
  pinMode(z, OUTPUT);
  pinMode(x, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(v, OUTPUT);
  pinMode(b, OUTPUT);
}
void loop()
{
  int btn_q;
  btn_q = digitalRead(btn);

  int btn_l;
  btn_l = digitalRead(btn_1);


  if (btn_q == LOW)
  {
    for (int i = 0; i < 6; i++)
    {
      digitalWrite(b, HIGH);
      delay(100);
      digitalWrite(b, LOW);
      delay(100);

      digitalWrite(v, HIGH);
      delay(100);
      digitalWrite(v, LOW);
      delay(100);

      digitalWrite(c, HIGH);
      delay(100);
      digitalWrite(c, LOW);
      delay(100);

      digitalWrite(c, HIGH);
      delay(100);
      digitalWrite(c, LOW);
      delay(100);

      digitalWrite(x, HIGH);
      delay(100);
      digitalWrite(x, LOW);
      delay(100);

      digitalWrite(z, HIGH);
      delay(100);
      digitalWrite(z, LOW);
      delay(100);
    }
    if (btn_l == LOW)
    {
      for (int i = 0; i < 6; i++)
      {
        digitalWrite(z, HIGH);
        delay(100);
        digitalWrite(z, LOW);
        delay(100);

        digitalWrite(x, HIGH);
        delay(100);
        digitalWrite(x, LOW);
        delay(100);

        digitalWrite(c, HIGH);
        delay(100);
        digitalWrite(c, LOW);
        delay(100);

        digitalWrite(v, HIGH);
        delay(100);
        digitalWrite(v, LOW);
        delay(100);

        digitalWrite(b, HIGH);
        delay(100);
        digitalWrite(b, LOW);
        delay(100);
      }
    }
  }
}
