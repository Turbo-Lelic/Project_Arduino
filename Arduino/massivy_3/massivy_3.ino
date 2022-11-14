int x[]={2,-13,4,-56,45,-68,5};
void setup()
{
delay(1000);
int o,p;
Serial.begin(9600);
for(int i=0;i<7;i++)
{
if(x[i]<0) o++;
if(x[i]>0) p++;
}
Serial.println("o="+(String)o+" p="+(String)p);
}
void loop()
{



}
