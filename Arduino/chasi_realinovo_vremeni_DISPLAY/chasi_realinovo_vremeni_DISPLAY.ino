#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Icd(0x3f, 16, 2);
DS1302 rtc(5 , 6 , 7);
Time t;

void setup()
{
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);
  rtc.setDOW(FRIDAY);
  rtc.setTime(12, 0, 0);
  rtc.setDate(6, 8, 2022);
  Icd.init();
  Icd.backlight();
  Icd.clear();
  Icd.setCursor(0, 0);
}
void loop()
{
  t = rtc.getTime();

  Serial.print(rtc.getDOWStr());
  Serial.print("");
  Icd.print(rtc.getDOWStr());

  Serial.print(rtc.getDateStr());
  Serial.print("--");
  Icd.print(rtc.getDateStr());

  Serial.println(rtc.getTimeStr());
  Icd.print(rtc.getTimeStr());

  Serial.print(t.date, DEC);
  Serial.print(rtc.getMonthStr());
  Serial.print(t.year, DEC);

  delay(1000);
}
