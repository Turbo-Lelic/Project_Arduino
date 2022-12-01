int btn_1 = 5, btn_2 = 6, ledpin_1 = 7, ledpin_2 = 8, ledpin_3 = 9, cnt_choice = 0;
int arr[3][2] = {
  {7, 0},
  {8, 0},
  {9, 0},
};
int arr_output[3] = {ledpin_1, ledpin_2, ledpin_3}, arr_input[2] = {btn_1, btn_2};

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 3; i++) {
    pinMode(arr_output[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(arr_input[i], INPUT);
  }
}
void loop() {
  int btn_1_state = digitalRead(arr_input[0]), btn_2_state = digitalRead(arr_input[1]);
  
  if (btn_1_state == LOW) {
    cnt_choice++;
    if (cnt_choice == 3) {
      cnt_choice = 0;
    }
  }
  if (btn_2_state == LOW) {
    if (cnt_choice == 0) {
      arr[0][1] += 50;
      if (arr[0][1] == 250) {
        arr[0][1] = 0;
      }
    } else if (cnt_choice == 1) {
        arr[1][1] += 50;
        if (arr[1][1] == 250) {
          arr[1][1] = 0;
        }
    } else if (cnt_choice == 2) {
        arr[2][1] += 50;
        if (arr[2][1] == 250) {
          arr[2][1] = 0;
        }
    }
  }

  analogWrite(arr_output[0], arr[0][1]), delay(50);
  analogWrite(arr_output[1], arr[1][1]), delay(50);
  analogWrite(arr_output[2], arr[2][1]), delay(50);
}