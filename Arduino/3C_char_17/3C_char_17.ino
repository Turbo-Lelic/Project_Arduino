char arr[6][3] = {
  {'1', ' ', 'Q'},
  {'2', ' ', 'A'},
  {'3', ' ', 'Z'},
  {'4', ' ', 'R'},
  {'5', ' ', 'F'},
  {'6', ' ', 'V'},
};
int peremeniirizistor = A0;

void setup() {
  Serial.begin(9600);
  pinMode(peremeniirizistor, INPUT);
}
void loop() {
  int peremeniirizistor_state = analogRead(peremeniirizistor);

  if (peremeniirizistor_state >= 0 && peremeniirizistor_state <= 100) {
    for (int i = 0; i < 3; i++) {
      Serial.print(arr[0][i]);
    }
    Serial.println();
  }
  if (peremeniirizistor_state >= 101 && peremeniirizistor_state <= 200) {
    for (int i = 0; i < 3; i++) {
      Serial.print(arr[1][i]);
    }
    Serial.println();
  }
  if (peremeniirizistor_state >= 201 && peremeniirizistor_state <= 300) {
    for (int i = 0; i < 3; i++) {
      Serial.print(arr[2][i]);
    }
    Serial.println();
  }
  if (peremeniirizistor_state >= 301 && peremeniirizistor_state <= 400) {
    for (int i = 0; i < 3; i++) {
      Serial.print(arr[3][i]);
    }
    Serial.println();
  }
  if (peremeniirizistor_state >= 401 && peremeniirizistor_state <= 500) {
    for (int i = 0; i < 3; i++) {
      Serial.print(arr[4][i]);
    }
    Serial.println();
  }
  if (peremeniirizistor_state >= 501 && peremeniirizistor_state <= 600) {
    for (int i = 0; i < 3; i++) {
      Serial.print(arr[5][i]);
    }
    Serial.println();
  }
}