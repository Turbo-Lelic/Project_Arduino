#include <Servo.h>
#define servoPin 9
#define servoMinImp 544
#define servoMaxImp 2400
Servo myServo;
int btn = 2;
int Pin = 4;
int x = 0;
void setup()
{
  Serial.begin(9600);
  myServo.attach(servoPin, servoMinImp, servoMaxImp);
  pinMode(btn, INPUT);
  pinMode(A0, INPUT);
  pinMode(Pin, OUTPUT);
}
void loop()
{
  int btn_1;
  btn_1 = digitalRead(btn);

  int df = analogRead(A0);
  if (btn_1 == LOW)
  {
    x += 1;
  }
  if (x == 1 and btn_1 == LOW)
  {
    digitalWrite(Pin, HIGH);
    delay(100);
    digitalWrite(Pin, LOW);
    delay(100);
  }
  if (x == 2 and btn_1 == LOW)
  {
    myServo.writeMicroseconds(servoMinImp);
    delay(300);
    myServo.writeMicroseconds(1520);
    delay(300);
    myServo.writeMicroseconds(servoMaxImp);
    delay(300);
  }
  if (x == 3 and btn_1 == LOW)
  {
    myServo.writeMicroseconds(servoMaxImp);
    delay(300);
    myServo.writeMicroseconds(1520);
    delay(300);
    myServo.writeMicroseconds(servoMinImp);
    delay(300);
  }
  if (x == 4 and btn_1 == LOW)
  {
    Serial.println(df);
  }
}
