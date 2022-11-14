#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int p_1 = A0, p_2 = A1;
byte custom_cursor1[] {
  B10101,
  B01010,
  B10101,
  B01010,
  B10101,
  B01010,
  B10101,
  B01010
};
byte custom_cursor2[] {
  B01010,
  B10101,
  B01010,
  B10101,
  B01010,
  B10101,
  B01010,
  B10101
};

void setup() {
  Serial.begin(9600);
  pinMode(p_1, INPUT);
  pinMode(p_2, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, custom_cursor1);
  lcd.createChar(1, custom_cursor2);
}

void loop() {
  int p_1_state = analogRead(p_1), p_2_state = analogRead(p_2);

  Serial.println("peremanii rezistor 1 - " + (String) p_1_state);
  Serial.println("peremanii rezistor 2 - " + (String) p_2_state);

  if (p_1_state >= 1023) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(0);
  }
  if (p_2_state >= 1023) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(1);
  }
}
