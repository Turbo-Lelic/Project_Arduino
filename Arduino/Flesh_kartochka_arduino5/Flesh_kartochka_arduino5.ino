#include <SPI.h>
#include <SD.h>

void setup()
{
Serial.begin(9600);
while(!Serial);
if (!SD.begin())
{
Serial.println("Initialization failed");
while(true);
}
Serial.println("Card OK");
Serial.println("Type: ");
File root = SD.open("/");
printRoot(root);
}
void loop()
{

}
void printRoot (File dir)
{
while(true)
{
File entry = dir.openNextFile();
if (! entry)
{
break;
}
Serial.print(entry.name());
if (entry.isDirectory())
{
Serial.println("/");
printRoot(entry);
} else {
Serial.print("\t\t\t\t");
Serial.println(entry.size(), DEC);
}
}
}
