int x[5] = {2, 3, 4, 5, 6};
int y[5] = {0, 50, 100, 200, 250};
void setup()
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(x[i], OUTPUT);
  }
  for (int i = 0; i < 5; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      analogWrite(x[i], y[0, 1, 2, 3, 4]);
      delay(100);
      analogWrite(x[i], y[4, 3, 2, 1, 0]);
      delay(100);
    }
  }
}
void loop()
{

}
