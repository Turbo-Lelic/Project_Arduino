#include "TM1637.h" 
int8_t DispMSG[] = {1, 2, 3, 4}; 
#define CLK 3
#define DIO 2
TM1637 tm1637(CLK, DIO);
void setup()
{
  tm1637.init();
  tm1637.set(BRIGHTEST);
}
void loop()
{
  tm1637.point(true);
  tm1637.display(DispMSG);
  delay(1000);
  tm1637.point(false);
  tm1637.display(DispMSG);
  delay(1000);
}
