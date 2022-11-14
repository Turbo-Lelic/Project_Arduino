int PWMA = 5;
int AIN1 = 7;
int AIN2 = 6;

int PWMB = 11;
int BIN1 = 10;
int BIN2 = 9;

int STBY = 8;
void setup()
{
  pinMode(PWMA,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  
  pinMode(PWMB,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  
  pinMode(STBY,OUTPUT);
  digitalWrite(STBY,HIGH);
}
void loop()
{
 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,LOW);
 analogWrite(PWMA,140);

 digitalWrite(BIN1,LOW);
 digitalWrite(BIN2,HIGH);
 analogWrite(PWMB,140);
}
