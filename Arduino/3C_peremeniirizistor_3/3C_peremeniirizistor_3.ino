#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int p = A0;
byte custom_cursor[] = {
  B10101,
  B01010,
  B10101,
  B01010,
  B10101,
  B01010,
  B10101,
  B01010
};

void setup() {
  Serial.begin(9600);
  pinMode(p, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, custom_cursor);
}
void loop() {
  int p_state = analogRead(p);

  Serial.println("peremanii rezistor - " + (String) p_state);

  if (p_state >= 0 && p_state <= 100) {
    lcd.setCursor(0, 0);
    lcd.write(0);
  }
  if (p_state >= 101 && p_state <= 200) {
    lcd.setCursor(1, 0);
    lcd.write(0);
  }
  if (p_state >= 201 && p_state <= 300) {
    lcd.setCursor(2, 0);
    lcd.write(0);
  }
  if (p_state >= 301 && p_state <= 400) {
    lcd.setCursor(3, 0);
    lcd.write(0);
  }
  if (p_state >= 401 && p_state <= 500) {
    lcd.setCursor(4, 0);
    lcd.write(0);
  }
}
