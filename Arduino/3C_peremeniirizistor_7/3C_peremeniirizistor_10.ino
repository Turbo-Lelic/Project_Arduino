#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int btn = 2, ledpin = 3, peremeniirizistor = A0, cnt = 0;
int arr[2] = {btn, peremeniirizistor};

void setup() {
  Serial.begin(9600);
  Icd.init();
  Icd.backlight();

  for (int i = 0; i < 2; i++) {
    pinMode(arr[i], INPUT);
  }
  pinMode(ledpin, OUTPUT);
}
void loop() {
  int peremeniirizistor_state = analogRead(peremeniirizistor), btn_state = digitalRead(btn);

  if (peremeniirizistor_state >= 100 && peremeniirizistor_state <= 200 ||
      peremeniirizistor_state >= 201 && peremeniirizistor_state <= 300 ||
      peremeniirizistor_state >= 301 && peremeniirizistor_state <= 400) {
    cnt++;
  }
  if (btn_state == LOW) {
    Icd.setCursor(0, 0);
    lcd.print(cnt);

    for (int i = 0; i < cnt; i++) {
      digitalWrite(ledpin, HIGH), delay(500);
      digitalWrite(ledpin, LOW), delay(500);
    }
  }
}