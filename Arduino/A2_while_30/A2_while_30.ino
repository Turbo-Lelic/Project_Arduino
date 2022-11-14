int LED_PIN = 9;
int LED_PIM = 10;
int LED_PIV = 11;
int i;
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIM, OUTPUT);
  pinMode(LED_PIV, OUTPUT);
  while (i <= 255)
  {
    analogWrite(LED_PIN, i);
    analogWrite(LED_PIM, i);
    analogWrite(LED_PIV, i);
    delay(5);
    i++;
  }
  while (i >=0)
  {
    analogWrite(LED_PIN, i);
    analogWrite(LED_PIM, i);
    analogWrite(LED_PIV, i);
    delay(5);
    i--;
  }
}
void loop()
{

}
