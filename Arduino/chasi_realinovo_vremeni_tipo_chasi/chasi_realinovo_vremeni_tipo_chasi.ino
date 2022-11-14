#include <DS1302.h>
#include <TM1637.h>

#define CLK 3
#define DIO 2

DS1302 rtc(5, 6, 7);
TM1637 tm1637(CLK, DIO);

Time t;
void setup()
{
  t = rtc.getTime();

  Serial.begin(9600);
  tm1637.init();
  rtc.halt(false);
  rtc.writeProtect(false);
  rtc.setTime(12, 0, 0);
}
void loop()
{
  Serial.println(rtc.getTimeStr());
  tm1637.display(t.sec);
  tm1637.display(t.min);
  delay(1000);
}
