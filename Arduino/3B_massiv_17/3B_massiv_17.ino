int x[3] = {1, 2, 3};
int y[3] = {0, 0, 0};
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 3; i++)
  {
    pinMode(x[i], INPUT);
  }
}
void loop()
{
  for (int g = 0; g < 3; g++)
  {
    y[g] = analogRead(x[g]);
  }
  for (int a = 0; a < 3; a++)
  {
    Serial.println(y[a]);
  }
}
