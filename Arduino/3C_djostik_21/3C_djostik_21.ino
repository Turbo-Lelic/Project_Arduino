int ledpin_1 = 7, ledpin_2 = 8, ledpin_3 = 9, cnt = 0;
int arr[3][2] = {
  {7, 0},
  {8, 0},
  {9, 0},
};
int arr_output[3] = {ledpin_1, ledpin_2, ledpin_3};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(arr_output[i], OUTPUT);
  }
  pinMode(A0, INPUT), pinMode(A1, INPUT);
}
void loop() {
  int x = analogRead(A0), y = analogRead(A1);

  if (x >= 0 && x <= 1023 && y == 512) {
    cnt++;
    if (cnt == 3) {
      cnt = 0;
    }
  }
  if (y >= 0 && y <= 1023 && x == 512) {
    if (cnt == 0) {
      arr[0][1] += 50;
      if (arr[0][1] == 250) {
        arr[0][1] = 0;
      }
    } else if (cnt == 1) {
        arr[1][1] += 50;
        if (arr[1][1] == 250) {
          arr[1][1] = 0;
        }
    } else if (cnt == 2) {
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