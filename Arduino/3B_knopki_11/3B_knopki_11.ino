#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int btn1 = 6;
int btn2 = 7;
int btn3 = 8;
int flag = 0;
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}
void loop()
{
  int btn_1 = digitalRead(btn1);
  int btn_2 = digitalRead(btn2);
  int btn_3 = digitalRead(btn3);
  lcd.setCursor(0, 0);
  lcd.print("LED_1 - 0");
  lcd.setCursor(0, 8);
  lcd.print("LED_2 - 0");
  lcd.setCursor(1, 0);
  lcd.print("LED_3 - 0");
  lcd.setCursor(1, 8);
  lcd.print("LED_4 - 0");
  if (btn_1 == LOW)
  {
    flag += 1;
  }
  else if (btn_2 == LOW)
  {
    flag -= 1;
  }
  else if (flag == 1 and btn_3 == LOW)
  {
    lcd.clear();
    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("LED_1 - 1");
    lcd.setCursor(0, 8);
    lcd.print("LED_2 - 0");
    lcd.setCursor(1, 0);
    lcd.print("LED_3 - 0");
    lcd.setCursor(1, 8);
    lcd.print("LED_4 - 0");
  }
  else if (flag == 2 and btn_3 == LOW)
  {
    lcd.clear();
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("LED_1 - 0");
    lcd.setCursor(0, 8);
    lcd.print("LED_2 - 1");
    lcd.setCursor(1, 0);
    lcd.print("LED_3 - 0");
    lcd.setCursor(1, 8);
    lcd.print("LED_4 - 0");
  }
  else if (flag == 3 and btn_3 == LOW)
  {
    lcd.clear();
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("LED_1 - 0");
    lcd.setCursor(0, 8);
    lcd.print("LED_2 - 0");
    lcd.setCursor(1, 0);
    lcd.print("LED_3 - 1");
    lcd.setCursor(1, 8);
    lcd.print("LED_4 - 0");
  }
  else if (flag == 3 and btn_3 == LOW)
  {
    lcd.clear();
    digitalWrite(led4, HIGH);
    delay(100);
    digitalWrite(led4, LOW);
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("LED_1 - 0");
    lcd.setCursor(0, 8);
    lcd.print("LED_2 - 0");
    lcd.setCursor(1, 0);
    lcd.print("LED_3 - 0");
    lcd.setCursor(1, 8);
    lcd.print("LED_4 - 1");
  }
}
