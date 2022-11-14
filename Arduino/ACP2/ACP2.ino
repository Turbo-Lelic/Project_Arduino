
float val = 0.0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}
void loop()
{
  val = analogRead(A0);
  delay(100);
  Serial.println((5.0 / 1024.0)*val);
  delay(1000);
}
