
#include <DHT.h>
#include <TM1637.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Icd(0x3f,16,2);
RF24           radio(9, 10);
int digitoneT;
int digittwoT;
int digitoneH;
int digittwoH;
#define CLK 3
#define DIO 2
TM1637 tm1637(CLK, DIO);
void setup()
{
  delay(100);
  Serial.begin(9600);
  tm1637.init();
  tm1637.setBrightness(4);
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
   radio.read(&digitoneT, sizeof(digitoneT));
   radio.read(&digittwoT, sizeof(digittwoT));
   radio.read(&digitoneH, sizeof(digitoneH));
   radio.read(&digittwoH, sizeof(digittwoH));
   delay(100);
   tm1637.display(1, digitoneT);
   tm1637.display(2, digittwoT);
   Serial.println(digitoneT);
   Serial.println(digittwoT);
   delay(5000);
   tm1637.display(1, digitoneH);
   tm1637.display(2, digittwoH);
   Serial.println(digitoneH);
   Serial.println(digittwoH);
   delay(5000);
  }
  else
  {
    Icd.clear();
    Icd.print("no signal!");
    delay(100);
  }
}
