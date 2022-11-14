int PWMA = 5;
int AIN1 = 7;
int AIN2 = 6;

int PWMB = 11;
int BIN1 = 10;
int BIN2 = 9;

int STBY = 8;

int flag_A = 0;
int flag_B = 0;

int BTN_A = 2;
int BTN_B = 3;

void setup()
{
  pinMode(BTN_A, INPUT);
  pinMode(BTN_B, INPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
}
void loop()
{
  int val_A = digitalRead(BTN_A);
  int val_B = digitalRead(BTN_B);
  delay(100);
  if (val_A == 0)
  {
    flag_A = ! flag_A;
  }
  if (val_B == 0)
  {
    flag_B = ! flag_B;
  }
  if (flag_A == 1)
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  }
  else
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  }
  analogWrite(PWMA, 140);
  if (flag_B == 1)
  {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }
  else
  {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }
  analogWrite(PWMB, 140);
}
