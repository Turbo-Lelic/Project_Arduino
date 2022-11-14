#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int btn1 = 3;
int btn2 = 4;
#define servoPin1 9
#define servoMinImp1 544
int servoMaxImp1 = 2400;
#define servoPin2 10
#define servoMinImp2 544
int servoMaxImp2 = 2400;
Servo myServo1;
Servo myServo2;
void setup()
{
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.setCursor(0, 0);
  myServo1.attach(servoPin1, servoMinImp1, servoMaxImp1);
  myServo2.attach(servoPin2, servoMinImp2, servoMaxImp2);
  lcd.println(servoMaxImp1);
  lcd.println(servoMaxImp2);
}
void loop()
{
  int btn_1 = digitalRead(btn1);
  int btn_2 = digitalRead(btn2);
  if (btn_1 == LOW)
  {
    servoMaxImp1 = 2200;
  }
  if (btn_2 == LOW)
  {
    servoMaxImp2 = 2200;
  }
}
