int n1 = 2;
int n2 = 3;
int n3 = 4;
int n4 = 5;
int n5 = 6;
int btn = 7;
int btn1 = 8;
int i;
void setup()
{
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);
  pinMode(n5, OUTPUT);
  pinMode(btn, INPUT);
  pinMode(btn1, INPUT);
}
void loop()
{

  int btn_q;
  btn_q = digitalRead(btn);

  int btn_w;
  btn_w = digitalRead(btn1);
  {
    if (btn_q == LOW)
    {
      while (i < 6)
      {
        digitalWrite(n1, HIGH);
        delay(100);
        digitalWrite(n1, LOW);
        delay(100);
        digitalWrite(n2, HIGH);
        delay(100);
        digitalWrite(n2, LOW);
        delay(100);
        digitalWrite(n3, HIGH);
        delay(100);
        digitalWrite(n3, LOW);
        delay(100);
        digitalWrite(n4, HIGH);
        delay(100);
        digitalWrite(n4, LOW);
        delay(100);
        digitalWrite(n5, HIGH);
        delay(100);
        digitalWrite(n5, LOW);
        delay(100);
        i++;
      }
      if (btn_w == LOW)
      {
        while (i < 6)
        {
        digitalWrite(n5, HIGH);
        delay(100);
        digitalWrite(n5, LOW);
        delay(100);
        digitalWrite(n4, HIGH);
        delay(100);
        digitalWrite(n4, LOW);
        delay(100);
        digitalWrite(n3, HIGH);
        delay(100);
        digitalWrite(n3, LOW);
        delay(100);
        digitalWrite(n2, HIGH);
        delay(100);
        digitalWrite(n2, LOW);
        delay(100);
        digitalWrite(n1, HIGH);
        delay(100);
        digitalWrite(n1, LOW);
        delay(100);
        i++;
        }
      }
    }
  }
}
