
String msg = "";
String ask;
int _flag;
int flag;
#define PIN_direction_TX_RX 7
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_direction_TX_RX, OUTPUT);
  digitalWrite(PIN_direction_TX_RX, LOW);
}
void loop()
{
  int btn = digitalRead(5);
  if (btn==0) _flag = 1;
  if (_flag == 1)
  {
    delay(200);
    digitalWrite(PIN_direction_TX_RX, HIGH);
    delay(10);
    String msg = "T16781T";
    Serial.print(msg);
    Serial.flush();
    delay(100);
    delay(1);
    digitalWrite(PIN_direction_TX_RX, LOW);
    delay(10);
    _flag = 2;
  }
  if (_flag == 2)
  {
    String ask = "";
    while (!Serial.available()) delay(20);
    delay(200);
    while (Serial.available())
      ask = ask + (char)(Serial.read());
    String _t, _h;
    _t = ask.substring(ask.indexOf("T1") + 2, ask.indexOf("1T"));
    _h = ask.substring(ask.indexOf("T2") + 2, ask.indexOf("2T"));
    int t = _t.toInt();
    int h = _h.toInt();
    _flag = 0;
  }
}
