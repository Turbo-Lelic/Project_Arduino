#include <Ultrasonic.h>
#include <LiquidCrystal_I2C.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 9
int btn1 = 6;
int led1 = 3;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(btn1, INPUT);
  pinMode(led1, OUTPUT);
}
void loop()
{
  int btn_1 = digitalRead(btn1);
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.println(microsec);
  if (microsec == 10 and btn_1 == LOW)
  {
    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("Flashing 1");
  }
  if (microsec == 20 and btn_1 == LOW)
  {
    for (int q = 0; q < 2; q++)
    {
      digitalWrite(led1, HIGH);
      delay(100);
      digitalWrite(led1, LOW);
      delay(100);
      lcd.setCursor(0, 0);
      lcd.print("Flashing 2");
    }
    if (microsec == 30 and btn_1 == LOW)
    {
      for (int w = 0; w < 3; w++)
      {
        digitalWrite(led1, HIGH);
        delay(100);
        digitalWrite(led1, LOW);
        delay(100);
        lcd.setCursor(0, 0);
        lcd.print("Flashing 3");
      }
      if (microsec == 40 and btn_1 == LOW)
      {
        for (int e = 0; e < 4; e++)
        {
          digitalWrite(led1, HIGH);
          delay(100);
          digitalWrite(led1, LOW);
          delay(100);
          lcd.setCursor(0, 0);
          lcd.print("Flashing 4");
        }
        if (microsec == 50 and btn_1 == LOW)
        {
          for (int r = 0; r < 5; r++)
          {
            digitalWrite(led1, HIGH);
            delay(100);
            digitalWrite(led1, LOW);
            delay(100);
            lcd.setCursor(0, 0);
            lcd.print("Flashing 5");
          }
          if (microsec == 60 and btn_1 == LOW)
          {
            for (int t = 0; t < 6; t++)
            {
              digitalWrite(led1, HIGH);
              delay(100);
              digitalWrite(led1, LOW);
              delay(100);
              lcd.setCursor(0, 0);
              lcd.print("Flashing 6");
            }
          }
        }
      }
    }
  }
}
