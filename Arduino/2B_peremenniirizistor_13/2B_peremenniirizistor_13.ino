int x = A0;
String k = "Hello";
String f = "Bye";
void setup()
{
  Serial.begin(9600);
  pinMode(x, INPUT);
}
void loop()
{
  int y = analogRead(x);
  if (y == 200)
  {
    for (int i = 0; i < 5; i++)
      Serial.println(k);
  }
  if (y == 400)
  {
    for (int i = 0; i < 3; i++)
      Serial.println(f);
  }
}
