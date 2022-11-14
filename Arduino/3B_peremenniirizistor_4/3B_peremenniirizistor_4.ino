int btn1 = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int x = A0;
int flag = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(x, INPUT);
}
void loop()
{
  int p = analogRead(x);
  int btn_1 = digitalRead(btn1);
  if (btn_1 == LOW)
  {
    flag += 1;
  }
  else if (flag == 1 and btn_1 == LOW)
  {
    analogWrite(led1, p);
    delay(100);
    analogWrite(led1, p);
    delay(100);
  }
  else if (flag == 2 and btn_1 == LOW)
  {
    analogWrite(led2, p);
    delay(100);
    analogWrite(led2, p);
    delay(100);
  }
  else if (flag == 3 and btn_1 == LOW)
  {
    analogWrite(led3, p);
    delay(100);
    analogWrite(led3, p);
    delay(100);
  }
  else if (flag == 4 and btn_1 == LOW)
  {
    analogWrite(led4, p);
    delay(100);
    analogWrite(led4, p);
    delay(100);
  }
}
