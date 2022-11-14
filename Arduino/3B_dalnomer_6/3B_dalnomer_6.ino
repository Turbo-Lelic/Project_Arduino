#include <Ultrasonic.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 9
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}
void loop()
{
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.println(microsec);
  if (microsec >= 0 and microsec <= 100)
  {
    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    delay(100);
  }
  else if (microsec >= 101 and microsec <= 200)
  {
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
  }
  else if (microsec >= 201 and microsec <= 300)
  {
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    delay(100);
  }
  else if (microsec >= 301 and microsec <= 400)
  {
    digitalWrite(led4, HIGH);
    delay(100);
    digitalWrite(led4, LOW);
    delay(100);
  }
  else if (microsec >= 401 and microsec <= 500)
  {
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led5, LOW);
    delay(100);
  }
}
