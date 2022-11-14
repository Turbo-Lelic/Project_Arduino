int btn1 = 2;
int btn2 = 3;
void setup()
{
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}
void loop()
{
  int btn_1;
  btn_1 = digitalRead(btn1);

  int btn_2;
  btn_2 = digitalRead(btn2);
  if (btn_1 == LOW)
  {
    Serial.print("Привет:)");
  }
  if (btn_2 == LOW)
  {
    Serial.print("До свидания:(");
  }
}
