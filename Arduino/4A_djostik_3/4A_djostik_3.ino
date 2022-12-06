// A0 = ось x | A1 = ось y | A2 = датчик огня | A3 = датчик уровня воды | A4 = датчик звука |
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int arr[5] = {A0, A1, A2, A3, A4};
unsigned int cnt = 0;

void setup() {
  Serial.begin(9600);
  lcd.init(); lcd.backlight();

  for (int i = 0; i < 5; i++) {
    pinMode(arr[i], INPUT);
  }
}
void loop() {
  int x = analogRead(A0), y = analogRead(A1), fire = analogRead(A2), voda = analogRead(A3), zvyk = analogRead(A4);
  
  if (x >= 1023 && x <= 512 && y == 512) { cnt--; }
  if (x >= 512 && x <= 0 && y == 512) {
    if (cnt == 2) { cnt--; }
    cnt++;
  }

  if (cnt == 0) {
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(fire);
  } else if (cnt == 1) {
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(voda);
  } else if (cnt == 2) {
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(zvyk);
  }
}