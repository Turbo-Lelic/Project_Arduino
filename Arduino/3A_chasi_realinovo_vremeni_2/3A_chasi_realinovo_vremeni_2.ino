#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Icd(0x3f, 16, 2);
DS1302 rtc(5 , 6 , 7);
Time t;
int btn1 = 8;
int btn2 = 9;
int btn3 = 10;

void setup()
{
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);
  rtc.setDOW(FRIDAY);
  rtc.setTime(12, 0, 0);
  rtc.setDate(6, 8, 2022);
}
void loop()
{
  t = rtc.getTime();

  int btn_1;
  btn_1 = digitalRead(btn1);

  int btn_2;
  btn_2 = digitalRead(btn2);

  int btn_3;
  btn_3 = digitalRead(btn3);

  if (btn_1 == LOW)
  {
    Icd.print(rtc.getDOWStr());
    delay(1000);
    Icd.clear();
  }
  else if (btn_2 == LOW)
  {
    Icd.print(rtc.getDateStr());
    delay(1000);
    Icd.clear();
  }
  else if (btn_3 == LOW)
  {
    Icd.print(rtc.getTimeStr());
    delay(1000);
    Icd.clear();
  }
}
