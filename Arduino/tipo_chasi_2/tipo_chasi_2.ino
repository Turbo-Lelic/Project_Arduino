
#include <DHT.h>
#include <TM1637.h>

#define DHTPIN 2
#define CLK 3
#define DIO 2

#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
TM1637 tm1637(CLK, DIO);
void setup()
{
  tm1637.init();

  Serial.begin(9600);
  dht.begin();
}
void loop()
{
  delay(2000);
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  int digitoneT = t / 10;
  int digittwoT = t % 10;
  int digitoneH = h / 10;
  int digittwoH = h % 10;
  tm1637.display(1, digitoneT);
  tm1637.display(2, digittwoT);
  delay(5000);
  tm1637.display(1, digitoneH);
  tm1637.display(2, digittwoH);
  delay(5000);
}
