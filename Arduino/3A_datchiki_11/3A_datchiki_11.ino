uint8_t btn = 2;
uint8_t flag;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(btn, INPUT);
}
void loop()
{
  int z = analogRead(A0);
  int t = analogRead(A1);
  int o = analogRead(A2);
  int u = analogRead(A3);
  int h = analogRead(A4);

  int btn1 = digitalRead(btn);
  if (flag == 0 and btn1 == LOW)
  {
    flag += 1;
    Serial.print(z);
  }
  else if (flag == 1 and btn1 == LOW)
  {
    flag += 1;
    Serial.print(t);
  }
  else if (flag == 2 and btn1 == LOW)
  {
    flag += 1;
    Serial.print(o);
  }
  else if (flag == 3 and btn1 == LOW)
  {
    flag += 1;
    Serial.print(u);
  }
  else if (flag == 4 and btn1 == LOW)
  {
    Serial.print(h);
  }
  else if (flag > 4)
  {
    flag -= 4;
  }
}
