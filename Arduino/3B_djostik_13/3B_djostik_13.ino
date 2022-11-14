int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int flag = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
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
  if (x == 1023)
  {
    flag -= 1;
  }
  else if (flag == 1)
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
  else if (flag == 3)
  {
    digitalWrite(led3, y);
    delay(100);
    digitalWrite(led3, y);
    delay(100);
  }
  else if (flag == 4)
  {
    digitalWrite(led4, y);
    delay(100);
    digitalWrite(led4, y);
    delay(100);
  }
  else if (flag == 5)
  {
    digitalWrite(led5, y);
    delay(100);
    digitalWrite(led5, y);
    delay(100);
  }
}
