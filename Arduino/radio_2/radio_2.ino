
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Icd(0x3f,16,2);
RF24           radio(9, 10);
int            data[2];
void setup()
{
  delay(100);
  Icd.init();
  Icd.backlight();

  radio.begin();
  radio.setChannel(5);
  radio.setDataRate     (RF24_1MBPS);
  radio.setPALevel      (RF24_PA_HIGH);
  radio.openReadingPipe (1, 0x1234567890LL);
  radio.startListening ();
}
void loop()
{
  if (radio.available())
  {
    radio.read(&data, sizeof(data));
    Serial.println("data[0]= "+(String)data[0]);
    Serial.println("data[1]= "+(String)data[1]);
    Icd.clear();
    Icd.print(data[0]);
    Icd.print(data[1]);
    delay(100);
  }
  else
  {
    Icd.clear();
    Icd.print("no signal!");
    delay(100);
  }
}
