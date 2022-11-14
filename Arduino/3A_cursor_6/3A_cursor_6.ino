byte customChar0[] = {
  B00000,
  B00000,
  B00110,
  B00011,
  B11111,
  B00011,
  B00110,
  B00000
};
byte customChar1[] = {
  B00000,
  B00000,
  B01100,
  B11000,
  B11111,
  B11000,
  B01100,
  B00000
};
byte customChar2[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B01110,
  B11111,
  B01110,
  B01110
};
byte customChar3[] = {
  B01110,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};
int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int flag = 0;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("CURSOR 3A_6");
  lcd.setCursor(0, 1);
  lcd.print("arduino");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.createChar(0, customChar0);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.home();
}
void loop()
{
  int btn_1;
  btn_1 = digitalRead(btn1);

  int btn_2;
  btn_2 = digitalRead(btn2);

  int btn_3;
  btn_3 = digitalRead(btn3);

  if (btn_1 == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.write(0);
  }
  else if (btn_2 == LOW)
  {
    lcd.clear();
    lcd.setCursor(15, 0);
    lcd.write(1);
  }
  else if (flag == 0 and btn_3 == LOW)
  {
    flag += 1;
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.write(2);
  }
  else if (flag == 1 and btn_3 == LOW)
  {
    flag -= 1;
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.write(3);
  }
}
