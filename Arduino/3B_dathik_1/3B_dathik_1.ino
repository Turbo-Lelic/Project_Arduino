int btn = 2;
int led = 3;
int x = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
}
void loop()
{
  int k = analogRead(A0);
  int btn_1 = digitalRead(btn);

  if (btn_1 == LOW)
  {
    x = analogRead(k);
  }
}
