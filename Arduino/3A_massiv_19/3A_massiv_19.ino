int x[3] = {2, 3, 4};
int y[3] = {100, 150, 200};
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
      digitalWrite(x[i], HIGH);
      delay(y[0]);
      digitalWrite(x[i], LOW);
      delay(y[0]);
    }
  }
}
void loop()
{

}
