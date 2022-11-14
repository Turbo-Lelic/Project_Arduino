int pinsout[] = {A7, A6, A5, A4};
int pinsin[] = {A3, A2, A1, A0};
const char keys[4][4] = {{'1', '2', '3', 'A'},

  {'4', '5', '6', 'B'},

  {'7', '8', '9', 'C'},

  {'*', '0', '#', 'D'}
};
int tekstr = 0;

void setup()
{
  for (int i = 0; i < 4; i++) {
    pinMode(pinsout[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(pinsin[i], INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (j == tekstr)digitalWrite(pinsout[j], LOW);
      else digitalWrite(pinsout[j], HIGH);
    }
    for (int j = 0; j < 4; j++)
    {
      if (digitalRead(pinsin[j]) == LOW)
      {
        Serial.print("button=");
        Serial.println(keys[i][j]);
        delay(100);
      }
    }
    tekstr = tekstr + 1;
  }
  tekstr = 0;
}
