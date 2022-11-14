int x[3] = {5, 6, 7};
int c[3] = {2, 3, 4};
int y[3] = {0, 0, 0};
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 3; i++)
  {
    pinMode(x[i], INPUT);
    pinMode(c[i], OUTPUT);
  }
}
void loop()
{
  delay(3000);
  Serial.println("btn1 = " + (String) y[0]);
  Serial.println("btn2 = " + (String) y[1]);
  Serial.println("btn3 = " + (String) y[2]);
  for (int q = 0; q < 3; q++)
  {
    y[q] = digitalRead(x[q]);
  }
  if (y[0] == LOW)
  {
    digitalWrite(c[0], HIGH);
    delay(100);
    digitalWrite(c[0], LOW);
    delay(100);
  }
  else if (y[1] == LOW)
  {
    digitalWrite(c[1], HIGH);
    delay(100);
    digitalWrite(c[1], LOW);
    delay(100);
  }
  else if (y[2] == LOW)
  {
    digitalWrite(c[2], HIGH);
    delay(100);
    digitalWrite(c[2], LOW);
    delay(100);
  }
}
