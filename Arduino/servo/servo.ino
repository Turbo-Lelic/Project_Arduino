#include <Servo.h>
#define servoPin 9 
#define servoMinImp 544
#define servoMaxImp 2400
Servo myServo;
void setup()
{
  myServo.attach(servoPin, servoMinImp, servoMaxImp);
}
void loop()
{
  myServo.writeMicroseconds(servoMinImp);
  delay(300);
  
  myServo.writeMicroseconds(1520);
  delay(300);
  
  myServo.writeMicroseconds(servoMaxImp);
  delay(300);
}
