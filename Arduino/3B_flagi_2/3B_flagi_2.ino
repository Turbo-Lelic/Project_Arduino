#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int led = 5;
int flag = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(led, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.setCursor(0, 0);
}
void loop()
{
  int btn_1 = digitalRead(btn1);
  int btn_2 = digitalRead(btn2);
  int btn_3 = digitalRead(btn3);
  if (btn_1 == LOW)
  {
    flag += 1;
  }
  else if (btn_2 == LOW)
  {
    flag -= 1;
  }
  else if (flag == 0 and btn_3 == LOW)
  {
    lcd.print("1");
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }
  else if (flag == 1 and btn_3 == LOW)
  {
    for (int i = 0; i < 2; i++)
    {
      lcd.print("2");
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      delay(100);
    }
  }
}
