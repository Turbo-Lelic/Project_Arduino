int btn = 11;
int btn_1 = 12;
int btn_2 = 13;
int z = 7;
int x = 8;
int j = 0;
void setup()
{
  pinMode(btn, INPUT);
  pinMode(btn_1, INPUT);
  pinMode(z, OUTPUT);
  pinMode(x, OUTPUT);
}
void loop()
{
  int btn_q;
  btn_q = digitalRead(btn);

  int btn_w;
  btn_w = digitalRead(btn_1);

  int btn_e;
  btn_e = digitalRead(btn_2);

  if (btn_q == LOW)
  {
    j += 1;
  }
  if (btn_w == LOW)
  {
    j -= 1;
  }
  if (j == 1 and btn_e == LOW)
  {
    digitalWrite(z, HIGH);
    digitalWrite(x, HIGH);
    delay(400);
    digitalWrite(z, LOW);
    digitalWrite(x, LOW);
    delay(400);
  }
  if (j == 0 and btn_e == LOW)
  {
    digitalWrite(z, HIGH);
    digitalWrite(x, HIGH);
    delay(400);
    digitalWrite(z, LOW);
    digitalWrite(x, LOW);
    delay(400);

    digitalWrite(z, HIGH);
    digitalWrite(x, HIGH);
    delay(400);
    digitalWrite(z, LOW);
    digitalWrite(x, LOW);
    delay(400);
  }
}
