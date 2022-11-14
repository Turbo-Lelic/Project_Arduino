int x[5][2] =
{
  {2, 0},
  {3, 50},
  {4, 100},
  {5, 200},
  {6, 250}
};
void setup()
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(x[i][0], OUTPUT);
  }
  for (int i = 0; i < 5; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      analogWrite(x[i][0], x[0][0]);
      delay(100);
      analogWrite(x[i][0], x[1][1]);
      delay(100);
    }
  }
}
void loop()
{
        
}
