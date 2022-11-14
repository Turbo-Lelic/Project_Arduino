#include "SPI.h"
#include "SD.h"
#include "iarduino_RTC.h"

iarduino_RTC time(RTC_DS1307);
File myFile;

const uint8_t SOUND_SENSOR = A1;
String REAL_TIME;
uint16_t LOUDNESS;
void setup()
{
Serial.begin(9600);
pinMode(SOUND_SENSOR, INPUT);
time.begin();
time.settime(0, 15, 15, 14, 5, 19, 2);
if (SD.begin())
{
Serial.println("Initialization failed");
while (true);
}
Serial.println("Card OK");
}
void loop()
{
if (millis() % 5000 == 0)
{
REAL_TIME = time.gettime("d-m-Y, H:i:s");
LOUDNESS = analogRead(SOUND_SENSOR);
myFile = SD.open("test.txt", FILE_WRITE);
myFile.print(REAL_TIME);
myFile.print(",");
myFile.println(LOUDNESS);
myFile.close();
}
}
