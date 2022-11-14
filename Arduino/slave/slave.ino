#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <DHT.h>
#define DHTPIN 2
DHT dht(DHTPIN, DHT11);
#define PIN_direction_TX_RX 7
LiquidCrystal_I2C Icd(0x27, 16, 2);
void setup()
{
  pinMode(PIN_direction_TX_RX, OUTPUT);
  digitalWrite(PIN_direction_TX_RX, LOW);
  Serial.begin(9600);
  dht.begin();

  Icd.init();
  Icd.backlight();
  Icd.clear();
  Icd.setCursor(0, 0);
  Icd.print("");
}
void loop()
{
  delay(1);
  digitalWrite(PIN_direction_TX_RX, LOW);
  delay(100);

  String var = "";
  while (!Serial.available()) delay(20);
  delay(200);

  while (Serial.available())
    var = var + (char)(Serial.read());

  String T1;
  T1 = var.substring(var.indexOf("T1") + 2, var.indexOf("1T"));

  if (T1 == "DHT")
  {
    delay(2000);
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);
    
    String str_t = "T1";
    str_t += (String)t;
    str_t += "1TT2";
    str_t += (String)h;
    str_t += "2T";

    digitalWrite(PIN_direction_TX_RX, HIGH);
    delay(10);

    Serial.println(str_t);
    Serial.flush();

    delay(1000);
    digitalWrite(PIN_direction_TX_RX, LOW);
    T1 = "";

      Serial.print("Влажность : ");
      Serial.println(h);

      Serial.print("Температура : ");
      Serial.print(t);
      Serial.print(" *C, ");
      Serial.print(f);
      Serial.println(" *F");

    
  }
}
