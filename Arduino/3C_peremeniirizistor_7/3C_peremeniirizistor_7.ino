#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int ledpin1 = 1, ledpin2 = 2, fire = 3, water = 4, btn1 = 5, btn2 = 6, btn3 = 7, fire_cnt = 0, water_cnt = 0, cnt_bool = 0;
int arr_digital[4] = {ledpin1, ledpin2, fire, water}, arr_analog[5] = {btn1, btn2, btn3, A0, A1};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(arr_digital[i], OUTPUT);
  }
  for (int i = 0; i < 5; i++) {
    pinMode(arr_analog[i], INPUT);
  }
  lcd.init();
  lcd.backlight();
}
void loop() {
  int btn1_state = digitalRead(btn1), btn2_state = digitalRead(btn2), btn3_state = digitalRead(btn3);
  int fire_state = analogRead(A0), water_state = analogRead(A1);

  lcd.setCursor(0, 0);
  lcd.print(fire_cnt);
  lcd.setCursor(1, 0);
  lcd.print(water_cnt);

  if (btn1_state == LOW) {
    if (cnt_bool == 2) {
      cnt_bool = 0;
    } else {
      cnt_bool++;
    }
  }

  if (btn2_state == LOW && cnt_bool == 0) {
    fire_cnt += 1;
  } else if (btn2_state == LOW && cnt_bool == 1) {
    water_cnt += 1;
  }

  if (btn3_state == LOW && cnt_bool == 0) {
    fire_cnt -= 1;
  } else if (bnt3_state == LOW && cnt_bool == 1) {
    water_cnt -= 1;
  }
  
  if (fire_cnt == 5 && fire_state == 5) {
    repet(int ledpin1);
  }
  if (water_cnt == 5 && water_state == 5) {
    repet(int ledpin2);
  }
}
void repet(int ledpin) {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledpin, HIGH);
    delay(200);
    digitalWrite(ledpin, LOW);
    delay(200);
  }
}