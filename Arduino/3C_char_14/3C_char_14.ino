char arr[6][2] = {
  {'a', '1'},
  {'b', '2'},
  {'c', '3'},
  {'d', '4'},
  {'e', '5'},
  {'f', '6'},
};
int btn = 2, cnt = 0;

void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT);
}

void loop() {
  int btn_state = digitalRead(btn);
  if (btn_state == LOW) {
    cnt++;
    if (cnt == 2) {
      cnt = 0;
    }
  }
  if (cnt == 0) {
    for (int i = 0; i < 6; i++) {
      Serial.print(arr[i][0]);
      if (i == 5) {
        Serial.println();
        delay(3000);
      }
    }
  }
  if (cnt == 1) {
    for (int i = 0; i < 6; i++) {
      Serial.print(arr[i][1]);
      if (i == 5) {
        Serial.println();
        delay(3000);
      }
    }
  }
}