int x = 1000;
void setup() {
  Serial.begin(9600);
}
void loop() {
  while (x > 6) {
    x -= 7;
    delay(5);
    Serial.println("1000-7 = " + (String)x);
  }
  if (x == 6) {
    Serial.print("I Ded Intel Sid");
    x += -1;
  }
}
