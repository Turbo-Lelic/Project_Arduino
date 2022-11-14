#include <SPI.h>
#include <SD.h>
void setup()
{
Serial.begin(9600);
while(!Serial);
Serial.println("Ожидание вставки карты");
delay(1000);
if (!SD.begin())
{
Serial.println("Сбой инициализации");
while(true);
}
Serial.println("Катра в норме");
File myFile = SD.open("information", FILE_WRITE);
String e = "Меня зовут Алексеев Алексей";
String p = "Мой возраст";
int i = 12;
String m = "Мой вес";
float f = 44.9;
myFile.println(e);
myFile.println(p);
myFile.println(i);
myFile.println(m);
myFile.println(f);
myFile.close();
Serial.println("Cделано");
}
void loop()
{

}
