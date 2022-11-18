char arr[6][6] = {
  {'1', ' ', 'o', 'o', 'o'},
  {'2', ' ', '-', '_', '-'},
  {'3', ' ', 'O', '_', 'O'},
  {'4', ' ', 'O', 'o', 'O'},
  {'5', ' ', 'g', 'g', '!'},
  {'6', ' ', 'C', '+', '+'},
};
int btn_1 = 2, btn_2 = 3, cnt = 0;
int arr_input[2] = {btn_1, btn_2};

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 2; i++) {
    pinMode(arr_input[i], INPUT);
  }
}
void loop() {
  int btn_1_state = digitalRead(btn_1), btn_2_state = digitalRead(btn_2);

  if (btn_1_state == LOW) {
    cnt++;
    if (cnt == 6) {
      cnt = 0;
    }
  }
  if (btn_2_state == LOW) {
    for (int i = 0; i < 5; i++) {
      Serial.print(arr[cnt][i]);
    }
    Serial.println();
    delay(1000);
  }
}