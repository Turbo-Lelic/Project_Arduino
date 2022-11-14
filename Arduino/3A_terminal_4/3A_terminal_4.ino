#include <DHT.h>
#define DHTPIN 2
DHT dht(DHTPIN, DHT11);
int btn1 = 5;
int btn2 = 6;
int btn3 = 7;
void setup()
{
  dht.begin();
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}
void loop()
{
  int btn_1 = digitalRead(btn1);
  int btn_2 = digitalRead(btn2);
  int btn_3 = digitalRead(btn3);

  int td = analogRead(A0);
  int fd = analogRead(A1);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (btn_1 == LOW)
  {
    Serial.println(td);
  }
  if (btn_2 == LOW)
  {
    Serial.println(fd);
  }
  if (btn_3 == LOW)
  {
    Serial.println(h);
    Serial.println(t);
    Serial.println(f);
  }
}
