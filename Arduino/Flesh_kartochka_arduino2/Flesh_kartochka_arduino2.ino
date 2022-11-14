#include <SPI.h>
#include <SD.h>
void setup()
{
Serial.begin(9600);
while(!Serial);
if (!SD.begin())
{
Serial.println("Initialization\failed");
while(true);
}
Serial.println("Card OK");
File myFile = SD.open("information");
while(myFile.available())
myFile.close();
}
void loop()
{

}
