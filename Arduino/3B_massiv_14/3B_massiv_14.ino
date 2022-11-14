int x[3] = {7, 8, 9};
int y[3] = {0, 0, 0};
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 3; i++)
  {
    pinMode(x[i], INPUT);
  }
  for (int q = 0; q < 3; q++)
  {
    y[q] = digitalRead(x[q]);
  }
  delay(2000);
  Serial.println("btn1 = " + (String) y[0]);
  Serial.println("btn2 = " + (String) y[1]);
  Serial.println("btn3 = " + (String) y[2]);
}
void loop()
{

}
