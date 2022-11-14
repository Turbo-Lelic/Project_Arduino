#include <Ultrasonic.h>
#define TRIGGER_PIN 9
#define ECHO_PIN 8
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup()
{
Serial.begin(9600);
}
void loop()
{
float cmMsec, inMsec;
long microsec = ultrasonic.timing();

cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
Serial.print("MS: ");
Serial.print(microsec);
Serial.print(", CM: ");
Serial.print(cmMsec);
delay(1000);
}
