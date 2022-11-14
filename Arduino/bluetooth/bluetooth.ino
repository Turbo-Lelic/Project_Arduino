char btCommand;
void setup()
{
  Serial.begin(9600);
  Serial.println("Ready");
}
void loop()
{
  if (Serial.available() > 0)
  {
    btCommand = Serial.read();
    if (btCommand == 'F')
    {
      Serial.println("F");
    }
    else if (btCommand == 'B')
    {
      Serial.println("B");
    }
    else if (btCommand == 'L')
    {
      Serial.println("L");
    }
    else
    {
      Serial.println("no commands");
    }
  }
}
