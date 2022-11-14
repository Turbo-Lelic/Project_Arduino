#include <DS1302.h>
DS1302 rtc(5, 6, 7);

void setup()
{
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);
  rtc.setDOW(FRIDAY);
  rtc.setTime(12, 0, 0);
  rtc.setDate(6, 8, 2022);
}
void loop()
{
  Serial.print(rtc.getDOWStr());
  Serial.print("");

  Serial.print(rtc.getDateStr());
  Serial.print("--");

  Serial.println(rtc.getTimeStr());

  delay(1000);
}
