int x[4] = {1, 2, 3, 4};
float y[4] = {0, 0, 0, 0};
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
  for (int j = 0; j < 4; j++)
  {
    y[j] = analogRead(x[j]);
    y[j] = (5.0/1024.0)*y[j];
    Serial.println(y[j]);
  }
}
