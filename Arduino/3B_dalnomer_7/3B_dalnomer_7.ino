#include <Ultrasonic.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 9
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
int led1 = 2;
int led2 = 3;
int btn = 4;
int flag = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(btn, INPUT);
}
void loop()
{
  int btn_1 = digitalRead(btn);
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.println(microsec);
  if (btn_1 == LOW)
  {
    flag += 1;
  }
  else if (flag == 1 and btn_1 == LOW)
  {
    analogWrite(led1, microsec);
    delay(100);
    analogWrite(led1, microsec);
    delay(100);
  }
  else if (flag == 2 and btn_1 == LOW)
  {
    analogWrite(led2, microsec);
    delay(100);
    analogWrite(led2, microsec);
    delay(100);
  }
}
