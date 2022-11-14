int led = 9;
int led1 = 10;
int led2 = 11;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(led, i);
    delay(5);
    analogWrite(led, i);
    delay(5);
  }
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(led1, i);
    delay(5);
    analogWrite(led1, i);
    delay(5);
  }
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(led2, i);
    delay(5);
    analogWrite(led2, i);
    delay(5);
  }
}
void loop()
{

}
