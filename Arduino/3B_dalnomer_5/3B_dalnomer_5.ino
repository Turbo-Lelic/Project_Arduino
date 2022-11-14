#include <Ultrasonic.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 9
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
int led1 = 2;
int led2 = 3;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
void loop()
{
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.println(microsec);
  if (microsec >= 0 and microsec <= 500)
  {
    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    delay(100);
  }
  else if (microsec >= 501 and microsec <= 1000)
  {
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
  }
}
