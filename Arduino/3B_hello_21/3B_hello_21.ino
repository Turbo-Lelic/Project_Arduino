char x[6] = "olleh";
void setup()
{
  Serial.begin(9600);
  for(int i = strlen(x); i >= 0; i--)
  {
    Serial.print(x[i]);
  }
}
void loop()
{

}
