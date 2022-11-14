int led1 = 2;
int led2 = 3;
int flag = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
void loop()
{
  int x = analogRead(A1);
  int y = analogRead(A2);
  Serial.println("Ocd x = " + (String)x);
  Serial.println("Ocd y = " + (String)y);
  if (x == 0)
  {
    flag += 1;
  }
  else if (x == 1023)
  {
    flag -= 1;
  }
  if (flag == 1)
  {
    digitalWrite(led1, y);
    delay(100);
    digitalWrite(led1, y);
    delay(100);
  }
  else if (flag == 2)
  {
    digitalWrite(led2, y);
    delay(100);
    digitalWrite(led2, y);
    delay(100);
  }
}
