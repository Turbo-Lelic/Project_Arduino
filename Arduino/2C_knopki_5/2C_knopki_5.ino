int btn = 12;
int z = 7;
int i;
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
    while ( i < 6 )
    {
      digitalWrite(z, HIGH);
      delay(100);
      digitalWrite(z, LOW);
      delay(100);
      i++;
    }
  }
}
