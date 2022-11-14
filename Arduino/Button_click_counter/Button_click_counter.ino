int k;
void setup()
{
  Serial.begin(9600);
  pinMode(5, 1);
  pinMode(6, 1);
  pinMode(7, 1);
  pinMode(8, 1);
  pinMode(9, 1);
  pinMode(10, 1);
}
void loop()
{
  int x = digitalRead(2);
  int c = digitalRead(3);
  if (x == 0)
  {
    k++;
    delay(300);

    if (k > 10)
    {
      k = 0;
    }
    Serial.println(k);
  }
  if (c == 0)
  {
    k--;
    delay(300);

    if (k < 0)
    {
      k = 0;
    }
    Serial.println(k);
  }

  if (k == 1)
  {
    digitalWrite(5, 1);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    digitalWrite(10, 0);
  }
  if (k == 2)
  {
    digitalWrite(5, 0);
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    digitalWrite(10, 0);
  }
  if (k == 3)
  {
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    digitalWrite(10, 0);
  }
  if (k == 4)
  {
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 1);
    digitalWrite(9, 0);
    digitalWrite(10, 0);
  }
  if (k == 5)
  {
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 1);
    digitalWrite(10, 0);
  }
  if (k == 6)
  {
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    digitalWrite(10, 1);
  }
}
