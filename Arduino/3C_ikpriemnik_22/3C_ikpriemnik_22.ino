#include <IRremote.h>
IRrecv irrecv(A1);
decode_results results;

int ledpin_1 = 7, ledpin_2 = 8, ledpin_3 = 9, cnt = 0;
int arr[3][2] {
  {7, 0},
  {8, 0},
  {9, 0},
};
int arr_output[3] = {ledpin_1, ledpin_2, ledpin_3};

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

  for (int i = 0; i < 3; i++) {
    pinMode(arr_output[i], OUTPUT);
  } 
  pinMode(A1, INPUT);
}
void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == FF6897) {
      cnt++;
      if (cnt == 3) {
        cnt = 0;
      }
    }
    if (results.value == FF9867) {
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
    irrecv.resume();
  }

  analogWrite(arr_output[0], arr[0][1]), delay(50);
  analogWrite(arr_output[1], arr[1][1]), delay(50);
  analogWrite(arr_output[2], arr[2][1]), delay(50);
}