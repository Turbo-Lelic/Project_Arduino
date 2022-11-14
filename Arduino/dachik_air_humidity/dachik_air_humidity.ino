#include <DHT.h>
#define DHTPIN 2
DHT dht(DHTPIN, DHT11);
void setup()
{
  Serial.begin(9600);
  dht.begin();
}
void loop()
{
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  Serial.print("Влажность : ");
  Serial.println(h);

  Serial.print("Температура : ");
  Serial.print(t);
  Serial.print(" *C, ");
  Serial.print(f);
  Serial.println(" *F");
}
