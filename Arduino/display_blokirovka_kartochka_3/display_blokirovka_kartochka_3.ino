#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h> 
#define CLK 2
#define DIO 3
#include "GyverTM1637.h"
GyverTM1637 disp(CLK, DIO);
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;
Servo servo;
void setup() {
disp.clear();
disp.brightness(7); 
Serial.begin(9600);
Serial.println("Waiting for card...");
SPI.begin(); 
mfrc522.PCD_Init(); 
servo.attach(6);
servo.write(0);
}
void loop() {
byte rfid[4] = {_N, _O};
disp.scrollByte(rfid, 300);
if ( ! mfrc522.PICC_IsNewCardPresent()) {
return;
}
if ( ! mfrc522.PICC_ReadCardSerial()) {
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
if (uidDec == 3938923286)
{
byte no[4] = {_N, _O};
disp.scrollByte(no, 300);
delay(1000);
}
if (uidDec == 166315161) 
{
byte troll[4] = {_Y, _E, _S};
disp.scrollByte(troll, 300);
delay(1000);
}
byte n[4] = {_b, _l,_o,_c};
disp.scrollByte(n, 300);
delay(10000);
}
