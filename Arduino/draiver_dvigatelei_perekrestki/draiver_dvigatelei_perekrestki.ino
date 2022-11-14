#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Icd(0x27, 16, 2);

#define AIN2 5
#define AIN1 6

#define BIN1 9
#define BIN2 10

#define PORT_BTN1 A7
#define SERNSOR_LINE_PORT A1
#define SERNSOR_T_PORT A3

#define BASE_SPEED 75
#define K1 0.6
#define SPEED_MAX 125

int i, gray, wigth, black, wight1, black1, gray1, wight2, wight3, black2, black3, gray2, gray3, flag, p;

void go_line();
void A_motor(int enc, int speed);
void A_motor_stop(void);
void B_motor(int enc, int speed);
void B_motor_stop(void);
void AB_stop();

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

  for (int i = 5; i < 12; i++)
  {
    pinMode(i, OUTPUT);
  }
  AB_stop();
  while (analogRead(PORT_BTN1) > 512)
  {
    wight2 = analogRead(SERNSOR_LINE_PORT);
    wigth = analogRead(A0);
    wight1 = analogRead(A3);
    wight3 = analogRead(A2);
    delay(100);
    Icd.clear();
    Icd.setCursor(0, 0);
    Icd.print("Wight: ");
    Icd.print(wight2);
  }
  delay(1000);


  while (analogRead(PORT_BTN1) > 512)
  {
    black2 = analogRead(SERNSOR_LINE_PORT);
    black = analogRead(A0);
    black1 = analogRead(A1);
    black3 = analogRead(A3);
    delay(100);
    Icd.clear();
    Icd.setCursor(0, 0);
    Icd.print("Black: ");
    Icd.print(black2);
  }
  delay(1000);

  gray2 = (wight2 + black2) / 2;
  gray = (wigth + black) / 2;
  gray1 = (wight1 + wight1) / 2;
  gray3 = (wight3 + wight3) / 2;

  Icd.clear();
  Icd.setCursor(0, 0);
  Icd.print((String)"g: " + gray + "g1:" + gray1);

  Icd.setCursor(0, 1);
  Icd.print((String)"g2: " + gray2 + "g3:" + gray3);
  delay(1000);
}
void loop()
{
  if (flag == 0)
  {
    while (analogRead(PORT_BTN1) > 512)delay(100);
    delay(200);
    flag = 1;
  }
  if (flag == 1)
  {
    go_line();

    int s1 = analogRead(A0);
    int s2 = analogRead(A3);

    if ((s1 > gray1) or (s2 > gray2))
    {
      p++;
      Icd.setCursor(15, 0); Icd.print(p);
      AB_stop();
      delay(500);
      mot_forward();
      delay(100);
      AB_stop();
      delay(500);
      if (p == 1)
      {
        flag = 2;
      }
      else if (p == 2)
      {
        flag = 3;
      }
      else if (p == 3)
      {
        flag = 4;
      }
      else if (p == 4)
      {
        flag = 5;
      }
      else if (p == 5)
      {
        flag = 6;
      }
    }
  }
  else if (flag == 2)
  {
    mot_forward();
    delay(50);
    flag = 1;
  }
  else if (flag == 3)
  {
    mot_right();
    flag = 1;
  }
  else if (flag == 4)
  {
    AB_stop();
  }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void go_line()
{

  int e = analogRead(SERNSOR_LINE_PORT) - gray2;
  int u = K1 * e;
  int _left = BASE_SPEED - u;
  int _right = BASE_SPEED + u;

  int left = constrain(_left, -SPEED_MAX, SPEED_MAX);
  int right = constrain(_right, -SPEED_MAX, SPEED_MAX);

  if (left >= 0)
  {
    A_motor(1, abs(left));
  }
  else
  {
    A_motor(0, abs(left));
  }

  if (right >= 0)
  {
    B_motor(0, abs(right));
  }
  else
  {
    B_motor(1, abs(right));
  }
}
void mot_forward()
{
  A_motor(1, BASE_SPEED + 30);
  B_motor(0, BASE_SPEED);
}
void mot_left()
{
  while (analogRead(A3) < gray3)
  {
    A_motor(1, BASE_SPEED + 50);
    B_motor(1, BASE_SPEED + 50);
  }
  AB_stop();
  delay(1000);

  while (analogRead(A1) < gray1)
  {
    A_motor(1, BASE_SPEED + 50);
    B_motor(1, BASE_SPEED + 50);
  }
  AB_stop();
  delay(1000);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void mot_right()
{
  while (analogRead(A0) < gray)
  {
    A_motor(0, BASE_SPEED + 50);
    B_motor(0, BASE_SPEED + 50);
  }
  AB_stop();
  delay(1000);

  while (analogRead(A2) < gray2)
  {
    A_motor(0, BASE_SPEED + 50);
    B_motor(0, BASE_SPEED + 50);
  }
  AB_stop();
  delay(1000);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void A_motor(int enc, int speed)
{
  analogWrite(AIN2, enc ? speed : 0);
  analogWrite(AIN1, enc ? 0 : speed);
}
void A_motor_stop(void)
{
  analogWrite(AIN2, 0);
  analogWrite(AIN1, 0);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void B_motor(int enc, int speed)
{
  analogWrite(BIN2, enc ? speed : 0);
  analogWrite(BIN1, enc ? 0 : speed);
}
void B_motor_stop(void)
{
  analogWrite(BIN2, 0);
  analogWrite(BIN1, 0);
}
void AB_stop()
{
  A_motor_stop();
  B_motor_stop();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
