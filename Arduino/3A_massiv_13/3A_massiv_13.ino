int x[5] = {5, 6, 7, 8, 9};
void setup()
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(x[i], OUTPUT);
  }
  for (int t = 0; t < 5; t++)
  {
    for (int i = 0; i < 5; i++)
    {
      digitalWrite(x[i], HIGH);
      delay(100);
      digitalWrite(x[i], LOW);
      delay(100);
    }
  }
}
  void loop()
  {

  }
