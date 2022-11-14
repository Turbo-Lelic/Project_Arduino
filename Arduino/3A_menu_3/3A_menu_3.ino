#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int ledpin1 = 2;
int ledpin2 = 3;
int ledpin3 = 4;
int MenuPos = 0;
int MenuPlus = 5;
int MenuMinus = 6;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(MenuPlus, INPUT);
  pinMode(MenuMinus, INPUT);
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
}
void loop()
{
  int fd = analogRead(A0);
  int vd = analogRead(A1);
  int btn_1 = digitalRead(MenuPlus);
  int btn_2 = digitalRead(MenuMinus);

  Serial.println("vd = " + (String) vd);
  Serial.println("fd = " + (String) fd);
  if (MenuPlus == LOW)
  {
    MenuPos++;
    Serial.println("MenuPos++");
  }
  if (MenuMinus == LOW)
  {
    MenuPos--;
    Serial.println("MenuPos--");
  }
  else if (MenuPos == 0)
  {
    digitalWrite(ledpin1, HIGH);
    delay(100);
    digitalWrite(ledpin1, LOW);
    delay(100);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(vd);
    lcd.setCursor(1, 0);
    lcd.print(fd);
  }
  else if (MenuPos == 1)
  {
    digitalWrite(ledpin2, HIGH);
    delay(100);
    digitalWrite(ledpin2, LOW);
    delay(100);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(vd);
  }
  else if (MenuPos == 2)
  {
    digitalWrite(ledpin3, HIGH);
    delay(100);
    digitalWrite(ledpin3, LOW);
    delay(100);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(fd);
  }
}
