
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
RF24 radio(9,10);
byte address[][6] = {"1Node","2Node","3Node","4Node","5Node","6Node"};
void setup(){
  Serial.begin(9600);
  radio.begin();
  radio.setAutoAck(1);
  radio.setRetries(0,15);
  radio.enableAckPayload();
  radio.setPayloadSize(32);
  radio.openReadingPipe(1,address[0]);
  radio.setChannel(0x60);
  radio.setPALevel (RF24_PA_MAX);
  radio.setDataRate (RF24_250KBPS);
  radio.powerUp();
  radio.startListening();
}
void loop() 
{
char gotByte[8];
byte pipeNo; 
while( radio.available(&pipeNo))
{
radio.read(&gotByte, sizeof(gotByte) );
}
for (byte i = 0; i < sizeof(gotByte); i++) 
{
Serial.print(gotByte[i]);
}
Serial.println();
}
