int PWMA = 5;
int AIN1 = 7;
int AIN2 = 6;
int STBY = 8;

void setup()
{
  pinMode(PWMA,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(STBY,OUTPUT);
  digitalWrite(STBY,HIGH);
}
void loop()
{
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  analogWrite(PWMA,140);
}
