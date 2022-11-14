int q = 7;
int w = 8;
int e = 9;
int r = 10;
int t = 11;
void setup()
{
  pinMode(q, OUTPUT);
  pinMode(w, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(t, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(t, HIGH);
    delay(100);
    digitalWrite(t, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(e, HIGH);
    delay(100);
    digitalWrite(e, LOW);
    delay(100);
  }
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(q, HIGH);
    delay(100);
    digitalWrite(q, LOW);
    delay(100);
  }
}
void loop()
{

}
