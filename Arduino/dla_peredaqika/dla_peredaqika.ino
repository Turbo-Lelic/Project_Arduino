String msg;
#define PIN_direction_TX_RX 7 
void setup()
{
Serial.begin(9600);
pinMode(PIN_direction_TX_RX,OUTPUT);
digitalWrite(PIN_direction_TX_RX,LOW);
}
void loop()
{
int btn = digitalRead(2);
if(btn == 0)
{
digitalWrite(PIN_direction_TX_RX,HIGH);
delay(10);
msg = "T11231TT24562T";
Serial.print(msg);
Serial.flush();
delay(10);
digitalWrite(PIN_direction_TX_RX,LOW);
delay(10);
}
}


















