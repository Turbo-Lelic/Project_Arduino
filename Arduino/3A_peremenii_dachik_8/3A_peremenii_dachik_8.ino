#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int btn1 = 5;
int btn2 = 6;
int btn3 = 7;
int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;
int flag = 0;
void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
}
void loop()
{
  int btn_1;
  btn_1 = digitalRead(btn1);

  int btn_2;
  btn_2 = digitalRead(btn2);

  int btn_3;
  btn_3 = digitalRead(btn3);

  int df = analogRead(A0);
  lcd.setCursor(0, 0);
  lcd.print(n1);
  lcd.setCursor(0, 1);
  lcd.print(n2);
  lcd.setCursor(0, 2);
  lcd.print(n3);
  lcd.setCursor(0, 3);
  lcd.print(n4);
  if (btn_1 == LOW)
  {
    flag += 1;
  }
  if (btn_2 == LOW)
  {
    flag -= 1;
  }
  if (flag == 1 and btn_3 == LOW)
  {
    n1 = analogRead(df);
    lcd.setCursor(1, 0);
    lcd.print(df);
  }
  if (flag == 2 and btn_3 == LOW)
  {
    n2 = analogRead(df);
    lcd.setCursor(1, 0);
    lcd.print(df);
  }
  if (flag == 3 and btn_3 == LOW)
  {
    n3 = analogRead(df);
    lcd.setCursor(1, 0);
    lcd.print(df);
  }
  if (flag == 4 and btn_3 == LOW)
  {
    n4 = analogRead(df);
    lcd.setCursor(1, 0);
    lcd.print(df);
  }
}
