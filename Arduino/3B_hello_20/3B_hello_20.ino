char x[6] = "hello!";
void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 6; i++)
  {
    Serial.print(x[i]);      
  }
}
void loop()
{
  
}
