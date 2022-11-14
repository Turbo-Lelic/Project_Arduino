#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int ledpin1 = 1, ledpin2 = 2, ledpin3 = 8, ledpin4 = 9, ledpin5 = 10, fire = 3, water = 4, zvyk = 11, poloci = 12, temperatura = 13, btn1 = 5, btn2 = 6, btn3 = 7, fire_cnt = 0, water_cnt = 0, zvyk_cnt = 0, poloci_cnt = 0, temperatura_cnt = 0, cnt_bool = 0;
int arr_digital[10] = {ledpin1, ledpin2, ledpin3, ledpin4, ledpin5, fire, water, zvyk, poloci, temperatura}, arr_analog[8] = {btn1, btn2, btn3, A0, A1, A2, A3, A4}, int arr_cnt[5] = {fire_cnt, water_cnt, zvyk_cnt, poloci_cnt, temperatura_cnt};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 10; i++) {
    pinMode(arr_digital[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(arr_analog[i], INPUT);
  }
  lcd.init();
  lcd.backlight();
}
void loop() {
  int btn1_state = digitalRead(btn1), btn2_state = digitalRead(btn2), btn3_state = digitalRead(btn3);
  int fire_state = analogRead(A0), water_state = analogRead(A1), zvyk_state = analogRead(A2), poloci_state = analogRead(A3), temperatura_state = analogRead(A4);

  for (int i = 0, j = 0; i < 5; i++, j += 2) {
    lcd.setCursor(0, j);
    lcd.print(arr_cnt[i]);
  }

  if (btn1_state == LOW) {
    if (cnt_bool == 5) {
      cnt_bool = 0;
    } else {
      cnt_bool++;
    }
  }

  if (btn2_state == LOW && cnt_bool == 0) {
    fire_cnt++;
  } else if (btn2_state == LOW && cnt_bool == 1) {
    water_cnt++;
  } else if (btn2_state == LOW && cnt_bool == 2) {
    zvyk_cnt++;
  } else if (btn2_state == LOW && cnt_bool == 3) {
    poloci_cnt++;
  } else if (bnt2_state == LOW && cnt_bool == 4) {
    temperatura_cnt++;
  }

  if (btn3_state == LOW && cnt_bool == 0) {
    fire_cnt--;
  } else if (btn3_state == LOW && cnt_bool == 1) {
    water_cnt--;
  } else if (btn3_state == LOW && cnt_bool == 2) {
    zvyk_cnt--;
  } else if (btn3_state == LOW && cnt_bool == 3) {
    poloci_cnt--;
  } else if (bnt3_state == LOW && cnt_bool == 4) {
    temperatura_cnt--;
  }
  
  if (fire_cnt == 5 && fire_state == 5) {
    repet(int ledpin1);
  }
  if (water_cnt == 5 && water_state == 5) {
    repet(int ledpin2);
  }
  if (zvyk_cnt == 5 && zvyk_state == 5) {
    repet(int ledpin3);
  }
  if (poloci_cnt == 5 && poloci_state == 5) {
    repet(int ledpin4);
  }
  if (temperatura_cnt == 5 && temperatura_state == 5) {
    repet(int ledpin5);
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