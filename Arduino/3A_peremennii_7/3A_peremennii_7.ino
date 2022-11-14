int btn1 = 2;
int btn2 = 3;
int pin = 5;
int text = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(pin, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}
void loop()
{
  int btn_1;
  btn_1 = digitalRead(btn1);

  int btn_2;
  btn_2 = digitalRead(btn2);
  
  int df = analogRead(A0);
  if (btn_1 == LOW)
  {
    text = 100;
    Serial.println(text);
    Serial.println(df);
  }
  if (btn_2 == LOW)
  {
    text = 200;
    Serial.println(text);
    Serial.println(df);
  }
  if (df > text)
  {
    digitalWrite(pin, HIGH);
    delay(300);
    digitalWrite(pin, LOW);
    delay(300);
    Serial.println(df);
  }
}
