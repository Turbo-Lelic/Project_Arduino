char x[5] = "hello";
void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 5; i++)
  {
    Serial.print(x[i]);      
  }
}
void loop()
{
  
}
