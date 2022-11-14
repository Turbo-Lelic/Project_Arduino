#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Icd(0x27, 16, 2);

int IN1 = 9;
int IN2 = 10;
int IN3 = 6;
int IN4 = 5;

#define PORT_BTN1 A7
#define SERNSOR_LINE_PORT A0
#define SERNSOR_T_PORT A1

#define BASE_SPEED 100
#define K1 0.8
#define SPEED_MAX 120

int i, gray, flag;
int white, black;

void setup()
{
  Serial.begin(9600);
  Icd.init();
  Icd.backlight();
  Icd.print("Ready");
  delay(100);
  
  pinMode(SERNSOR_LINE_PORT, 0);
  pinMode(SERNSOR_T_PORT, 0);
  digitalWrite(SERNSOR_LINE_PORT, 1);
  digitalWrite(SERNSOR_T_PORT, 1);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  while (digitalRead(PORT_BTN1) != 0)
  {
    white = analogRead(SERNSOR_LINE_PORT);
    delay(200);
    Icd.clear();
    Icd.setCursor(0, 0);
    Icd.print(white);
  }
  delay(2000);
  while (digitalRead(PORT_BTN1) != 0)
  {
    black = analogRead(SERNSOR_LINE_PORT);
    delay(200);
    Icd.clear();
    Icd.setCursor(0, 0);
    Icd.print(black);
  }
  delay(1000); 
  while (digitalRead(PORT_BTN1) != 0)delay(100);
  analogWrite(IN2, BASE_SPEED);
  analogWrite(IN1, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, BASE_SPEED);
  int ks = 3000;
  for (int i = 0; i < ks; i++)
  {
    if (analogRead(SERNSOR_LINE_PORT) < white) white = analogRead
          (SERNSOR_LINE_PORT);
    if (analogRead(SERNSOR_LINE_PORT) > black) black = analogRead
          (SERNSOR_LINE_PORT);
    delay(5);
  }
  analogWrite(IN2, 0);
  analogWrite(IN1, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
  delay(2000);
  gray = (white + black) / 2;
  delay(100);
  Icd.clear();
  Icd.setCursor(0, 0);
  Icd.print("b: " + (String)black);
  Icd.setCursor(0,1);
  Icd.print("w: " + (String)white + "gr: " + (String)gray);
  delay(1000);
}
void loop()
{
  if (flag == 0)
  {
    while (digitalRead(PORT_BTN1) != 0)delay(100);
    delay(200);
    flag = 1;
  }
  if (flag == 1)
  {
    go_line();
  }
}
void go_line()
{
  int e = analogRead(SERNSOR_LINE_PORT) - gray;
  //int u = (K1 * e) + ((e * e * e) * 0.000001);
  int u = K1 * e;

  int _left = BASE_SPEED - u;
  int _right = BASE_SPEED + u;

  int left = constrain(_left, -SPEED_MAX, SPEED_MAX);
  int right = constrain(_right, -SPEED_MAX, SPEED_MAX);

  if (left >= 0)
  {
    analogWrite(IN2, 0);
    analogWrite(IN1, abs(left));
  }
  else
  {
    analogWrite(IN2, abs(left));
    analogWrite(IN1, 0);
  }
  if (right >= 0)
  {
    analogWrite(IN3, 0);
    analogWrite(IN4, abs(right));
  }
  else
  {
    analogWrite(IN3, abs(right));
    analogWrite(IN4, 0);
  }
}
