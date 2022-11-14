int x = A0;
int q = 7;
int w = 8;
int e = 9;
int y;
void setup()
{
  Serial.begin(9600);
  pinMode(q, OUTPUT);
  pinMode(w, OUTPUT);
  pinMode(e, OUTPUT);
}
void loop()
{
  y = analogRead(x);
  Serial.println(y);
  if (y == 200)
  {
    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    digitalWrite(e, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    digitalWrite(e, LOW);
    delay(y);
  }
  if (y == 400)
  {
    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    digitalWrite(e, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    digitalWrite(e, LOW);
    delay(y);  
    
    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    digitalWrite(e, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    digitalWrite(e, LOW);
    delay(y);  
  }
  if (y == 600)
  {
    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    digitalWrite(e, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    digitalWrite(e, LOW);
    delay(y);  
    
    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    digitalWrite(e, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    digitalWrite(e, LOW);
    delay(y);  

    digitalWrite(q, HIGH);
    digitalWrite(w, HIGH);
    digitalWrite(e, HIGH);
    delay(y);
    digitalWrite(q, LOW);
    digitalWrite(w, LOW);
    digitalWrite(e, LOW);
    delay(y);  
  }
}  
