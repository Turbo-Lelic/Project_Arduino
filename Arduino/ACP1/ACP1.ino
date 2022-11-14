int val = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}
void loop()
{
  val = analogRead(A0);
  delay(100);
  Serial.println(val);
  delay(1000);
}
