
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <TM1637.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Icd(0x3f, 16, 2);
RF24           radio(9, 10);
int16_t x = A0;
int16_t y;
#define CLK 3
#define DIO 2
TM1637 tm1637(CLK, DIO);
void setup()
{
  delay(1000);

  tm1637.init();
  tm1637.setDp(7);
  Serial.begin(9600);
  Serial.println("Приемник");
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
    while (true)
    {
      radio.read(&y, sizeof(y));
      Serial.println(y);
      tm1637.display(y);
      delay(y);
    }
  }
}
