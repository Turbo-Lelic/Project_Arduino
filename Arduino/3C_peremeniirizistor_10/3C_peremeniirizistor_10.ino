#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int peremenniirizistor = A0, bnt = 2, ledpin = 3, cnt = 0;
int arr[2] = {peremenniirizistor, bnt};

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  for (int i = 0; i < 2; i++) {
    pinMode(arr[i], INPUT);
  }
  pinMode(ledpin, OUTPUT);
} 
void loop() {
  int peremenniirizistor_state = analogRead(peremenniirizistor), btn_state = digitalRead(btn);

  if (peremenniirizistor_state >= 100 && peremenniirizistor_state <= 200 ||
      peremenniirizistor_state >= 201 && peremenniirizistor_state <= 300 ||
      peremenniirizistor_state >= 301 && peremenniirizistor_state <= 400) {
    cnt++;
  }
  if (btn_state == LOW) {
    lcd.setCursor(0, 0);
    lcd.print(cnt);
    
    for (int i = 0; i < cnt; i++) {
      digitalWrite(ledpin, HIGH), delay(500);
      digitalWrite(ledpin, LOW), delay(500);
    }
  }
}