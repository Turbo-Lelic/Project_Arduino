int x[5][2] =
{
  {2, 1},
  {3, 0},
  {4, 1},
  {5, 0},
  {6, 1}
};
void setup()
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(x[i][0], x[0][1]);
  }
  for (int i = 0; i < 5; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      digitalWrite(x[i][0], x[0][1]);
      delay(100);
      digitalWrite(x[i][0], x[1][1]);
      delay(100);
    }
  }
}
void loop()
{
        
}
