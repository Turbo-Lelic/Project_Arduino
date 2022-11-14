#include <SPI.h>
#include <SD.h>

char c = 0;
int i = 0;
float f = 0;
String s = "";
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
File myFile = SD.open ("file.txt");
if (!myFile)
{
Serial.println("file not found");
while (true);
}
else
{
char Bytes[10];
int k = 0;
while(myFile.available() &&
((Bytes[k] = myFile.read()) != '\n')) ++k;
c = Bytes[0];
k = 0;
while(myFile.available() &&
((Bytes[k] = myFile.read()) != '\n')) ++k;
i = atoi(Bytes);
k = 0;
while(myFile.available() &&
((Bytes[k] = myFile.read()) != '\n')) ++k;
f = atof(Bytes);
while(myFile.available() &&
((s += char(myFile.read()))));
myFile.close();
SD.remove("file.txt");
}
}
void loop()
{
Serial.println(c);
Serial.println(i);
Serial.println(f);
Serial.println(s);
delay(i*100);
}
