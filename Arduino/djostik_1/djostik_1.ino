int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int pin8 = 8;
void setup()
{
  Serial.begin(9600);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
}
void loop()
{
  int x = analogRead(A1);
  int y = analogRead(A2);
  Serial.println("Ocd x = " + (String)x);
  Serial.println("Ocd y = " + (String)y);
  if (x > 510 and x < 550)
  {
    digitalWrite(pin5, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, LOW);
  }
  if (x > 600)
  {
    digitalWrite(pin5, HIGH);
    digitalWrite(pin6, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, LOW);
  }
  if (x < 500)
  {
    digitalWrite(pin5, LOW);
    digitalWrite(pin6, HIGH);
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, LOW);
  }
  if (y > 600)
  {
    digitalWrite(pin5, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin7, HIGH);
    digitalWrite(pin8, LOW);
  }
  if (y < 500)
  {
    digitalWrite(pin5, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, HIGH);
  }
}
