int x = A0;
int y;
String f = "Hi";
String h = "Goodbye";
void setup()
{
  Serial.begin(9600);
  pinMode(x,INPUT);
}
void loop()
{
  y = analogRead(x);
  if (y == 200)
  {
   Serial.println(f);
  }
  if (y == 400)
  {
   Serial.println(h);
  }
}
