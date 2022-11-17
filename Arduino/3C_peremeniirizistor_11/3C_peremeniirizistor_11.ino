int peremeniirizistor = A0, btn = 3, a = 0, b = 0, c = 0, d = 0, f = 0, cnt = 0;
int arr_int[5] = {a, b, c, d, f};

void setup() {
  Serial.begin(9600);
  pinMode(peremeniirizistor, INPUT);
  pinMode(btn, INPUT);
}
void loop() {
  int peremeniirizistor_state = analogRead(peremeniirizistor), btn_state = digitalRead(btn);

  if (btn_state == HIGH) {
    cnt++;
    if (cnt == 5) {
      cnt = 0;
    }
  }
  arr_int[cnt] = peremeniirizistor_state;
  for (int i = 0; i < 5; i++) {
    Serial.println(arr_int[i]);
    if (i == 4) {
      Serial.println("____________");
    }
  }
}