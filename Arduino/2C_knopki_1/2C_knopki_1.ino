int btn = 12;
int z = 7;
void setup()
{
  pinMode(btn, INPUT);
  pinMode(z, OUTPUT);
}
void loop()
{
  int btn_q;
  btn_q = digitalRead(btn);

  if (btn_q == LOW)
  {
    for (int i = 0; i < 6; i++)
    {
      digitalWrite(z, HIGH);
      delay(100);
      digitalWrite(z, LOW);
      delay(100);
    }
  }
}
