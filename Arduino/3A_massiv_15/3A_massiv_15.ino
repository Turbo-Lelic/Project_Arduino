int x[5] = {2, 3, 4, 5, 6};
int y[5] = {0, 1, 0, 1, 0};
void setup()
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(x[i], y[1]);
  }
  for (int i = 0; i < 5; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      digitalWrite(x[i], y[1]);
      delay(100);
      digitalWrite(x[i], y[0]);
      delay(100);
    }
  }
}
void loop()
{

}
