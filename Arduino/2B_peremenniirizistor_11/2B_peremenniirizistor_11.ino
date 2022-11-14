int x = A0;
int q = 7;
int w = 8;
int e = 9;
int t = 10;
int y;
void setup()
{
  Serial.begin(9600);
  pinMode(q, OUTPUT);
  pinMode(w, OUTPUT);
  pinMode(t, OUTPUT);  
  pinMode(e, OUTPUT);    
  pinMode(x,INPUT);
}
void loop()
{
  y = analogRead(x);
  Serial.println(y);
  if (y == 200)
  {
    digitalWrite(q, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    delay(y);
  }
  if (y == 400)
  {
    digitalWrite(w, HIGH);
    delay(y);
    digitalWrite(w, LOW);
    delay(y);
  }
    if (y == 600)
  {
    digitalWrite(e, HIGH);
    delay(y);
    digitalWrite(e, LOW);
    delay(y);
  }
    if (y == 800)
  {
    digitalWrite(t, HIGH);
    delay(y);
    digitalWrite(t, LOW);
    delay(y);
  }
}
