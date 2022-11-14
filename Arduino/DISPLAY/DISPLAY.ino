#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Icd(0x27///3, 16, 2);
void setup()
{
  Icd.init();
  Icd.backlight();
  Icd.print("HI I AM ROBOT");
}
void loop()
{

}
