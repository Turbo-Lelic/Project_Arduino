#include <TM1637.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <LiquidCrystal_I2C.h>
int16_t x = A0;
int16_t y;
#define CLK 3
#define DIO 2
TM1637 tm1637(CLK, DIO);
RF24           radio(9, 10);
LiquidCrystal_I2C Icd(0x3f, 16, 2);
void setup()
{
  pinMode(x,INPUT);
  radio.begin(9600);
  Serial.begin(9600);
  Serial.println("Передатчик");
  radio.setChannel(5);
  radio.setDataRate     (RF24_1MBPS);
  radio.setPALevel      (RF24_PA_HIGH);
  radio.openWritingPipe (0x1234567890LL);
}
void loop()
{
  y = analogRead(x);
  delay(100);
  radio.write(&y, sizeof(y));
}
