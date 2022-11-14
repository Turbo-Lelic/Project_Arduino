#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Icd(0x27, 16, 2);
int ledpin1 = 7;
int ledpin2 = 9;
int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int flag = 0;
void setup()
{
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  Serial.begin(9600);
}
void loop()
{
  int btn_1;
  btn_1 = digitalRead(btn1);

  int btn_2;
  btn_2 = digitalRead(btn2);

  int btn_3;
  btn_3 = digitalRead(btn3);

  Icd.print(flag);

  if (btn_1 == LOW)
  {
    digitalWrite(ledpin1, HIGH);
    digitalWrite(ledpin2, HIGH);
    delay(100);
    digitalWrite(ledpin1, LOW);
    digitalWrite(ledpin2, LOW);
    delay(100);
    flag += 10;
  }
  if (flag == 10 and btn_2 == LOW)
  {
    for (int i = 0; i < 1; i++)
    {
      analogWrite(ledpin1, HIGH);
      delay(100);
      analogWrite(ledpin1, LOW);
      delay(100);
    }
    if (flag == 20 and btn_2 == LOW)
    {
      for (int i = 0; i < 2; i++)
      {
        analogWrite(ledpin1, HIGH);
        delay(100);
        analogWrite(ledpin1, LOW);
        delay(100);
      }
      if (flag == 30 and btn_2 == LOW)
      {
        for (int i = 0; i < 3; i++)
        {
          analogWrite(ledpin1, HIGH);
          delay(100);
          analogWrite(ledpin1, LOW);
          delay(100);
        }
        if (flag == 40 and btn_3 == LOW)
        {
          for (int i = 0; i < 1; i++)
          {
            analogWrite(ledpin2, HIGH);
            delay(100);
            analogWrite(ledpin2, LOW);
            delay(100);
          }
          if (flag == 50 and btn_3 == LOW)
          {
            for (int i = 0; i < 2; i++)
            {
              analogWrite(ledpin2, HIGH);
              delay(100);
              analogWrite(ledpin2, LOW);
              delay(100);
            }
            if (flag == 60 and btn_3 == LOW)
            {
              for (int i = 0; i < 3; i++)
              {
                analogWrite(ledpin2, HIGH);
                delay(100);
                analogWrite(ledpin2, LOW);
                delay(100);
              }
            }
          }
        }
      }
    }
  }
}
