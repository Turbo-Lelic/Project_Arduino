#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int x = A1, y = A2;
int arr[2] = {x, y};

void setup(){
  Serial.begin(9600);

  for (int i = 0; i < 2; i++) {
    pinMode(arr[i], INPUT);
  }
  lcd.init();
  lcd.cursor();
  lcd.backlight();
}
void loop() {
  int x_state = analogRead(x), y_state = analogRead(y);
  Serial.println("Ocd x - " + (String)x_state);
  Serial.println("Ocd y - " + (String)y_state);
  
  if (x_state >= 0 && x_state <= 500) {
    lcd.setCursor(0, 0);
  } else if (x_state >= 501 && x_state <= 1023) {
    lcd.setCursor(1, 0);
  } else if (y_state >= 0 && y_state <= 500) {
    lcd.setCursor(2, 0);
  } else if (y_state >= 501 && y_state >= 1023) {
    lcd.setCursor(3, 0);
  }
}
