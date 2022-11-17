#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  Icd.init();
  Icd.backlight();
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}
void loop() {
  int x = analogRead(A0), y = analogRead(A1);

  if (x >= 0 && x <= 512 && y == 512) {
    lcd.setCursor(0, 0);
    lcd.print("Hello");
  }
  if (x >= 513 && x <= 1023 && y == 512) {
    lcd.setCursor(0, 1);
    lcd.print("Goodbye");
  }
}