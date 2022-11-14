int p = A0, ledpin_1 = 8, ledpin_2 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(p, INPUT);
  pinMode(ledpin_1, OUTPUT);
  pinMode(ledpin_2, OUTPUT);
}
void loop() {
  int p_state = analogRead(p);

  if (p_state >= 0 && p_state <= 500) {
    digitalWrite(ledpin_1, HIGH);
  }
  if (p_state >= 501 && p_state <= 1023) {
    digitalWrite(ledpin_2, HIGH);
  }
}
