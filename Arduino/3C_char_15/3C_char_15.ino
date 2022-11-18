char arr[3][7] = {
  {'1', ' ', 'h', 'e', 'l', 'l', 'o'},
  {'2', ' ', 'g', 'g', ' ', 'w', 'p'},
  {'3', ' ', 'g', 'o', 'o', 'd', '!'},
};
void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 7; j++) {
      if (j == 0) {
        Serial.println();
      }
      Serial.print(arr[i][j]);
    }
  }
}
void loop() {}