#include <IRremote.h>
IRrecv ir(8);
decode_results results;
char arr[6][3] = {
  {'1', ' ', 'Q'};
  {'2', ' ', 'W'};
  {'3', ' ', 'E'};
  {'4', ' ', 'A'};
  {'5', ' ', 'S'};
  {'6', ' ', 'D'};
};

void setup() {
  Serial.begin(9600);
  ir.enableIRIn();
}
void loop() {
  if (ir.decode(&results)) {
    if (results.value == FF6897) {
      for (int i = 0; i < 3; i++) {
        Serial.print(arr[0][i]);
      }
      Serial.println();
    }
    if (results.value == FF9867) {
      for (int i = 0; i < 3; i++) {
        Serial.print(arr[1][i]);
      }
      Serial.println();
    }
    if (results.value == FFB04F) {
      for (int i = 0; i < 3; i++) {
        Serial.print(arr[2][i]);
      }
      Serial.println();
    }
    if (results.value == FF30C7) {
      for (int i = 0; i < 3; i++) {
        Serial.print(arr[3][i]);
      }
      Serial.println();
    }
    if (results.value == FF18E7) {
      for (int i = 0; i < 3; i++) {
        Serial.print(arr[4][i]);
      }
      Serial.println();
    }
    if (results.value == FF7A85) {
      for (int i = 0; i < 3; i++) {
        Serial.print(arr[5][i]);
      }
      Serial.println();
    }

    ir.resume();
  }
}