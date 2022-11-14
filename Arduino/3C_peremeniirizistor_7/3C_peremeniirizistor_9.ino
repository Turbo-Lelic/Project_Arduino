int btn = 2, bool_cnt = 0, cnt_1 = 0, cnt_2 = 0;
int arr[2] = {btn, A0};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 2; i++) {
    pinMode(arr[i], INPUT);
  }
}
void loop() {
  int peremeniirizistor_state = analogRead(A0), btn_state = digitalRead(btn);
  Serial.println("cnt_1 = " + (String)cnt_1);
  Serial.println("cnt_2 = " + (String)cnt_2);

  if (btn_state == LOW) {
    if (cnt_bool == 0) {
      cnt_bool++;
    } else if (cnt_bool == 1) {
      cnt_bool--;
    }
  }

  if (cnt_bool == 0) {
    cnt_1 = peremeniirizistor_state;
  }
  if (cnt_bool == 1) {
    cnt_2 = peremeniirizistor_state;
  }
}