int p = A0, ledpin_1 = 6, ledpin_2 = 7, ledpin_3 = 8, ledpin_4 = 9, ledpin_5 = 10;
int arr[5] = {ledpin_1, ledpin_2, ledpin_3, ledpin_4, ledpin_5};

void setup() {
  Serial.begin(9600);
  pinMode(p, INPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(arr[i], OUTPUT);
  }
}
void loop() {
  int p_state = analogRead(p);

  if (p_state >= 0 && p_state <= 100) {
    digitalWrite(ledpin_1, HIGH);
  }
  if (p_state >= 101 && p_state <= 200) {
    digitalWrite(ledpin_2, HIGH);
  }
  if (p_state >= 201 && p_state <= 300) {
    digitalWrite(ledpin_3, HIGH);
  }
  if (p_state >= 301 && p_state <= 400) {
    digitalWrite(ledpin_4, HIGH);
  }
  if (p_state >= 401 && p_state <= 500) {
    digitalWrite(ledpin_5, HIGH);
  }
}
