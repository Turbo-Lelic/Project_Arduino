int k=8;
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9 
MFRC522 mfrc522 (SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;
void setup()
{
pinMode(k,OUTPUT);
Serial.begin(9600);
Serial.println("Waiting for card...");
SPI.begin();
mfrc522.PCD_Init();
}
void loop()
{
if ( ! mfrc522.PICC_IsNewCardPresent())
{
return;
}
if ( ! mfrc522.PICC_ReadCardSerial())
{
return;
}
uidDec = 0;
for (byte i = 0; i < mfrc522.uid.size; i++)
{
uidDecTemp = mfrc522.uid.uidByte[i];
uidDec = uidDec * 256 + uidDecTemp;
}
Serial.println("Card UID: ");
Serial.println(uidDec);
if (uidDec == 2587064457)
{
digitalWrite(k,HIGH);
}
if (uidDec == 3030851990)
{
digitalWrite(k,LOW);
}
}
