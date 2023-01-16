#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledpin_1 = 2, ledpin_2 = 3, cnt_ledpin = 0, cnt_value_1 = 0, cnt_value_2 = 0;

void setup() {
  Serial.begin(9600);
  lcd.init(); lcd.backlight();
  pinMode(ledpin_1, OUTPUT); pinMode(ledpin_2, OUTPUT);
  pinMode(A0, INPUT); pinMode(A1, INPUT);
}
void loop() {
  int x = analogRead(A0), y = analogRead(A1);

  if (y == 512 && x >= 1023 && x <= 511) {cnt_ledpin = 1;}
  if (y == 512 && x >= 510 && x <= 0) {cnt_ledpin = 0;}

  if (x == 512 && y >= 1023 && y <= 511) { // ON
    if (cnt_ledpin == 0) {
      if (cnt_value_1 == 1) {
        cnt_value_1 = 1;
      } else {
        cnt_value_1++;
      }
      digitalWrite(ledpin_1, HIGH);
    }
    if (cnt_ledpin == 1) {
      if (cnt_value_2 == 1) {
        cnt_value_2 = 1;
      } else {
        cnt_value_2++;
      }
      digitalWrite(ledpin_2, HIGH);
    }
  }
  if (x == 512 && y >= 510 && y <= 0) { // OFF
    if (cnt_ledpin == 0) {
      if (cnt_value_1 == 0) {
        cnt_value_1 = 0;
      } else {
        cnt_value_1--;
      }
      digitalWrite(ledpin_1, LOW);
    }
    if (cnt_ledpin == 1) {
      if (cnt_value_2 == 0) {
        cnt_value_2 = 0;
      } else {
        cnt_value_2--;
      }
      digitalWrite(ledpin_2, LOW);
    }
  }
  lcd.setCursor(0, 0); lcd.print(cnt_value_1);
  lcd.setCursor(0, 1); lcd.print(cnt_value_2);
}