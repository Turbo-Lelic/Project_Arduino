int x[4] = {1, 2, 3, 4};
int y[4] = {0, 0, 0, 0};
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 4; i++)
  {
    pinMode(x[i], INPUT);
  }
}
void loop()
{
  for (int q = 0; q < 4; q++)
  {
    y[q] = analogRead(x[q]);
  }
  for (int s = 0; s < 4; s++)
  {
    Serial.println(y[s]);
  }
}
