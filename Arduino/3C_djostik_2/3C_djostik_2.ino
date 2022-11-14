#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int x = A1, y = A2, btn = 8, ledpin = 7, cnt = 0;
int arr[3] = {x, y, btn};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(arr[i], INPUT);
  }
  pinMode(ledpin, OUTPUT);
  lcd.init();
  lcd.backlight();
}
void loop() {
  int btn_state = analogRead(btn), x_state = analogRead(x), y_state = analogRead(y);

  Serial.println("x - " + (String) x);
  Serial.println("y - " + (String) y);

  if (y_state == 1023) {
    cnt++;
  }
  if (btn_state == LOW) {
    lcd.print(cnt);
    
    for (int i = 0; i < cnt; i++) {
      digitalWrite(ledpin, HIGH);
      delay(500);
      digitalWrite(ledpin, LOW); 
    }
  }
}
