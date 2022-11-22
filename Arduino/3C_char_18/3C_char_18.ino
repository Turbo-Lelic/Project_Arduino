char arr[6][3] = {
  {'1', ' ', 'Z'},
  {'2', ' ', 'X'},
  {'3', ' ', 'C'},
  {'4', ' ', 'V'},
  {'5', ' ', 'B'},
  {'6', ' ', 'N'},
};
int arr_pin[2] = {A0, A1};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 2; i++) {
    pinMode(arr_pin[i], INPUT);
  }
}
void loop() {
  int x_state = analogRead(arr_pin[0]), y_state = analogRead(arr_pin[1]);

  if (x_state >= 0 && x_state <= 100 && y_state == 512) { func_cout(0); }
  if (x_state >= 101 && x_state <= 200 && y_state == 512) { func_cout(1); }
  if (x_state >= 201 && x_state <= 300 && y_state == 512) { func_cout(2); }
  if (x_state >= 301 && x_state <= 400 && y_state == 512) { func_cout(3); }
  if (x_state >= 401 && x_state <= 500 && y_state == 512) { func_cout(4); }
  if (x_state >= 501 && x_state <= 600 && y_state == 512) { func_cout(5); }
}
void func_cout(int n) {
  for (int i = 0; i < 3; i++) {
    Serial.print(arr[n][i]);
  }
  Serial.println();
}