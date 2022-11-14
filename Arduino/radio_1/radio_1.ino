
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
RF24           radio(9, 10);
int            data[2];
void setup()
{
  delay(1000);
  digitalWrite(A1, HIGH);
  pinMode(A1, INPUT);
  digitalWrite(A2, HIGH);
  pinMode(A2, INPUT);
  radio.begin(9600);
  radio.setChannel(5);
  radio.setDataRate     (RF24_1MBPS);
  radio.setPALevel      (RF24_PA_HIGH);
  radio.openWritingPipe (0x1234567890LL);
}
void loop()
{
  data[0] = analogRead(A1);
  data[1] = analogRead(A2);
  delay(100);
  radio.write(&data, sizeof(data));
}
