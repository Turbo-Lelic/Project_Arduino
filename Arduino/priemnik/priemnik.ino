String msg="";
String msg1,msg2;
void setup()
{
Serial.begin(9600);
}
void loop()
{
while(!Serial.available())delay(20);
delay(200);
while(Serial.available())
msg = msg + (char)(Serial.read());
msg1=msg.substring(msg.indexOf("T1")+2,msg.indexOf("1T"));
msg2=msg.substring(msg.indexOf("T2")+2,msg.indexOf("2T"));
}













