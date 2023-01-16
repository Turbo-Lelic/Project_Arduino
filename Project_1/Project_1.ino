#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT dht(5, DHT11);

int ledpin_1 = 2, ledpin_2 = 3, ledpin_3 = 4;
int arr[3] = {ledpin_1, ledpin_2, ledpin_3};
void setup() {
  Serial.begin(9600); 
  dht.begin(); lcd.init(); lcd.backlight();

  for (int i = 0; i < 3; i++) {
    pinMode(arr[i], OUTPUT);
  }
}
void loop() {
  float v = dht.readHumidity(), t = dht.readTemperature(); //Влажность | Температура
  Serial.println("влажность: ", v); Serial.println("температура: ", t);

  if ((v >= 40 && v <= 55) && (t >= 20 && t <= 23)) { // 3/1
    digitalWrite(arr[2], HIGH), delay(3000);
    digitalWrite(arr[2], LOW), delay(3000);
  } else if (((v >= 30 && v <= 39 || v >= 56 && v < 65) && (t >= 17 && t <= 19 || t >= 24 && t <= 26))) { // 3/2
    digitalWrite(arr[1], HIGH), delay(2000);
    digitalWrite(arr[1], LOW), delay(2000);
  } else { // 3/3
    digitalWrite(arr[0], HIGH), delay(1000);
    digitalWrite(arr[0], LOW), delay(1000);
  }
  lcd.setCursor(0, 0); lcd.print("влажность: "); lcd.print(v);
  lcd.setCursor(0, 1); lcd.print("температура: "); lcd.print(t);
}