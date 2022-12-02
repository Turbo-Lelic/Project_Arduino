#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int cnt = 0, cnt_1 = 0, cnt_2 = 0; 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(A0, INPUT), pinMode(A1, INPUT);
}
void loop() {
  int x = analogRead(A0), y = analogRead(A1);
  lcd.setCursor(0, 0), lcd.print(cnt_1);
  lcd.setCursor(1, 0), lcd.print(cnt_2);

  if (x >= 0 && x <= 1023 && y == 512) {
    cnt++;
    if (cnt == 2) {
      cnt = 0;
    }
  }
  if (y >= 0 && y <= 1023 && x == 512) {
    if (cnt == 0) {
      cnt_1 += 1;
    }
    if (cnt == 1) {
      cnt_2 += 1;
    }
  }
}