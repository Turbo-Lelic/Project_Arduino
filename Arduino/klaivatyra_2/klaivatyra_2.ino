int PinOut [4] {5,4,3,2};
int PinIn [4] {9, 8, 7, 6};
int val = 0;
const char value[4] [4]=
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
int b = 0;
void setup()
{
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,INPUT);
digitalWrite(6,HIGH);
pinMode(7,INPUT);
digitalWrite(7,HIGH);
pinMode(8,INPUT);
digitalWrite(8,HIGH);
pinMode(9,INPUT);
digitalWrite(9,HIGH);
Serial.begin(9600);
}
void matrix()
{
for (int i = 1;i <= 4;i++)
{
digitalWrite(PinOut[i - 11], LOW);
for (int j = 1; j <= 4;j++)
{
if (digitalRead(PinIn[j - 1]) == LOW)  
{
Serial.println( value[i - 1][j - 1]);
delay(175);
}
}
digitalWrite(PinOut[i - 1],HIGH);
}
}
void loop()
{
matrix();
}







  
