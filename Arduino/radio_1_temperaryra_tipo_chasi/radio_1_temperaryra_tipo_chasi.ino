
#include <DHT.h>
#include <TM1637.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
RF24           radio(9, 10);
int digitoneT;
int digittwoT;
int digitoneH;
int digittwoH;
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  dht.begin();
  delay(1000);
  Serial.begin(9600);
  radio.begin(9600);
  radio.setChannel(5);
  radio.setDataRate     (RF24_1MBPS);
  radio.setPALevel      (RF24_PA_HIGH);
  radio.openWritingPipe (0x1234567890LL);
}
void loop()
{
  
  delay(2000); 
  
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  digitoneT = t / 10;
  digittwoT = t % 10;
  digitoneH = h / 10;
  digittwoH = h % 10;

  Serial.println(t);
  Serial.println(h);

  radio.write(&digitoneT, sizeof(digitoneT));
  radio.write(&digittwoT, sizeof(digittwoT));
  radio.write(&digitoneH, sizeof(digitoneH));
  radio.write(&digittwoH, sizeof(digittwoH));
}
