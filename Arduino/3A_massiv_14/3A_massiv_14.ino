int x[3] = {5, 6, 7};
void setup()
{
  for (int i = 0; i < 3; i++)
  {
    pinMode(x[i], OUTPUT);
  }
  for (int t = 0; t < 3; t++)
  {
    for (int y = 0; y <= 255; y++)
    {
      analogWrite(x, y);
      delay(5);
      analogWrite(x, y);
      delay(5);
    }
  }
}
void loop()
{

}
