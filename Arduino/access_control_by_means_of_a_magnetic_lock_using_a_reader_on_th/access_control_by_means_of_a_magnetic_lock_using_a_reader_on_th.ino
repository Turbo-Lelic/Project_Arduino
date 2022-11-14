#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;
int Magnit = 4;
int Button = 2;
void setup() {
  pinMode(Magnit, OUTPUT);
  pinMode(Button, INPUT);
  Serial.begin(9600);
  Serial.println("Waiting for card...");
  SPI.begin();
  mfrc522.PCD_Init();
}
void loop() {
  digitalWrite(Magnit, LOW);
  if (digitalRead(Button) == 0) {
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

    if (uidDec == 3951204253 or uidDec == 96859006)
    {
      tone(5, 200, 500);
      digitalWrite(Magnit, HIGH);
      delay(10000);
      tone(5, 500, 500);
      digitalWrite(Magnit, LOW);
    }
  }
  else {
    tone(5, 200, 500);
    digitalWrite(Magnit, HIGH);
    delay(10000);
    tone(5, 500, 500);
    digitalWrite(Magnit, LOW);
  }
}
